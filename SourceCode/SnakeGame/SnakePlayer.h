#pragma once
#include <QQueue>
#include "SourceCode/SnakeGame/SnakeList.h"
#include "SourceCode/SnakeGame/SnakeSettings.h"
using namespace std;

class SnakePlayer : public SnakeList
{
public: //公有数据类型
    //保存用户输入的蛇的走向，控制蛇的前进后退、左转右转
    enum Destination
    {
        up,     //0   向上
        down,   //1   向下
        left,   //2   向左
        right   //3   向右
    };
    QQueue<Destination> playerInput;    //玩家输入的队列

private:                                //私有数据成员
    int aliveFlag;                      //判定玩家是否存活
    int score;                          //玩家积分
    Destination desLast;                //lastDes为上一步移动的走向，防止蛇倒退
    bool newInputFlag;                  //判断这一渲染周期内是否有新的用户输入
    int doubleGainCounter;              //双倍收入计数器
    static bool growFlag;               //成长药水计数器
    static int numOfAlivePlayers;       //计算存活的玩家总数

public: //公有成员函数

    //构造函数&析构函数
    SnakePlayer();

    ~SnakePlayer();

    //设置蛇的初始位置和移动方向
    void iniPlayer(const int &ROW, const int &COL, const Destination &DES);

    //接受玩家输入，若让蛇倒着走，则停止接受输入
    void setDestination(Destination const &DES);

    //根据贪吃蛇走向，求得贪吃蛇移动的下一个位置
    Destination nextPos(int &nextRow, int &nextCol);

    //模拟蛇变长，表头增加一个结点
    void snakeGrow();

    //模拟蛇移动，在表尾删除一个结点，表头根据蛇的走向(To变量)来插入一个结点
    void snakeMove();

    //查看该位置是否撞到了蛇的身体，撞到则返回true
    bool isHitBody(const int &nextRow, const int &nextCol);

    //模拟蛇咬到自己，搜索链表，若蛇头的下一个位置将到达蛇身所在（debug：蛇尾除外），返回1
    bool isSelfEating();

    //模拟蛇缩短一半
    void snakeHalving();

    //模拟蛇返老还童，只剩下一个初始节点
    void snakeRebirth();

    //返回玩家当前积分
    int getScore() const;

    //模拟玩家积分增长
    void gainScore(int const &GAIN);

    //模拟吃到双倍收入药水
    void doubleGain();

    //改变成长标志
    static void setGrowFlag(const bool &GF);

    //取得成长标志的值
    static bool getGrowFlag();

    //取得newInputFlag的值
    bool getNewInputFlag() const;

    //改变newInputFlag的值
    void setNewInputFlag(const bool &WDF);

    //改变aliveFlag的值
    void setAliveFlag(const bool &AF);

    //取得aliveFlag的值
    bool isAlive();

    //取得当前存活玩家数
    static int getNumOfAlivePlayers();
};
