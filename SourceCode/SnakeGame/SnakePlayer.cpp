#include "SourceCode/SnakeGame/SnakePlayer.h"

bool SnakePlayer::growFlag = false;
int SnakePlayer::numOfAlivePlayers = 0;

SnakePlayer::SnakePlayer()
{
    score = 0;
    //初始化蛇的设置
    //蛇的初始位置从地图坐标（3，3）开始，默认向右走
    iniPlayer(3, 3, right);
    aliveFlag = true;
    newInputFlag = false;
    growFlag = false;
    doubleGainCounter = 0;
    ++numOfAlivePlayers;
}

SnakePlayer::~SnakePlayer()
{
    if (aliveFlag == true)
        --numOfAlivePlayers;
}

void SnakePlayer::iniPlayer(const int &ROW, const int &COL, const SnakePlayer::Destination &DES)
{
    SnakeList::clear();
    playerInput.clear();
    SnakeList::insert(ROW, COL);
    desLast = DES;
}

//根据贪吃蛇走向，求得贪吃蛇移动的下一个位置
SnakePlayer::Destination SnakePlayer::nextPos(int &nextRow, int &nextCol)
{
    if (aliveFlag == true)
    {
        SnakeList::head->next->getPos(nextRow, nextCol);
        Destination desTmp;
        //用户没有输入，蛇默认向前走
        if (playerInput.isEmpty() == true)
            desTmp = desLast;
        else
            desTmp = playerInput.head();
        switch (desTmp)
        {
        case up:
            nextRow = (nextRow - 1 + SnakeSettings::maxRow) % SnakeSettings::maxRow;
            break;
        case down:
            nextRow = (nextRow + 1) % SnakeSettings::maxRow;
            break;
        case left:
            nextCol = (nextCol - 1 + SnakeSettings::maxCol) % SnakeSettings::maxCol;
            break;
        case right:
            nextCol = (nextCol + 1) % SnakeSettings::maxCol;
            break;
        };
        return desTmp;
    }
    else
    {
        nextRow = -1;
        nextCol = -1;
        return left;
    }

}

//设置蛇的下一个移动位置，并防止蛇倒着走
void SnakePlayer::setDestination(SnakePlayer::Destination const &DES)
{
    if (aliveFlag == true)
    {
        //若为新周期的输入，清空用户输入栈
        if (newInputFlag == true)
        {
            playerInput.clear();
            newInputFlag = false;
        }
        //desLast的作用是防止蛇倒着走
        if (SnakeList::getLength() != 1)
        {
            Destination desTmp;
            if (playerInput.isEmpty() == true)
                desTmp = desLast;
            else
                desTmp = playerInput.last();
            switch (desTmp)
            {
            case up:
                if (DES == down)
                    return;
                break;
            case down:
                if (DES == up)
                    return;
                break;
            case left:
                if (DES == right)
                    return;
                break;
            case right:
                if (DES == left)
                    return;
                break;
            }
        }
        playerInput.enqueue(DES);
    }
}

//模拟蛇变长，表头增加一个结点
void SnakePlayer::snakeGrow()
{
    if (aliveFlag == true)
    {
        int nextRow, nextCol;
        Destination desTmp = nextPos(nextRow, nextCol);
        if(playerInput.isEmpty() == false)
            playerInput.dequeue();
        desLast = desTmp;
        SnakeList::insert(nextRow, nextCol);
    }
}

//模拟蛇移动，在表尾删除一个结点，表头根据蛇的走向(To变量)来插入一个结点
void SnakePlayer::snakeMove()
{
    if (aliveFlag == true)
    {
        snakeGrow();
        SnakeList::remove();
    }
}

//查看该位置是否撞到了蛇的身体，撞到则返回true
bool SnakePlayer::isHitBody(const int &nextRow, const int &nextCol)
{
    if (aliveFlag == true && SnakeList::getLength() != 1)
    {
        int curRow, curCol;
        //注意是搜索蛇身，从蛇头往后的第一个结点开始搜索
        SnakeNode *curNode = SnakeList::getHead()->next->next;
        //不要和蛇尾比较，蛇咬不到蛇尾
        while(curNode != SnakeList::getTail()->prev)
        {
            curNode->getPos(curRow, curCol);
            if (curRow == nextRow && curCol == nextCol)
                return true;
            curNode = curNode->next;
        }
    }
    return false;
}

//模拟蛇咬到自己，搜索链表，若蛇头的下一个位置将到达蛇身所在（debug：蛇尾除外），返回1
bool SnakePlayer::isSelfEating()
{
    if (aliveFlag == true && SnakeList::getLength() != 1)
    {
        int nextRow, nextCol;
        nextPos(nextRow, nextCol);
        return isHitBody(nextRow, nextCol);
    }
    return 0;
}

//快速渲染，慢速缩短，展现蛇的动态缩短效果#￥@#@#%@￥%#￥%@#￥%@#%
//模拟蛇缩短一半
void SnakePlayer::snakeHalving()
{
    if (aliveFlag == true)
    {
        int half = (SnakeList::getLength() + 1) / 2;
        while (SnakeList::getLength() > half)
            SnakeList::remove();
    }
}

//快速渲染，慢速缩短，展现蛇的动态缩短效果#￥@#@#%@￥%#￥%@#￥%@#%
//模拟蛇返老还童，只剩下一个初始节点
void SnakePlayer::snakeRebirth()
{
    if (aliveFlag == true)
    {
        while (SnakeList::getLength() > 1)
            SnakeList::remove();
    }
}

//返回玩家当前积分
int SnakePlayer::getScore() const
{
    return score;
}

//模拟玩家积分增长
void SnakePlayer::gainScore(int const &GAIN)
{
    if (aliveFlag == true)
    {
        score += GAIN;
        if (doubleGainCounter > 0)
        {
            score += GAIN;
            --doubleGainCounter;
        }
    }
}

//模拟吃到双倍收入药水
void SnakePlayer::doubleGain()
{
    doubleGainCounter = 5;
}

//改变成长标志
void SnakePlayer::setGrowFlag(const bool &GF)
{
    growFlag = GF;
}

//取得growFlag的值
bool SnakePlayer::getGrowFlag()
{
    return growFlag;
}

//取得newInputFlag的值
bool SnakePlayer::getNewInputFlag() const
{
    return newInputFlag;
}

//改变newInputFlag的值
void SnakePlayer::setNewInputFlag(const bool &NIF)
{
    newInputFlag = NIF;
}

//改变aliveFlag的值
void SnakePlayer::setAliveFlag(const bool &AF)
{
    //确认死亡
    if (AF == false && aliveFlag == true)
    {
        this->clear();
        --numOfAlivePlayers;
    }
    //死而复生
    if (AF == true && aliveFlag == false)
    {
        iniPlayer(3, 3, left);
        ++numOfAlivePlayers;
    }
    aliveFlag = AF;
}

//取得aliveFlag的值
bool SnakePlayer::isAlive()
{
    return  aliveFlag;
}

//取得当前存活玩家数
int SnakePlayer::getNumOfAlivePlayers()
{
    return numOfAlivePlayers;
}
