#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <sstream>
#include <QWidget>

#include "SourceCode/SnakeGame/SnakeSound.h"
#include "SourceCode/SnakeGame/SnakeSettings.h"
#include "SourceCode/SnakeGame/SnakeRanking.h"

namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = nullptr);

    ~GameOverWindow() override;

signals:
    //按下按钮时发送给MainWindow的信号
    void Retry_clicked();

    void BackToMenu_clicked();

    void Exit_clicked();

private slots:
    void iniGameOverWindow(int Score, int PlayerId);

    void on_BackToMenuBtn_clicked();

    void on_RetryBtn_clicked();

    void on_ExitBtn_clicked();

    void on_lineEditWinnerName_editingFinished();

    void on_NameConfirmBtn_clicked();

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    //根据SnakeRanking更新rankingList_name/score
    void updateRankingList();

    //保存ranking记录并更新rankingList
    void saveRanking(QString PlayerName, int Score);

private:
    Ui::GameOverWindow *ui;
    QString winnerName;
    SnakeRanking rankingList;

    //按两次按钮确认存储
    bool confirmFlag;
    //保存结束防止再次保存
    bool saveFlag;
    //五秒后confirmFlag置false并恢复内容
    int m_timerId;
};

#endif // GAMEOVERWINDOW_H
