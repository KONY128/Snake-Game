#include "SourceCode/SnakeGame/SnakeFood.h"

//在某个位置创建一个食物
SnakeFood::SnakeFood()
{
    numOfFruit   = 0;
    numOfPotion  = 0;
    numOfTrash   = 0;
}

void SnakeFood::createFood(int const &ROW, int const &COL, SnakeNode::Type const &TYPE)
{
    if (exist(ROW, COL))
        return;
    if (ROW >= SnakeSettings::maxRow || COL >= SnakeSettings::maxCol || ROW < 0 || COL < 0)
        throw "Error. Creating a Food out of map.";
    SnakeList::insert(ROW, COL, TYPE);
    switch (TYPE) {
    case SnakeNode::snake_wall :  throw "Error. Creating A Wrong Food.";
    case SnakeNode::apple      :                                        //1   苹果
    case SnakeNode::watermelon :                                        //2   西瓜
    case SnakeNode::straberry  :                                        //3   草莓
    case SnakeNode::pineapple  :  ++numOfFruit; break;                  //4   菠萝
    case SnakeNode::trash      :                                        //5   垃圾
    case SnakeNode::boomb      :  ++numOfTrash; break;                  //6   炸弹
    case SnakeNode::diminution :                                        //7   缩小药水
    case SnakeNode::rebirth    :                                        //8   重生药水
    case SnakeNode::growth     :                                        //9   生长药水
    case SnakeNode::gain       :  ++numOfPotion; break;                 //10  双倍积分
    }
}

//检查某个位置是否有食物存在
SnakeNode *SnakeFood::exist(int const &ROW, int const &COL) const
{
    if (ROW >= SnakeSettings::maxRow || COL >= SnakeSettings::maxCol || ROW < 0 || COL < 0)
        return nullptr;
    return SnakeList::exist(ROW, COL);
}

//返回某个位置的食物类型
SnakeNode::Type SnakeFood::foodType(int const &ROW, int const &COL)
{
    SnakeNode *p = exist(ROW, COL);
    if (p == nullptr)
        return SnakeNode::snake_wall;
    return p->getType();
}

//摧毁某个位置的食物
void SnakeFood::destroyFood(int const &ROW, int const &COL)
{
    if (ROW >= SnakeSettings::maxRow || COL >= SnakeSettings::maxCol || ROW < 0 || COL < 0)
        return;
    if (exist(ROW, COL))
    {
        SnakeNode::Type TYPE = foodType(ROW, COL);
        switch (TYPE) {
        case SnakeNode::snake_wall :  throw "Error. Creating A Wrong Food.";
        case SnakeNode::apple      :                                        //1   苹果
        case SnakeNode::watermelon :                                        //2   西瓜
        case SnakeNode::straberry  :                                        //3   草莓
        case SnakeNode::pineapple  :  --numOfFruit; break;                  //4   菠萝
        case SnakeNode::trash      :                                        //5   垃圾
        case SnakeNode::boomb      :  --numOfTrash; break;                  //6   炸弹
        case SnakeNode::diminution :                                        //7   缩小药水
        case SnakeNode::rebirth    :                                        //8   重生药水
        case SnakeNode::growth     :                                        //9   生长药水
        case SnakeNode::gain       :  --numOfPotion; break;                 //10  双倍积分
        }
        SnakeList::deleteNode(ROW, COL);
    }
}

int SnakeFood::getNumOfFruit()
{
    return numOfFruit;
}

int SnakeFood::getNumOfPotion()
{
    return numOfPotion;
}

int SnakeFood::getNumOfTrash()
{
    return numOfTrash;
}
