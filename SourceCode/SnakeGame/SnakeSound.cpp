#include "SnakeSound.h"

QMediaPlayer SnakeSound::SoundPlayer;

//2019/9/24 BUG: 相对位置失效
//原因：改变了文件夹路径，已有的编译文件中相对地址错误
//教训：相对位置是以build 项目参数来确定的，记得改掉build项目参数
void SnakeSound::GameStart()
{
    SoundPlayer.setVolume(40);
    SoundPlayer.setMedia(QUrl::fromLocalFile("./SoundEffects/GameStart.mp3"));
    SoundPlayer.play();
}

void SnakeSound::Click()
{
    SoundPlayer.setVolume(20);
    SoundPlayer.setMedia(QUrl::fromLocalFile("./SoundEffects/Click.mp3"));
    SoundPlayer.play();
}

void SnakeSound::Potion()
{
    SoundPlayer.setVolume(38);
    SoundPlayer.setMedia(QUrl::fromLocalFile("./SoundEffects/Potion.mp3"));
    SoundPlayer.play();
}

void SnakeSound::Food()
{
    SoundPlayer.setVolume(100);
    SoundPlayer.setMedia(QUrl::fromLocalFile("./SoundEffects/Food.mp3"));
    SoundPlayer.play();
}

void SnakeSound::Page()
{
    SoundPlayer.setVolume(70);
    SoundPlayer.setMedia(QUrl::fromLocalFile("./SoundEffects/Page.wav"));
    SoundPlayer.play();
}

void SnakeSound::Bomb()
{
    SoundPlayer.setVolume(22);
    SoundPlayer.setMedia(QUrl::fromLocalFile("./SoundEffects/Bomb.wav"));
    SoundPlayer.play();
}

void SnakeSound::Poo()
{
    SoundPlayer.setVolume(100);
    SoundPlayer.setMedia(QUrl::fromLocalFile("./SoundEffects/Poo.mp3"));
    SoundPlayer.play();
}
