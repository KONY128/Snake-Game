#ifndef SNAKEAUTO_H
#define SNAKEAUTO_H
#include "SourceCode/SnakeGame/SnakeFood.h"
#include "SourceCode/SnakeGame/SnakePlayer.h"
#include "SourceCode/SnakeGame/SnakeWall.h"
#include "SourceCode/SnakeGame/SnakeEmpty.h"
#include "SourceCode/SnakeGame/SnakeSettings.h"
#include <QList>
#include <QtDebug>

class SnakeAuto
{
public:

    //自动判断蛇应该往哪走，向用户输入栈中添加输入
    //已Debug：蛇应该优先吃药水才对
    //已Debug：Harsh Terrian开启时的生存策略
    static void AutoJudge(SnakePlayer *autoPlayer, SnakeFood *FOOD, SnakeWall *WALL);

private:

    //查找当前SnakeEmpty有没有路径通向某个地址，若wanderFlag为真，则返回一个wander策略(离最远的方向)
    static bool findWayTo(SnakePlayer *autoPlayer, const SnakeEmpty::Point &Destination, QQueue<SnakePlayer::Destination> &Path, bool wanderFlag); //走一步？还是走很多步？

    //取得两点间曼哈顿距离
    //有bug！如果没有墙怎么办!
    static int getDistance(const SnakeEmpty::Point &A, const SnakeEmpty::Point &B);
};

#endif // SNAKEAUTO_H
