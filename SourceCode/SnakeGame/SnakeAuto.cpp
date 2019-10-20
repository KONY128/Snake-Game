#include "SnakeAuto.h"

void SnakeAuto::AutoJudge(SnakePlayer *autoPlayer, SnakeFood *FOOD, SnakeWall *WALL)
{

    /*
     * 只在PlayerInput非空时插入输入栈
     * 如果可以吃到食物，直接去吃
     *     吃不到，找尾巴，找得到就追
     *          连尾巴都找不到，随便走走
     */


    //debug：Harsh Terrian生存策略，新生成的砖块在眼前时，重新计算路径
    int nextRow = autoPlayer->getHead()->next->row;
    int nextCol = autoPlayer->getHead()->next->column;
    autoPlayer->nextPos(nextRow, nextCol);
    if (WALL->exist(nextRow, nextCol))
        autoPlayer->playerInput.clear();

    //输入栈非空时则按照输入栈操作
    if (autoPlayer->playerInput.isEmpty() == false)
        return;

    //已debug：药水存在时优先吃药水，不吃屎
    int foodCol = FOOD->getHead()->next->column, foodRow = FOOD->getHead()->next->row;
    SnakeNode *node = FOOD->getHead()->next;
    if (FOOD->getNumOfPotion() > 0){
        while (node != FOOD->getTail()){
            if (static_cast <int> (node->nodeType) >= 7){
                node->getPos(foodRow, foodCol);
                break;
            }
            node = node->next;
        }
    }
    else{
        while (node != FOOD->getTail()){
            if (node->nodeType != SnakeNode::trash){
                node->getPos(foodRow, foodCol);
                break;
            }
            node = node->next;
        }
    }
    SnakeEmpty::Point foodP(foodRow, foodCol);
    SnakeEmpty::Point tailP(autoPlayer->getTail()->prev->row, autoPlayer->getTail()->prev->column);
    QQueue<SnakePlayer::Destination> path;

    //核心代码，先找食物
    if (findWayTo(autoPlayer, foodP, path, false)){
        autoPlayer->playerInput << path;
        return;
    }
    //已经找不到食物了，找尾巴，没找到就wander一步
    else if (findWayTo(autoPlayer, tailP, path, true)){
        autoPlayer->playerInput << path;
        return;
    }
}

