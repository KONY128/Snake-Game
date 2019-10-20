/********************************************************************************
** Form generated from reading UI file 'MainMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *shadowWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *PreSettingsBtn;
    QPushButton *ExitBtn;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(800, 600);
        MainMenu->setMinimumSize(QSize(800, 600));
        MainMenu->setMaximumSize(QSize(1280, 800));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainMenu->setFont(font);
        MainMenu->setAutoFillBackground(false);
        MainMenu->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(MainMenu);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        shadowWidget = new QWidget(MainMenu);
        shadowWidget->setObjectName(QString::fromUtf8("shadowWidget"));
        shadowWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(shadowWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(shadowWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(270, 60));
        label->setMaximumSize(QSize(270, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(27);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        PreSettingsBtn = new QPushButton(shadowWidget);
        PreSettingsBtn->setObjectName(QString::fromUtf8("PreSettingsBtn"));
        PreSettingsBtn->setMinimumSize(QSize(160, 40));
        PreSettingsBtn->setMaximumSize(QSize(160, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        PreSettingsBtn->setFont(font2);
        PreSettingsBtn->setLayoutDirection(Qt::LeftToRight);
        PreSettingsBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: 2px solid rgb(170, 255, 255);\n"
"}"));

        gridLayout->addWidget(PreSettingsBtn, 1, 0, 1, 1, Qt::AlignHCenter);

        ExitBtn = new QPushButton(shadowWidget);
        ExitBtn->setObjectName(QString::fromUtf8("ExitBtn"));
        ExitBtn->setMinimumSize(QSize(160, 40));
        ExitBtn->setMaximumSize(QSize(160, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        ExitBtn->setFont(font3);
        ExitBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: 2px solid rgb(255, 255, 0);\n"
"}\n"
""));

        gridLayout->addWidget(ExitBtn, 2, 0, 1, 1, Qt::AlignHCenter);


        horizontalLayout->addWidget(shadowWidget);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", nullptr));
        label->setText(QApplication::translate("MainMenu", "Snake Game", nullptr));
        PreSettingsBtn->setText(QApplication::translate("MainMenu", "Pre Settings", nullptr));
        ExitBtn->setText(QApplication::translate("MainMenu", "Exit Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
