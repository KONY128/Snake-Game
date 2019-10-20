#ifndef SNAKERENDERER_H
#define SNAKERENDERER_H

#include <QWidget>
#include <QtGui>
#include <QPushButton>  //QT按钮类
#include <QVBoxLayout>  //垂直布局器
#include <QKeyEvent>    //键盘输入事件
#include <QtGlobal>     //用于生成随机数
#include <QColor>
#include <QImage>
#include "SourceCode/SnakeGame/SnakeSound.h"
#include "SourceCode/SnakeGame/SnakeFood.h"
#include "SourceCode/SnakeGame/SnakePlayer.h"
#include "SourceCode/SnakeGame/SnakeWall.h"
#include "SourceCode/SnakeGame/SnakeJudge.h"
#include "SourceCode/SnakeGame/SnakeAuto.h"

class SnakeRenderer : public QWidget
{
    Q_OBJECT
public:
    //构造&析构函数
    explicit SnakeRenderer(QWidget *parent = nullptr);

    ~SnakeRenderer() override;

    //启动游戏
    void startGame();

    //结束游戏了
    void endGame();

    //强行退出游戏（不保存）
    void exitGame();

signals:
    //游戏结束时给mainWindow发射的信号
    void gameOver();

    //保存游戏结束过后的赢家信息
    void saveGameData(int Score, int PlayerId);

protected:      //事件函数
    void timerEvent(QTimerEvent *event) override;

    void keyPressEvent(QKeyEvent *event)override;

    void paintEvent(QPaintEvent *event) override;

    //切入窗口，游戏进行，切出窗口，游戏暂停
    void focusInEvent (QFocusEvent *event ) override;

    void focusOutEvent (QFocusEvent *event) override;


private:         //私有成员变量
    //游戏刷新时间
    int m_timerId;
    //游戏组成部件
    SnakeWall *walls;
    SnakeFood *foods;
    SnakePlayer *player1;
    SnakePlayer *player2;
    SnakePlayer *player3;
    //判断游戏是否结束、开始，是否是自动游戏模式
    bool gameFlag;          //为真则游戏开始，为假则游戏未开始
    bool focusFlag;         //窗口在后台(失去focus)时游戏不进行
    bool gameOverFlashFlag;
    bool newInput_player1;
    bool newInput_player2;
    bool newInput_player3;

private:
    //私有成员函数

    //初始化游戏内容
    void iniGame();

    //清除游戏内容
    void clearGame();
};

#endif // SNAKERENDERER_H
