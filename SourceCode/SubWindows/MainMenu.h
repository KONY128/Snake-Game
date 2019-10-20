#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>

#include "SourceCode/SnakeGame/SnakeSound.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

signals:
    void PreSettings_clicked();
    void ExitGame_clicked();

protected:

private slots:
    void on_PreSettingsBtn_clicked();
    void on_ExitBtn_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
