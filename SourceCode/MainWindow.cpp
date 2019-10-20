#include "SourceCode/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniWidget();
    //this->move(400, 200);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainMenu;
    delete gameSettingWindow;
    delete gameUi;
    delete gameOverWindow;
}

void MainWindow::iniWidget()
{
    //子界面初始化
    mainMenu = new MainMenu(this);
    gameSettingWindow = new GameSettingWindow(this);
    gameUi = new SnakeRenderer(this);
    gameOverWindow = new GameOverWindow(this);
    showMainMenu();

    //设置主窗口无边框且透明
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    //链接按钮信号与槽
    connect(mainMenu, SIGNAL(ExitGame_clicked()), this, SLOT(exitGame()));
    connect(mainMenu, SIGNAL(PreSettings_clicked()), this, SLOT(showPreSettingsWindow()));
    connect(gameSettingWindow, SIGNAL(BackToMenu_clicked()), this, SLOT(showMainMenu()));
    connect(gameSettingWindow, SIGNAL(StartGame_clicked()), this, SLOT(startGame()));
    connect(gameOverWindow, SIGNAL(Exit_clicked()), this, SLOT(exitGame()));
    connect(gameOverWindow, SIGNAL(Retry_clicked()), this, SLOT(startGame()));
    connect(gameOverWindow, SIGNAL(BackToMenu_clicked()), this, SLOT(showMainMenu()));
    connect(gameUi, SIGNAL(gameOver()), this, SLOT(endGame()));
    connect(gameUi, SIGNAL(saveGameData(int, int)), gameOverWindow, SLOT(iniGameOverWindow(int, int)));
}

void MainWindow::showPreSettingsWindow()
{
    mainMenu->hide();
    gameSettingWindow->show();
    gameUi->hide();
    gameOverWindow->hide();
    this->windowCentered();
}

void MainWindow::showMainMenu()
{
    mainMenu->show();
    gameSettingWindow->hide();
    gameUi->hide();
    gameOverWindow->hide();
    this->windowCentered();
}


void MainWindow::startGame()
{
    mainMenu->hide();
    gameSettingWindow->hide();
    gameUi->show();
    gameOverWindow->hide();
    this->resize(20 * SnakeSettings::maxCol, 20 * SnakeSettings::maxRow);
    this->windowCentered();
    gameUi->move(0, 0);
    gameUi->startGame();
    gameUi->setFocus(Qt::MouseFocusReason);
}

void MainWindow::endGame()
{
    this->resize(800, 600);
    mainMenu->hide();
    gameSettingWindow->hide();
    gameUi->hide();
    gameOverWindow->show();
    this->windowCentered();
}

void MainWindow::exitGame()
{
    this->close();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    mainMenu->resize(width(), height());
    gameSettingWindow->resize(width(), height());
    gameOverWindow->resize(width(), height());
}

void MainWindow::windowCentered()
{
    int DWidth = QApplication::desktop()->width();
    int DHeight = QApplication::desktop()->height();
    this->move((DWidth - width()) / 2, (DHeight - height()) / 2);
}
