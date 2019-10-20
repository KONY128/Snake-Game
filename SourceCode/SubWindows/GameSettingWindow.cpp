#include "SourceCode/SubWindows/GameSettingWindow.h"
#include "ui_GameSettingWindow.h"
GameSettingWindow::GameSettingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSettingWindow)
{
    ui->setupUi(this);
    //设置主窗口无边框，且透明
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    //设置边框阴影效果
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(5);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);
    ui->shadowWidget->setGraphicsEffect(shadow);
    this->m_timerId = this->startTimer(100);
    labelsUpdate();
    recoverLabels = false;
}

GameSettingWindow::~GameSettingWindow()
{
    delete ui;
}

//发送按钮按下信号的槽函数
void GameSettingWindow::on_BackToMenuBtn_clicked()
{
        SnakeSound::Page();
    emit BackToMenu_clicked();
}

void GameSettingWindow::on_StartGameBtn_clicked()
{
        SnakeSound::Page();
    emit StartGame_clicked();
}

void GameSettingWindow::labelsUpdate()
{
    if (SnakeSettings::playerNum == SnakeSettings::autoPlay)
        SnakeSettings::wallSet = SnakeSettings::none;

    //方便生成label信息
    std::stringstream ss;
    std::string labelText;

    ss << "Game Col: " << SnakeSettings::maxCol;
    std::getline(ss, labelText);
    ss.clear();
    ui->labelMaxCol->setText(QString::fromStdString(labelText));

    ss << "Game Row: " << SnakeSettings::maxRow;
    std::getline(ss, labelText);
    ss.clear();
    ui->labelMaxRow->setText(QString::fromStdString(labelText));

    ss << "Game Speed: " << SnakeSettings::gameSpeed << " ms";
    std::getline(ss, labelText);
    ss.clear();
    ui->labelGameSpeed->setText(QString::fromStdString(labelText));

    switch (SnakeSettings::wallSet) {
    case SnakeSettings::none: ss << "All Walls"; break;
    case SnakeSettings::up_down: ss << "Left & Right Walls"; break;
    case SnakeSettings::left_right: ss << "Up & Down Walls"; break;
    case SnakeSettings::all: ss << "No Walls"; break;
    }
    std::getline(ss, labelText);
    ss.clear();
    ui->labelWallSet->setText(QString::fromStdString(labelText));

    switch (SnakeSettings::playerNum) {
    case SnakeSettings::autoPlay: ss << "Auto Play"; break;
    case SnakeSettings::singlePlayer: ss << "Single Player"; break;
    case SnakeSettings::doublePlayer: ss << "Double Players"; break;
    case SnakeSettings::triplePlayer: ss << "Triple Players"; break;
    }
    std::getline(ss, labelText);
    ss.clear();
    ui->labelPlayerSet->setText(QString::fromStdString(labelText));

    //ui->checkBoxSP->checkState()
}

//在达到边界值后，延迟两秒刷新labels
void GameSettingWindow::timerEvent(QTimerEvent *event)
{
    QWidget::timerEvent(event);
    if (event->timerId() == this->m_timerId && this->recoverLabels == true)
    {
        delay_timerId = this->startTimer(2000);
        recoverLabels = false;
    }
    if (event->timerId() == delay_timerId)
    {
        labelsUpdate();
        this->killTimer(delay_timerId);
    }
}

void GameSettingWindow::on_btnColUp_clicked()
{
    SnakeSound::Click();
    SnakeSettings::maxCol += 5;
    this->labelsUpdate();
    if (SnakeSettings::isGood() == false)
    {
        recoverLabels = true;
        SnakeSettings::maxCol -= 5;
        std::stringstream ss;
        std::string labelText;
        ss << "Maximum Col: " << SnakeSettings::colLimit_max;
        std::getline(ss, labelText);
        ui->labelMaxCol->setText(QString::fromStdString(labelText));
    }
}

void GameSettingWindow::on_btnColDown_clicked()
{
    SnakeSound::Click();
    SnakeSettings::maxCol -= 5;
    this->labelsUpdate();
    if (SnakeSettings::isGood() == false)
    {
        recoverLabels = true;
        SnakeSettings::maxCol += 5;
        std::stringstream ss;
        std::string labelText;
        ss << "Minimum Col: " << SnakeSettings::colLimit_min;
        std::getline(ss, labelText);
        ui->labelMaxCol->setText(QString::fromStdString(labelText));
    }
}

