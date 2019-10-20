/********************************************************************************
** Form generated from reading UI file 'GameSettingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESETTINGWINDOW_H
#define UI_GAMESETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameSettingWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *shadowWidget;
    QPushButton *StartGameBtn;
    QPushButton *BackToMenuBtn;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelMaxCol;
    QPushButton *btnColUp;
    QPushButton *btnColDown;
    QCheckBox *checkBoxSP;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelMaxRow;
    QPushButton *btnRowUp;
    QPushButton *btnRowDown;
    QWidget *horizontalWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnWallSetLeft;
    QLabel *labelWallSet;
    QPushButton *btnWallSetRight;
    QWidget *horizontalWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnPlayerSetLeft;
    QLabel *labelPlayerSet;
    QPushButton *btnPlayerSetRight;
    QCheckBox *checkBoxHT;
    QWidget *horizontalWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelGameSpeed;
    QPushButton *btnSpeedUp;
    QPushButton *btnSpeedDown;
    QCheckBox *checkBoxTS;
    QLabel *labelGameSpeed_2;

    void setupUi(QWidget *GameSettingWindow)
    {
        if (GameSettingWindow->objectName().isEmpty())
            GameSettingWindow->setObjectName(QString::fromUtf8("GameSettingWindow"));
        GameSettingWindow->resize(800, 600);
        GameSettingWindow->setMinimumSize(QSize(800, 600));
        GameSettingWindow->setMaximumSize(QSize(1280, 800));
        verticalLayout = new QVBoxLayout(GameSettingWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        shadowWidget = new QWidget(GameSettingWindow);
        shadowWidget->setObjectName(QString::fromUtf8("shadowWidget"));
        shadowWidget->setMinimumSize(QSize(0, 0));
        shadowWidget->setMaximumSize(QSize(16777213, 16777215));
        shadowWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        StartGameBtn = new QPushButton(shadowWidget);
        StartGameBtn->setObjectName(QString::fromUtf8("StartGameBtn"));
        StartGameBtn->setGeometry(QRect(340, 500, 160, 40));
        StartGameBtn->setMinimumSize(QSize(160, 40));
        StartGameBtn->setMaximumSize(QSize(160, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        StartGameBtn->setFont(font);
        StartGameBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: 2px solid rgb(170, 255, 255);\n"
"}"));
        BackToMenuBtn = new QPushButton(shadowWidget);
        BackToMenuBtn->setObjectName(QString::fromUtf8("BackToMenuBtn"));
        BackToMenuBtn->setGeometry(QRect(340, 430, 160, 40));
        BackToMenuBtn->setMinimumSize(QSize(160, 40));
        BackToMenuBtn->setMaximumSize(QSize(160, 40));
        BackToMenuBtn->setFont(font);
        BackToMenuBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: 2px solid rgb(170, 255, 255);\n"
"}"));
        horizontalWidget = new QWidget(shadowWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(30, 40, 350, 50));
        horizontalWidget->setMinimumSize(QSize(350, 50));
        horizontalWidget->setMaximumSize(QSize(350, 50));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        labelMaxCol = new QLabel(horizontalWidget);
        labelMaxCol->setObjectName(QString::fromUtf8("labelMaxCol"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(12);
        labelMaxCol->setFont(font1);

        horizontalLayout->addWidget(labelMaxCol, 0, Qt::AlignHCenter);

        btnColUp = new QPushButton(horizontalWidget);
        btnColUp->setObjectName(QString::fromUtf8("btnColUp"));
        btnColUp->setMinimumSize(QSize(44, 44));
        btnColUp->setMaximumSize(QSize(44, 44));
        btnColUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/button/up"), QSize(), QIcon::Normal, QIcon::Off);
        btnColUp->setIcon(icon);
        btnColUp->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btnColUp);

        btnColDown = new QPushButton(horizontalWidget);
        btnColDown->setObjectName(QString::fromUtf8("btnColDown"));
        btnColDown->setMinimumSize(QSize(44, 44));
        btnColDown->setMaximumSize(QSize(44, 44));
        btnColDown->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/button/down"), QSize(), QIcon::Normal, QIcon::Off);
        btnColDown->setIcon(icon1);
        btnColDown->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btnColDown);

        checkBoxSP = new QCheckBox(shadowWidget);
        checkBoxSP->setObjectName(QString::fromUtf8("checkBoxSP"));
        checkBoxSP->setGeometry(QRect(60, 280, 170, 40));
        checkBoxSP->setMinimumSize(QSize(170, 40));
        checkBoxSP->setMaximumSize(QSize(170, 40));
        checkBoxSP->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/food/purplePotion"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxSP->setIcon(icon2);
        checkBoxSP->setChecked(true);
        checkBoxSP->setTristate(false);
        horizontalWidget_2 = new QWidget(shadowWidget);
        horizontalWidget_2->setObjectName(QString::fromUtf8("horizontalWidget_2"));
        horizontalWidget_2->setGeometry(QRect(30, 110, 350, 50));
        horizontalWidget_2->setMinimumSize(QSize(350, 50));
        horizontalWidget_2->setMaximumSize(QSize(350, 50));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        labelMaxRow = new QLabel(horizontalWidget_2);
        labelMaxRow->setObjectName(QString::fromUtf8("labelMaxRow"));
        labelMaxRow->setFont(font1);

        horizontalLayout_2->addWidget(labelMaxRow, 0, Qt::AlignHCenter);

        btnRowUp = new QPushButton(horizontalWidget_2);
        btnRowUp->setObjectName(QString::fromUtf8("btnRowUp"));
        btnRowUp->setMinimumSize(QSize(44, 44));
        btnRowUp->setMaximumSize(QSize(44, 44));
        btnRowUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        btnRowUp->setIcon(icon);
        btnRowUp->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btnRowUp);

        btnRowDown = new QPushButton(horizontalWidget_2);
        btnRowDown->setObjectName(QString::fromUtf8("btnRowDown"));
        btnRowDown->setMinimumSize(QSize(44, 44));
        btnRowDown->setMaximumSize(QSize(44, 44));
        btnRowDown->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        btnRowDown->setIcon(icon1);
        btnRowDown->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btnRowDown);

        horizontalWidget_3 = new QWidget(shadowWidget);
        horizontalWidget_3->setObjectName(QString::fromUtf8("horizontalWidget_3"));
        horizontalWidget_3->setGeometry(QRect(410, 40, 350, 50));
        horizontalWidget_3->setMinimumSize(QSize(350, 50));
        horizontalWidget_3->setMaximumSize(QSize(350, 50));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget_3);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(30, 0, 30, 0);
        btnWallSetLeft = new QPushButton(horizontalWidget_3);
        btnWallSetLeft->setObjectName(QString::fromUtf8("btnWallSetLeft"));
        btnWallSetLeft->setMinimumSize(QSize(44, 44));
        btnWallSetLeft->setMaximumSize(QSize(44, 44));
        btnWallSetLeft->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/button/left"), QSize(), QIcon::Normal, QIcon::Off);
        btnWallSetLeft->setIcon(icon3);
        btnWallSetLeft->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(btnWallSetLeft);

        labelWallSet = new QLabel(horizontalWidget_3);
        labelWallSet->setObjectName(QString::fromUtf8("labelWallSet"));
        labelWallSet->setFont(font1);

        horizontalLayout_3->addWidget(labelWallSet, 0, Qt::AlignHCenter);

        btnWallSetRight = new QPushButton(horizontalWidget_3);
        btnWallSetRight->setObjectName(QString::fromUtf8("btnWallSetRight"));
        btnWallSetRight->setMinimumSize(QSize(44, 44));
        btnWallSetRight->setMaximumSize(QSize(44, 44));
        btnWallSetRight->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Image/button/right"), QSize(), QIcon::Normal, QIcon::Off);
        btnWallSetRight->setIcon(icon4);
        btnWallSetRight->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(btnWallSetRight);

        horizontalWidget_4 = new QWidget(shadowWidget);
        horizontalWidget_4->setObjectName(QString::fromUtf8("horizontalWidget_4"));
        horizontalWidget_4->setGeometry(QRect(410, 110, 350, 50));
        horizontalWidget_4->setMinimumSize(QSize(350, 50));
        horizontalWidget_4->setMaximumSize(QSize(350, 50));
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_4);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(30, 0, 30, 0);
        btnPlayerSetLeft = new QPushButton(horizontalWidget_4);
        btnPlayerSetLeft->setObjectName(QString::fromUtf8("btnPlayerSetLeft"));
        btnPlayerSetLeft->setMinimumSize(QSize(44, 44));
        btnPlayerSetLeft->setMaximumSize(QSize(44, 44));
        btnPlayerSetLeft->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        btnPlayerSetLeft->setIcon(icon3);
        btnPlayerSetLeft->setIconSize(QSize(40, 40));

        horizontalLayout_4->addWidget(btnPlayerSetLeft);

        labelPlayerSet = new QLabel(horizontalWidget_4);
        labelPlayerSet->setObjectName(QString::fromUtf8("labelPlayerSet"));
        labelPlayerSet->setFont(font1);

        horizontalLayout_4->addWidget(labelPlayerSet, 0, Qt::AlignHCenter);

        btnPlayerSetRight = new QPushButton(horizontalWidget_4);
        btnPlayerSetRight->setObjectName(QString::fromUtf8("btnPlayerSetRight"));
        btnPlayerSetRight->setMinimumSize(QSize(44, 44));
        btnPlayerSetRight->setMaximumSize(QSize(44, 44));
        btnPlayerSetRight->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        btnPlayerSetRight->setIcon(icon4);
        btnPlayerSetRight->setIconSize(QSize(40, 40));

        horizontalLayout_4->addWidget(btnPlayerSetRight);

        checkBoxHT = new QCheckBox(shadowWidget);
        checkBoxHT->setObjectName(QString::fromUtf8("checkBoxHT"));
        checkBoxHT->setGeometry(QRect(60, 340, 170, 40));
        checkBoxHT->setMinimumSize(QSize(170, 40));
        checkBoxHT->setMaximumSize(QSize(170, 40));
        checkBoxHT->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Image/wall"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxHT->setIcon(icon5);
        checkBoxHT->setTristate(false);
        horizontalWidget_5 = new QWidget(shadowWidget);
        horizontalWidget_5->setObjectName(QString::fromUtf8("horizontalWidget_5"));
        horizontalWidget_5->setGeometry(QRect(30, 190, 350, 50));
        horizontalWidget_5->setMinimumSize(QSize(350, 50));
        horizontalWidget_5->setMaximumSize(QSize(350, 50));
        horizontalLayout_5 = new QHBoxLayout(horizontalWidget_5);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 0, 10, 0);
        labelGameSpeed = new QLabel(horizontalWidget_5);
        labelGameSpeed->setObjectName(QString::fromUtf8("labelGameSpeed"));
        labelGameSpeed->setFont(font1);

        horizontalLayout_5->addWidget(labelGameSpeed, 0, Qt::AlignHCenter);

        btnSpeedUp = new QPushButton(horizontalWidget_5);
        btnSpeedUp->setObjectName(QString::fromUtf8("btnSpeedUp"));
        btnSpeedUp->setMinimumSize(QSize(44, 44));
        btnSpeedUp->setMaximumSize(QSize(44, 44));
        btnSpeedUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        btnSpeedUp->setIcon(icon);
        btnSpeedUp->setIconSize(QSize(40, 40));

        horizontalLayout_5->addWidget(btnSpeedUp);

        btnSpeedDown = new QPushButton(horizontalWidget_5);
        btnSpeedDown->setObjectName(QString::fromUtf8("btnSpeedDown"));
        btnSpeedDown->setMinimumSize(QSize(44, 44));
        btnSpeedDown->setMaximumSize(QSize(44, 44));
        btnSpeedDown->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: 4px solid rgb(170, 255, 255);\n"
"}"));
        btnSpeedDown->setIcon(icon1);
        btnSpeedDown->setIconSize(QSize(40, 40));

        horizontalLayout_5->addWidget(btnSpeedDown);

        checkBoxTS = new QCheckBox(shadowWidget);
        checkBoxTS->setObjectName(QString::fromUtf8("checkBoxTS"));
        checkBoxTS->setGeometry(QRect(60, 400, 170, 40));
        checkBoxTS->setMinimumSize(QSize(170, 40));
        checkBoxTS->setMaximumSize(QSize(170, 40));
        checkBoxTS->setFont(font1);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Image/food/poo"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxTS->setIcon(icon6);
        checkBoxTS->setChecked(true);
        checkBoxTS->setTristate(false);
        labelGameSpeed_2 = new QLabel(shadowWidget);
        labelGameSpeed_2->setObjectName(QString::fromUtf8("labelGameSpeed_2"));
        labelGameSpeed_2->setGeometry(QRect(630, 550, 151, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        labelGameSpeed_2->setFont(font2);
        labelGameSpeed_2->setStyleSheet(QString::fromUtf8("QLabel:hover{\n"
"color: rgb(72, 72, 218);\n"
"}"));

        verticalLayout->addWidget(shadowWidget);


        retranslateUi(GameSettingWindow);

        QMetaObject::connectSlotsByName(GameSettingWindow);
    } // setupUi

    void retranslateUi(QWidget *GameSettingWindow)
    {
        GameSettingWindow->setWindowTitle(QApplication::translate("GameSettingWindow", "GameSettingWindow", nullptr));
        StartGameBtn->setText(QApplication::translate("GameSettingWindow", "Start Game", nullptr));
        BackToMenuBtn->setText(QApplication::translate("GameSettingWindow", "Back", nullptr));
        labelMaxCol->setText(QApplication::translate("GameSettingWindow", "Max Col", nullptr));
        btnColUp->setText(QString());
        btnColDown->setText(QString());
#ifndef QT_NO_STATUSTIP
        checkBoxSP->setStatusTip(QApplication::translate("GameSettingWindow", "status test", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBoxSP->setWhatsThis(QApplication::translate("GameSettingWindow", "this is super potion", nullptr));
#endif // QT_NO_WHATSTHIS
        checkBoxSP->setText(QApplication::translate("GameSettingWindow", "Super Potions", nullptr));
        labelMaxRow->setText(QApplication::translate("GameSettingWindow", "Max Row", nullptr));
        btnRowUp->setText(QString());
        btnRowDown->setText(QString());
        btnWallSetLeft->setText(QString());
        labelWallSet->setText(QApplication::translate("GameSettingWindow", "Wall Set", nullptr));
        btnWallSetRight->setText(QString());
        btnPlayerSetLeft->setText(QString());
        labelPlayerSet->setText(QApplication::translate("GameSettingWindow", "Player Set", nullptr));
        btnPlayerSetRight->setText(QString());
        checkBoxHT->setText(QApplication::translate("GameSettingWindow", "Harsh Terrain", nullptr));
        labelGameSpeed->setText(QApplication::translate("GameSettingWindow", "Game Speed", nullptr));
        btnSpeedUp->setText(QString());
        btnSpeedDown->setText(QString());
        checkBoxTS->setText(QApplication::translate("GameSettingWindow", "Trash", nullptr));
        labelGameSpeed_2->setText(QApplication::translate("GameSettingWindow", "Made By KONY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameSettingWindow: public Ui_GameSettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESETTINGWINDOW_H
