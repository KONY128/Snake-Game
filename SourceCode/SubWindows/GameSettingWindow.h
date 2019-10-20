#ifndef GAMESETTINGWINDOW_H
#define GAMESETTINGWINDOW_H

#include <sstream>
#include <string>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QLabel>

#include "SourceCode/SnakeGame/SnakeSound.h"
#include "SourceCode/SnakeGame/SnakeSettings.h"

namespace Ui {
class GameSettingWindow;
}

class GameSettingWindow : public QWidget
{
    Q_OBJECT

public:
    //析构&构造函数
    explicit GameSettingWindow(QWidget *parent = nullptr);

    ~GameSettingWindow() override;

signals:
    //按下按钮时发送给MainWindow的信号
    void StartGame_clicked();

    void BackToMenu_clicked();

private slots:
    //发送按钮按下信号的槽函数
    void on_BackToMenuBtn_clicked();

    void on_StartGameBtn_clicked();

    //更新label上显示的信息
    //如果游戏人数变更为SnakeAuto，则四周都有墙
    void labelsUpdate();

    void on_btnColUp_clicked();

    void on_btnColDown_clicked();

    void on_btnRowUp_clicked();

    void on_btnRowDown_clicked();

    void on_btnWallSetLeft_clicked();

    void on_btnWallSetRight_clicked();

    void on_btnPlayerSetLeft_clicked();

    void on_btnPlayerSetRight_clicked();

    void on_btnSpeedUp_clicked();

    void on_btnSpeedDown_clicked();

    void on_checkBoxSP_stateChanged(int arg1);

    void on_checkBoxHT_stateChanged(int arg1);

    void on_checkBoxTS_stateChanged(int arg1);

protected:
    //在达到边界值后，延迟两秒刷新labels
    void timerEvent(QTimerEvent *event) override;

private:
    Ui::GameSettingWindow *ui;

    //用于延迟两秒刷新labels效果的变量
    int m_timerId;
    int delay_timerId;
    bool recoverLabels;
};

#endif // GAMESETTINGWINDOW_H
