#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>    //窗口阴影
#include <QVector>
#include "SourceCode/SubWindows/MainMenu.h"
#include "SourceCode/SubWindows/GameSettingWindow.h"
#include "SourceCode/SnakeGame/SnakeRenderer.h"
#include "SourceCode/SubWindows/GameOverWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void iniWidget();

private slots:
    void exitGame();

    void showPreSettingsWindow();

    void showMainMenu();

    void startGame();

    void endGame();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void windowCentered();

private:
    Ui::MainWindow *ui;
    GameSettingWindow *gameSettingWindow;
    MainMenu *mainMenu;
    SnakeRenderer *gameUi;
    GameOverWindow *gameOverWindow;
};

#endif // MAINWINDOW_H