bool SnakeAuto::findWayTo(SnakePlayer *autoPlayer, const SnakeEmpty::Point &Destination, QQueue<SnakePlayer::Destination> &Path, bool wanderFlag)
{
    //从蛇头开始BFS，并进行初始化工作
    SnakeEmpty::Point SnakeHere(autoPlayer->getHead()->next->row, autoPlayer->getHead()->next->column);
    QLinkedList<SnakeEmpty::Point> backUp;      //用于备份从SnakeEmpty中删掉的结点
    QLinkedList<SnakeEmpty::Point> pointsLeft;  //剩下的要处理的结点
    QLinkedList<SnakeEmpty::Point> pathP;       //存入Path，只不过先用类Point存，最后转换成用户输入Path
    pointsLeft.append(SnakeHere);
    //BFS找路，结果存入pathP中，注意其第0个元素为蛇头位置，最后一个元素为目的地
    while(pointsLeft.isEmpty() == false)
    {
        //取出当前处理结点，同时pathP栈中存入路径(继续走老路) / 删除已有路径(遇到了墙，回退)
        SnakeHere = pointsLeft.takeLast();
        if (pathP.isEmpty())
            pathP.append(SnakeHere);
        else if (getDistance(pathP.last(), SnakeHere) == 1) //当前处理的结点离之前的很近，说明在继续走老路
            pathP.append(SnakeHere);
        else{
            while(getDistance(pathP.last(), SnakeHere) != 1) //不走老路，找到这个结点分叉的位置
                pathP.pop_back();
            pathP.append(SnakeHere);
        }
        //将当前所处理结点的上下左右位置确定
        SnakeEmpty::Point SnakeUp((SnakeSettings::maxRow +  SnakeHere.row - 1) % SnakeSettings::maxRow, SnakeHere.col);
        SnakeEmpty::Point SnakeDown((SnakeHere.row + 1) % SnakeSettings::maxRow, SnakeHere.col);
        SnakeEmpty::Point SnakeLeft(SnakeHere.row, (SnakeSettings::maxCol + SnakeHere.col - 1) % SnakeSettings::maxCol);
        SnakeEmpty::Point SnakeRight(SnakeHere.row, (SnakeHere.col + 1) % SnakeSettings::maxCol);
        //看看有没有到Destination，将其加入栈中
        if (SnakeUp == Destination){
            pathP << SnakeUp;
            break;
        }
        if (SnakeDown == Destination){
            pathP << SnakeDown;
            break;
        }
        if (SnakeLeft == Destination){
            pathP << SnakeLeft;
            break;
        }
        if (SnakeRight == Destination){
            pathP << SnakeRight;
            break;
        }
        //若没有到Destination，将SnakeEmpty里的曼哈顿距离最大的点先进栈(后于最小的点最先处理)
        //注意，进栈则意味着从SnakeEmpty中删除，并保存入backUp中
        //先算出上下左右距离目标点的曼哈顿距离，将它们进行排序
        int disUp = getDistance(SnakeUp, Destination), disDown = getDistance(SnakeDown, Destination),
                disLeft = getDistance(SnakeLeft, Destination), disRight = getDistance(SnakeRight, Destination);
        QList<int> sortList;
        sortList << disUp << disDown << disLeft << disRight;
        qSort(sortList);
        //根据排序顺序，将曼哈顿距离最大的先进栈(最小的点最先处理),同时把SnakeEmpty中的删掉，备份进backup中，
        for (int i = 3; i >= 0; --i){
            if (sortList[i] == disUp && SnakeEmpty::emptyList.contains(SnakeUp)){
                pointsLeft.append(SnakeUp);
                SnakeEmpty::emptyList.removeAll(SnakeUp);
                backUp.append(SnakeUp);
            }
            if (sortList[i] == disDown && SnakeEmpty::emptyList.contains(SnakeDown)){
                pointsLeft.append(SnakeDown);
                SnakeEmpty::emptyList.removeAll(SnakeDown);
                backUp.append(SnakeDown);
            }
            if (sortList[i] == disLeft && SnakeEmpty::emptyList.contains(SnakeLeft)){
                pointsLeft.append(SnakeLeft);
                SnakeEmpty::emptyList.removeAll(SnakeLeft);
                backUp.append(SnakeLeft);
            }
            if (sortList[i] == disRight && SnakeEmpty::emptyList.contains(SnakeRight)){
                pointsLeft.append(SnakeRight);
                SnakeEmpty::emptyList.removeAll(SnakeRight);
                backUp.append(SnakeRight);
            }
        }
    }
    //处理结束，欢迎SnakeEmpty，先检查能不能找到目的地，若能找到则将pathP转换为用户输入Path
    //注意pathP第零个元素是蛇头的位置，若最后一个元素是Destination，说明找到了，若不是Destination则没找到
    while(backUp.isEmpty() != true)
        SnakeEmpty::emptyList.append(backUp.takeFirst());
    if (pathP.last() == Destination || wanderFlag){ //找到了Destination的通路
        SnakeEmpty::Point p1(0,0), p2(0,0); //p1,p2用来考量到底是往path里插哪个方向
        p2 = pathP.takeFirst();
        while(pathP.isEmpty() != true){
            p1 = p2;
            p2 = pathP.takeFirst();
            if (p2.row < p1.row)
                Path.enqueue(SnakePlayer::up);
            else if (p2.row > p1.row)
                Path.enqueue(SnakePlayer::down);
            else if (p2.col < p1.col)
                Path.enqueue(SnakePlayer::left);
            else if (p2.col > p1.col)
                Path.enqueue(SnakePlayer::right);
            else
                qDebug() << "Path Not Linking";
            //注意，若没找到，则进行wander，wander只走一步
            if (pathP.isEmpty() != true && !(pathP.last() == Destination))
                break;
        }
        return true;
    }
    else //没有找到通路
        return false;
}

int SnakeAuto::getDistance(const SnakeEmpty::Point &A, const SnakeEmpty::Point &B)
{
    return qAbs(A.col - B.col) + qAbs(A.row - B.row);
}

