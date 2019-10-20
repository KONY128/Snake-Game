#pragma once

//贪吃 蛇游戏的相关设置
class SnakeSettings
{
    //公有数据类型定义
public:
    enum resolutionSettings //游戏的分辨率设定
    {
        free,           //0   自由分辨率
        r800_600,       //1   最小分辨率
        r1280_800,      //2   中档分辨率
        r1400_900       //3   大档分辨率
    };
    enum wallSettings //设置墙壁是否可穿越
    {
        none,       //0   墙壁不通
        left_right, //1   左右相通
        up_down,    //2   上下相通
        all         //3   墙壁全通
    };
    enum playerSettings //设置玩家人数
    {
        autoPlay,     //0   自动模式
        singlePlayer, //1   单人游戏
        doublePlayer, //2   双人游戏
        triplePlayer  //3   三人游戏
    };

    //公有成员函数与数据成员
public:

    //限制游戏速度及地图最大、最小值
    const static int rowLimit_min;
    const static int rowLimit_max;
    const static int colLimit_min;
    const static int colLimit_max;
    const static int speedLimit_min;
    const static int speedLimit_max;

    static int maxRow;        //游戏的行、列值
    static int maxCol;
    static int gameSpeed;     //游戏速度值，即游戏地图多久刷新一次，单位ms
    static bool SuperPotion;  //是否允许游戏刷出超级药水
    static bool harshTerrain; //是否有初始地形和随机产生的砖块
    static bool trash;        //是否生成垃圾

    static playerSettings playerNum;     //游戏人数，为0则为自动，最多为四人游戏
    static resolutionSettings resolutionSet;
    static wallSettings wallSet;

    //初始化设置，默认游戏为20*20
    static void settingsIni(int const &MR = 20, int const &MC = 20);

    //判断游戏设置是否正常，各参数是否在正常范围之内
    static bool isGood();
};

