#-------------------------------------------------
#
# Project created by QtCreator 2019-07-12T01:38:53
#
#-------------------------------------------------

QT       += core gui multimedia #播放游戏音效用

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        SourceCode/SnakeGame/SnakeAuto.cpp \
        SourceCode/SnakeGame/SnakeRanking.cpp \
        SourceCode/SnakeGame/SnakeSound.cpp \
        SourceCode/SnakeGame/SnakeSettings.cpp\
        SourceCode/SnakeGame/SnakeFood.cpp\
        SourceCode/SnakeGame/SnakeWall.cpp\
        SourceCode/SnakeGame/SnakePlayer.cpp\
        SourceCode/SnakeGame/SnakeList.cpp\
        SourceCode/SnakeGame/SnakeRenderer.cpp \
        SourceCode/SnakeGame/SnakeEmpty.cpp \
        SourceCode/SnakeGame/SnakeJudge.cpp \
        SourceCode/SubWindows/GameSettingWindow.cpp \
        SourceCode/SubWindows/MainMenu.cpp \
        SourceCode/SubWindows/GameOverWindow.cpp \
        SourceCode/main.cpp \
        SourceCode/MainWindow.cpp

HEADERS += \
        SourceCode/SnakeGame/SnakeAuto.h \
        SourceCode/SnakeGame/SnakeRanking.h \
        SourceCode/SnakeGame/SnakeSound.h \
        SourceCode/SnakeGame/SnakeEmpty.h \
        SourceCode/SnakeGame/SnakeJudge.h \
        SourceCode/SnakeGame/SnakeSettings.h\
        SourceCode/SnakeGame/SnakeFood.h\
        SourceCode/SnakeGame/SnakeWall.h\
        SourceCode/SnakeGame/SnakePlayer.h\
        SourceCode/SnakeGame/SnakeList.h\
        SourceCode/SnakeGame/SnakeRenderer.h\
        SourceCode/SubWindows/GameSettingWindow.h \
        SourceCode/SubWindows/MainMenu.h \
        SourceCode/SubWindows/GameOverWindow.h \
        SourceCode/MainWindow.h

FORMS += \
        SourceCode/SubWindows/GameSettingWindow.ui \
        SourceCode/SubWindows/MainMenu.ui \
        SourceCode/SubWindows/GameOverWindow.ui \
        SourceCode/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    snakeresource.qrc

DISTFILES +=
