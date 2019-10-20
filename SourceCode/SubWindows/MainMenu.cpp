#include "SourceCode/SubWindows/MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
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
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_PreSettingsBtn_clicked()
{
    SnakeSound::Page();
    emit PreSettings_clicked();
}

void MainMenu::on_ExitBtn_clicked()
{
    emit ExitGame_clicked();
}
