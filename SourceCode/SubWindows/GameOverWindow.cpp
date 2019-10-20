#include "SourceCode/SubWindows/GameOverWindow.h"
#include "ui_GameOverWindow.h"

GameOverWindow::GameOverWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);
    iniGameOverWindow(0, 1);
}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}

void GameOverWindow::iniGameOverWindow(int Score, int PlayerId)
{
    switch (PlayerId){
    case 1:
        if (SnakeSettings::playerNum == SnakeSettings::autoPlay)
            ui->labelWinnerPlayerId->setText(QStringLiteral("autoPlay"));
        else
            ui->labelWinnerPlayerId->setText(QStringLiteral("Player1"));
        break;
    case 2:
        ui->labelWinnerPlayerId->setText(QStringLiteral("Player2"));
        break;
    case 3:
        ui->labelWinnerPlayerId->setText(QStringLiteral("Player3"));
        break;
    default: throw "Error. Wrong PlayerId parameter.";
    }
    ui->labelWinnerScore->setText(QString::number(Score));
    ui->lineEditWinnerName->setText(QStringLiteral("Input your name here for ranking."));
    confirmFlag = false;
    saveFlag = false;
    winnerName = QString();
    updateRankingList();
}

void GameOverWindow::on_BackToMenuBtn_clicked()
{
    SnakeSound::Page();
    emit BackToMenu_clicked();
}

void GameOverWindow::on_RetryBtn_clicked()
{
    SnakeSound::Page();
    emit Retry_clicked();
}

void GameOverWindow::on_ExitBtn_clicked()
{
    emit Exit_clicked();
}

void GameOverWindow::on_lineEditWinnerName_editingFinished()
{
    SnakeSound::Click();
    if (saveFlag == true)
        return;
    if (ui->lineEditWinnerName->text() == QStringLiteral("Input your name here for ranking."))
        return;
    confirmFlag = false;
    winnerName = ui->lineEditWinnerName->text();
}

//没有输入：不做反应
//输入了名字：确认用这个名字吗？确认就再按一次（五秒内）
//超过五秒则恢复原状
void GameOverWindow::on_NameConfirmBtn_clicked()
{
    SnakeSound::Click();
    //上传ranking完成后，恒显示这句话
    if (saveFlag == true)
    {
        ui->lineEditWinnerName->setText(QStringLiteral("Ranking complete."));
        return;
    }
    if (winnerName == QString())
    {
        ui->lineEditWinnerName->setText(QStringLiteral("Input your name here for ranking."));
        return;
    }
    //第一次上传ranking，保存playerName
    if (confirmFlag == false)
    {
        winnerName = ui->lineEditWinnerName->text();
        ui->lineEditWinnerName->setText(QStringLiteral("Click again to confirm your name."));
        confirmFlag = true;
        m_timerId = this->startTimer(5000);
        return;
    }
    //第二次按按钮，保证以后按按钮没反应了
    saveFlag = true;

    this->saveRanking(winnerName, ui->labelWinnerScore->text().toInt());
    winnerName = QString();
    this->killTimer(m_timerId);
    ui->lineEditWinnerName->setText(QStringLiteral("Ranking complete."));
}

void GameOverWindow::saveRanking(QString PlayerName, int Score)
{
    rankingList.AddRanking(PlayerName, Score);
    rankingList.SaveRanking();
    updateRankingList();
}

void GameOverWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId)
    {
        confirmFlag = false;
        ui->lineEditWinnerName->setText(winnerName);
        this->killTimer(m_timerId);
    }
}

void GameOverWindow::updateRankingList()
{
    ui->rankingList_name->clear();
    ui->rankingList_score->clear();
    for (auto iter = rankingList.rankingList.begin(); iter != rankingList.rankingList.end(); iter++)
    {
         ui->rankingList_name->addItem(iter->name);
         ui->rankingList_score->addItem(QString::number(iter->score));
    }
}
