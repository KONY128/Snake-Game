#ifndef SNAKESOUND_H
#define SNAKESOUND_H

#include <QWidget>
#include <QMediaPlayer>

class SnakeSound : public QWidget
{
    Q_OBJECT
public:

    static QMediaPlayer SoundPlayer;

    //播放游戏各类音效
    static void GameStart();

    static void Click();

    static void Potion();

    static void Food();

    static void Page();

    static void Bomb();

    static void Poo();
};

#endif // SNAKESOUND_H