void GameSettingWindow::on_btnRowUp_clicked()
{
    SnakeSound::Click();
    SnakeSettings::maxRow += 5;
    this->labelsUpdate();
    if (SnakeSettings::isGood() == false)
    {
        recoverLabels = true;
        SnakeSettings::maxRow -= 5;
        std::stringstream ss;
        std::string labelText;
        ss << "Maximum Row: " << SnakeSettings::rowLimit_max;
        std::getline(ss, labelText);
        ui->labelMaxRow->setText(QString::fromStdString(labelText));
    }
}

void GameSettingWindow::on_btnRowDown_clicked()
{
    SnakeSound::Click();
    SnakeSettings::maxRow -= 5;
    this->labelsUpdate();
    if (SnakeSettings::isGood() == false)
    {
        recoverLabels = true;
        SnakeSettings::maxRow += 5;
        std::stringstream ss;
        std::string labelText;
        ss << "Minimum Row: " << SnakeSettings::rowLimit_min;
        std::getline(ss, labelText);
        ui->labelMaxRow->setText(QString::fromStdString(labelText));
    }
}

void GameSettingWindow::on_btnWallSetLeft_clicked()
{
    SnakeSound::Click();
    int wallSetIndex = static_cast<int>(SnakeSettings::wallSet);
    wallSetIndex = (wallSetIndex - 1 + 4) % 4;
    SnakeSettings::wallSet = static_cast<SnakeSettings::wallSettings>(wallSetIndex);
    this->labelsUpdate();
}

void GameSettingWindow::on_btnWallSetRight_clicked()
{
    SnakeSound::Click();
    int wallSetIndex = static_cast<int>(SnakeSettings::wallSet);
    wallSetIndex = (wallSetIndex + 1) % 4;
    SnakeSettings::wallSet = static_cast<SnakeSettings::wallSettings>(wallSetIndex);
    this->labelsUpdate();
}

void GameSettingWindow::on_btnPlayerSetLeft_clicked()
{
    SnakeSound::Click();
    int playerSetIndex = static_cast<int>(SnakeSettings::playerNum);
    playerSetIndex = (playerSetIndex - 1 + 4) % 4;
    SnakeSettings::playerNum = static_cast<SnakeSettings::playerSettings>(playerSetIndex);
    this->labelsUpdate();
}

void GameSettingWindow::on_btnPlayerSetRight_clicked()
{
    SnakeSound::Click();
    int playerSetIndex = static_cast<int>(SnakeSettings::playerNum);
    playerSetIndex = (playerSetIndex + 1) % 4;
    SnakeSettings::playerNum = static_cast<SnakeSettings::playerSettings>(playerSetIndex);
    this->labelsUpdate();
}

void GameSettingWindow::on_btnSpeedUp_clicked()
{
    SnakeSound::Click();
    SnakeSettings::gameSpeed += 50;
    this->labelsUpdate();
    if (SnakeSettings::isGood() == false)
    {
        recoverLabels = true;
        SnakeSettings::gameSpeed -= 50;
        std::stringstream ss;
        std::string labelText;
        ss << "Maximum Speed: " << SnakeSettings::speedLimit_max << " ms";
        std::getline(ss, labelText);
        ui->labelGameSpeed->setText(QString::fromStdString(labelText));
    }
}

void GameSettingWindow::on_btnSpeedDown_clicked()
{
    SnakeSound::Click();
    SnakeSettings::gameSpeed -= 50;
    this->labelsUpdate();
    if (SnakeSettings::isGood() == false)
    {
        recoverLabels = true;
        SnakeSettings::gameSpeed += 50;
        std::stringstream ss;
        std::string labelText;
        ss << "Minimum Speed: " << SnakeSettings::speedLimit_min << " ms";
        std::getline(ss, labelText);
        ui->labelGameSpeed->setText(QString::fromStdString(labelText));
    }
}

void GameSettingWindow::on_checkBoxSP_stateChanged(int arg1)
{
    SnakeSound::Click();
    SnakeSettings::SuperPotion = arg1;
}

void GameSettingWindow::on_checkBoxHT_stateChanged(int arg1)
{
    SnakeSound::Click();
    SnakeSettings::harshTerrain = arg1;
}

void GameSettingWindow::on_checkBoxTS_stateChanged(int arg1)
{
    SnakeSound::Click();
    SnakeSettings::trash = arg1;
}
