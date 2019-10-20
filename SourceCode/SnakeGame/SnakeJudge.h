#ifndef SNAKEJUDGE_H
#define SNAKEJUDGE_H

#include <QWidget>
#include <QtGui>
#include <QtGlobal> //用于生成随机数
#include <QTime>

#include "SourceCode/SnakeGame/SnakeSound.h"
#include "SourceCode/SnakeGame/SnakeFood.h"
#include "SourceCode/SnakeGame/SnakePlayer.h"
#include "SourceCode/SnakeGame/SnakeWall.h"
#include "SourceCode/SnakeGame/SnakeEmpty.h"

class SnakeJudge
{
public:

    //判断该蛇下一个位置有没有撞墙，撞墙则返回true
    static bool hitWall(SnakePlayer *PLAYER, SnakeWall *WALL);

    //判断该蛇下一个位置有没有撞到自己或者其他蛇
    static bool hitSnake(SnakePlayer *PLAYER_A, SnakePlayer *PLAYER_B = nullptr, SnakePlayer *PLAYER_C = nullptr);

    //判断该蛇有没有吃到食物，吃到则进行相关操作，没吃到则正常前进
    static bool eatFood(SnakePlayer *PLAYER, SnakeFood *FOOD);

    //根据SnakeSettings更新食物信息
    static void updateFood(SnakeFood *FOOD);

    //根据SnakeSettings更新墙壁信息
    static void updateWall(SnakeWall *WALL, SnakePlayer *PLAYER_A, SnakePlayer *PLAYER_B = nullptr, SnakePlayer *PLAYER_C = nullptr);

    //输入游戏信息，进行游戏判断，若游戏在此过程中结束(蛇都死完了)，则返回false
    static bool judge(SnakeFood *FOOD, SnakeWall *WALL, SnakePlayer *PLAYER_A, SnakePlayer *PLAYER_B = nullptr, SnakePlayer *PLAYER_C = nullptr);

private:

    static QMediaPlayer *player;
};

#endif // SNAKEJUDGE_H
