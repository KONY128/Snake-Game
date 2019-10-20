#pragma once
#include <iostream>
#include "SourceCode/SnakeGame/SnakeList.h"
#include "SourceCode/SnakeGame/SnakeSettings.h"
#include "SourceCode/SnakeGame/SnakeEmpty.h"
using namespace std;

class SnakeFood : public SnakeList
{
public: //公有成员函数
    SnakeFood();

    //在某个位置创建一个食物
    void createFood(int const &ROW, int const &COL, SnakeNode::Type const &TYPE);

    //检查某个位置是否有食物存在
    SnakeNode *exist(int const &ROW, int const &COL) const;

    //返回某个位置的食物类型,0(snake_wall)为食物不存在
    SnakeNode::Type foodType(int const &ROW, int const &COL);

    //摧毁某个位置的食物
    void destroyFood(int const &ROW, int const &COL);

    int getNumOfFruit();

    int getNumOfPotion();

    int getNumOfTrash();

private: //私有数据成员
    int numOfFruit;
    int numOfPotion;
    int numOfTrash;
};
