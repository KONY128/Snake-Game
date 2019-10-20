#pragma once
#include <QTime>
#include "SourceCode/SnakeGame/SnakeList.h"
#include "SourceCode/SnakeGame/SnakeSettings.h"

class SnakeWall : public SnakeList
{
    /*
    //私有数据成员
private:
    SnakeList wall;
    */

    //公有成员函数
public:
    //构造函数
    SnakeWall();

    //根据初始地图设置来创建墙壁
    void iniWall();

    //在某个位置创建一个墙
    void createWall(int const &ROW, int const &COL);

    //检查某个位置是否有墙存在
    SnakeNode *exist(int const &ROW, int const &COL) const;

    //摧毁某个位置的墙
    void destroyWall(int const &ROW, int const &COL);

    //把墙壁清空
    void clearWall();
};
