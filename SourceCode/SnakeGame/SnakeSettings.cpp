#include "SourceCode/SnakeGame/SnakeSettings.h"

//定义游戏设置变量，给static变量开辟存储空间,并赋默认值
//游戏模式默认值
SnakeSettings::playerSettings SnakeSettings::playerNum = SnakeSettings::doublePlayer;      //默认为单人模式
SnakeSettings::resolutionSettings SnakeSettings::resolutionSet = SnakeSettings::r1280_800; //默认分辨率大小为1280*800
SnakeSettings::wallSettings SnakeSettings::wallSet = SnakeSettings::all;                   //默认墙壁为四面相通
bool SnakeSettings::harshTerrain = false;                                                  //初始地形默认为关
bool SnakeSettings::SuperPotion = true;                                                    //默认不刷超级药水
bool SnakeSettings::trash = true;                                                          //默认生成垃圾

//游戏地图应该在10*10到40*60之间
const int SnakeSettings::rowLimit_min = 10;
const int SnakeSettings::rowLimit_max = 40;
const int SnakeSettings::colLimit_min = 10;
const int SnakeSettings::colLimit_max = 60;
//游戏速度应该在50~1000ms之间
const int SnakeSettings::speedLimit_min = 50;
const int SnakeSettings::speedLimit_max = 1000;

//默认地图大小即最小地图
int SnakeSettings::maxRow = rowLimit_min;
int SnakeSettings::maxCol = colLimit_min;
int SnakeSettings::gameSpeed = 400;

//构造函数，设置其最大行列数、墙壁设置等等
void SnakeSettings::settingsIni(int const &MR, int const &MC)
{
    playerNum = singlePlayer;  //默认为单人模式
    wallSet = none;            //默认墙壁为四面不通
    resolutionSet = r800_600; //默认分辨率大小为1280*800
    harshTerrain = false;      //初始地形默认为关
    //确保输入参数正常
    if (MR < rowLimit_min || MC < colLimit_min || MR > rowLimit_max ||
        MC > colLimit_max || gameSpeed > speedLimit_max || gameSpeed < speedLimit_min)
        throw "Error. Your Parameters Exceed Settting Limit.";
    maxRow = MR;
    maxCol = MC;
}

//判断游戏设置是否正常，各参数是否在正常范围之内
bool SnakeSettings::isGood()
{
    if (maxRow < rowLimit_min || maxCol < colLimit_min || maxRow > rowLimit_max ||
        maxCol > colLimit_max || gameSpeed > speedLimit_max || gameSpeed < speedLimit_min)
        return false;
    return 1;
}
