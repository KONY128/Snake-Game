#include "SourceCode/SnakeGame/SnakeWall.h"

//构造函数
SnakeWall::SnakeWall()
{
    iniWall();
}

//根据初始地图设置来创建墙壁
void SnakeWall::iniWall()
{
    switch (SnakeSettings::wallSet)
    {
    case SnakeSettings::none:
        for (int i = 0; i < SnakeSettings::maxRow; ++i)
        {
            createWall(i, 0);
            createWall(i, SnakeSettings::maxCol - 1);
        }
        for (int j = 0; j < SnakeSettings::maxCol; ++j)
        {
            createWall(0, j);
            createWall(SnakeSettings::maxRow - 1, j);
        }
        break;
    case SnakeSettings::left_right:
        for (int j = 0; j < SnakeSettings::maxCol; ++j)
        {
            createWall(0, j);
            createWall(SnakeSettings::maxRow - 1, j);
        }
        break;
    case SnakeSettings::up_down:
        for (int i = 0; i < SnakeSettings::maxRow; ++i)
        {
            createWall(i, 0);
            createWall(i, SnakeSettings::maxCol - 1);
        }
        break;
    case SnakeSettings::all:
        break;
    }

    //如果开了复杂地形，则初始随机增加三个地块
    //debug:三个地块不出现在蛇出生的下一个位置
    if (SnakeSettings::harshTerrain == true)
    {
        int wallRow, wallCol, wallLocationIdx;
        bool noBug = false;
        for (int i = 3; i > 0; i--)
        {
            while (noBug == false)
            {
                qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
                wallLocationIdx = qrand() % SnakeEmpty::emptyList.count();
                SnakeEmpty::Point pointTmp = SnakeEmpty::get(wallLocationIdx);
                wallRow = pointTmp.row;
                wallCol = pointTmp.col;
                noBug = true;
                switch (SnakeSettings::playerNum) {
                case SnakeSettings::triplePlayer:  if (7 == wallRow && 4 == wallCol) noBug = false; [[clang::fallthrough]];
                case SnakeSettings::doublePlayer:  if (5 == wallRow && 4 == wallCol) noBug = false; [[clang::fallthrough]];
                case SnakeSettings::singlePlayer:
                case SnakeSettings::autoPlay:      if (3 == wallRow && 4 == wallCol) noBug = false;
                }
            }
            createWall(wallRow, wallCol);
            noBug = false;
        }
    }
}

//在某个位置创建一个墙
void SnakeWall::createWall(int const &ROW, int const &COL)
{
    if (ROW >= SnakeSettings::maxRow || COL >= SnakeSettings::maxCol || ROW < 0 || COL < 0)
        throw "Error. Creating a Wall out of map.";
    if (exist(ROW, COL))
        return;
    insert(ROW, COL);
}

//检查某个位置是否有墙存在
SnakeNode *SnakeWall::exist(int const &ROW, int const &COL) const
{
    if (ROW >= SnakeSettings::maxRow || COL >= SnakeSettings::maxCol || ROW < 0 || COL < 0)
        return nullptr;
    return SnakeList::exist(ROW, COL);
}

//摧毁某个位置的墙
void SnakeWall::destroyWall(int const &ROW, int const &COL)
{
    if (ROW >= SnakeSettings::maxRow || COL >= SnakeSettings::maxCol || ROW < 0 || COL < 0)
        return;
    if (exist(ROW, COL))
        SnakeList::deleteNode(ROW, COL);
}

//把墙壁清空
void SnakeWall::clearWall()
{
    SnakeList::clear();
}
