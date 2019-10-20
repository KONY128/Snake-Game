/********************************************************************************
** Form generated from reading UI file 'GameOverWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERWINDOW_H
#define UI_GAMEOVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOverWindow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lableText1;
    QLabel *labelWinnerPlayerId;
    QLabel *labelText2;
    QLabel *labelWinnerScore;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *labelWinner;
    QLineEdit *lineEditWinnerName;
    QPushButton *NameConfirmBtn;
    QGridLayout *gridLayout;
    QListWidget *rankingList_name;
    QListWidget *rankingList_score;
    QLabel *labelText3;
    QLabel *labelText4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *BackToMenuBtn;
    QPushButton *RetryBtn;
    QPushButton *ExitBtn;

    void setupUi(QWidget *GameOverWindow)
    {
        if (GameOverWindow->objectName().isEmpty())
            GameOverWindow->setObjectName(QString::fromUtf8("GameOverWindow"));
        GameOverWindow->resize(800, 606);
        GameOverWindow->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(GameOverWindow);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(GameOverWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(25);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 15, -1, 10);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lableText1 = new QLabel(widget);
        lableText1->setObjectName(QString::fromUtf8("lableText1"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(14);
        lableText1->setFont(font);

        horizontalLayout_3->addWidget(lableText1);

        labelWinnerPlayerId = new QLabel(widget);
        labelWinnerPlayerId->setObjectName(QString::fromUtf8("labelWinnerPlayerId"));
        labelWinnerPlayerId->setMinimumSize(QSize(120, 30));
        labelWinnerPlayerId->setMaximumSize(QSize(120, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(13);
        font1.setUnderline(false);
        labelWinnerPlayerId->setFont(font1);

        horizontalLayout_3->addWidget(labelWinnerPlayerId);

        labelText2 = new QLabel(widget);
        labelText2->setObjectName(QString::fromUtf8("labelText2"));
        labelText2->setFont(font);

        horizontalLayout_3->addWidget(labelText2);

        labelWinnerScore = new QLabel(widget);
        labelWinnerScore->setObjectName(QString::fromUtf8("labelWinnerScore"));
        labelWinnerScore->setMinimumSize(QSize(100, 30));
        labelWinnerScore->setMaximumSize(QSize(100, 30));
        labelWinnerScore->setFont(font1);

        horizontalLayout_3->addWidget(labelWinnerScore);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelWinner = new QLabel(widget);
        labelWinner->setObjectName(QString::fromUtf8("labelWinner"));
        labelWinner->setMinimumSize(QSize(200, 30));
        labelWinner->setMaximumSize(QSize(200, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(14);
        font2.setUnderline(false);
        labelWinner->setFont(font2);

        horizontalLayout->addWidget(labelWinner);

        lineEditWinnerName = new QLineEdit(widget);
        lineEditWinnerName->setObjectName(QString::fromUtf8("lineEditWinnerName"));
        lineEditWinnerName->setMinimumSize(QSize(65, 40));
        lineEditWinnerName->setMaximumSize(QSize(400, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(11);
        font3.setUnderline(false);
        lineEditWinnerName->setFont(font3);

        horizontalLayout->addWidget(lineEditWinnerName);

        NameConfirmBtn = new QPushButton(widget);
        NameConfirmBtn->setObjectName(QString::fromUtf8("NameConfirmBtn"));
        NameConfirmBtn->setMinimumSize(QSize(130, 40));
        NameConfirmBtn->setMaximumSize(QSize(130, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        NameConfirmBtn->setFont(font4);
        NameConfirmBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: 2px solid rgb(170, 255, 255);\n"
"}"));

        horizontalLayout->addWidget(NameConfirmBtn);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rankingList_name = new QListWidget(widget);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        new QListWidgetItem(rankingList_name);
        rankingList_name->setObjectName(QString::fromUtf8("rankingList_name"));
        rankingList_name->setMaximumSize(QSize(360, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        rankingList_name->setFont(font5);

        gridLayout->addWidget(rankingList_name, 1, 0, 1, 1);

        rankingList_score = new QListWidget(widget);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        new QListWidgetItem(rankingList_score);
        rankingList_score->setObjectName(QString::fromUtf8("rankingList_score"));
        rankingList_score->setMaximumSize(QSize(220, 16777215));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setUnderline(false);
        font6.setWeight(50);
        rankingList_score->setFont(font6);

        gridLayout->addWidget(rankingList_score, 1, 1, 1, 1);

        labelText3 = new QLabel(widget);
        labelText3->setObjectName(QString::fromUtf8("labelText3"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font7.setPointSize(13);
        labelText3->setFont(font7);

        gridLayout->addWidget(labelText3, 0, 0, 1, 1);

        labelText4 = new QLabel(widget);
        labelText4->setObjectName(QString::fromUtf8("labelText4"));
        labelText4->setFont(font7);

        gridLayout->addWidget(labelText4, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BackToMenuBtn = new QPushButton(widget);
        BackToMenuBtn->setObjectName(QString::fromUtf8("BackToMenuBtn"));
        BackToMenuBtn->setMinimumSize(QSize(180, 40));
        BackToMenuBtn->setMaximumSize(QSize(180, 40));
        BackToMenuBtn->setFont(font4);
        BackToMenuBtn->setStyleSheet(QString::fromUtf8("QPushButton{border: none;background-color: rgb(255, 255, 255);}QPushButton:hover{border: 2px solid rgb(170, 255, 255);}"));

        verticalLayout_2->addWidget(BackToMenuBtn, 0, Qt::AlignHCenter);

        RetryBtn = new QPushButton(widget);
        RetryBtn->setObjectName(QString::fromUtf8("RetryBtn"));
        RetryBtn->setMinimumSize(QSize(180, 40));
        RetryBtn->setMaximumSize(QSize(180, 40));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font8.setPointSize(14);
        font8.setBold(true);
        font8.setWeight(75);
        RetryBtn->setFont(font8);
        RetryBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: 2px solid rgb(170, 255, 255);\n"
"}"));

        verticalLayout_2->addWidget(RetryBtn, 0, Qt::AlignHCenter);

        ExitBtn = new QPushButton(widget);
        ExitBtn->setObjectName(QString::fromUtf8("ExitBtn"));
        ExitBtn->setMinimumSize(QSize(180, 40));
        ExitBtn->setMaximumSize(QSize(180, 40));
        ExitBtn->setFont(font4);
        ExitBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border: 2px solid rgb(255, 255, 0);\n"
"}"));

        verticalLayout_2->addWidget(ExitBtn, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(GameOverWindow);

        QMetaObject::connectSlotsByName(GameOverWindow);
    } // setupUi

    void retranslateUi(QWidget *GameOverWindow)
    {
        GameOverWindow->setWindowTitle(QApplication::translate("GameOverWindow", "GameOverWindow", nullptr));
        lableText1->setText(QApplication::translate("GameOverWindow", "The Winner Is : ", nullptr));
        labelWinnerPlayerId->setText(QApplication::translate("GameOverWindow", "player* ", nullptr));
        labelText2->setText(QApplication::translate("GameOverWindow", "Score : ", nullptr));
        labelWinnerScore->setText(QApplication::translate("GameOverWindow", "****", nullptr));
        labelWinner->setText(QApplication::translate("GameOverWindow", "Winner Name :", nullptr));
        lineEditWinnerName->setText(QApplication::translate("GameOverWindow", "Input your name here for ranking.", nullptr));
        NameConfirmBtn->setText(QApplication::translate("GameOverWindow", "Confirm", nullptr));

        const bool __sortingEnabled = rankingList_name->isSortingEnabled();
        rankingList_name->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = rankingList_name->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("GameOverWindow", "test", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = rankingList_name->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("GameOverWindow", "b", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = rankingList_name->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("GameOverWindow", "c", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = rankingList_name->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("GameOverWindow", "d", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = rankingList_name->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("GameOverWindow", "e", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = rankingList_name->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("GameOverWindow", "f", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = rankingList_name->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("GameOverWindow", "g", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = rankingList_name->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("GameOverWindow", "h", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = rankingList_name->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("GameOverWindow", "i", nullptr));
        rankingList_name->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = rankingList_score->isSortingEnabled();
        rankingList_score->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem9 = rankingList_score->item(0);
        ___qlistwidgetitem9->setText(QApplication::translate("GameOverWindow", "1234", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = rankingList_score->item(1);
        ___qlistwidgetitem10->setText(QApplication::translate("GameOverWindow", "2", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = rankingList_score->item(2);
        ___qlistwidgetitem11->setText(QApplication::translate("GameOverWindow", "3", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = rankingList_score->item(3);
        ___qlistwidgetitem12->setText(QApplication::translate("GameOverWindow", "4", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = rankingList_score->item(4);
        ___qlistwidgetitem13->setText(QApplication::translate("GameOverWindow", "5", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = rankingList_score->item(5);
        ___qlistwidgetitem14->setText(QApplication::translate("GameOverWindow", "6", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = rankingList_score->item(6);
        ___qlistwidgetitem15->setText(QApplication::translate("GameOverWindow", "7", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = rankingList_score->item(7);
        ___qlistwidgetitem16->setText(QApplication::translate("GameOverWindow", "8", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = rankingList_score->item(8);
        ___qlistwidgetitem17->setText(QApplication::translate("GameOverWindow", "9", nullptr));
        rankingList_score->setSortingEnabled(__sortingEnabled1);

        labelText3->setText(QApplication::translate("GameOverWindow", "Best player ever \360\237\221\207", nullptr));
        labelText4->setText(QApplication::translate("GameOverWindow", "Their Score \360\237\221\207", nullptr));
        BackToMenuBtn->setText(QApplication::translate("GameOverWindow", "Back To Menu", nullptr));
        RetryBtn->setText(QApplication::translate("GameOverWindow", "Retry", nullptr));
        ExitBtn->setText(QApplication::translate("GameOverWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverWindow: public Ui_GameOverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERWINDOW_H
