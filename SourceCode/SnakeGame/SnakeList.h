#pragma once

#include "SourceCode/SnakeGame/SnakeEmpty.h"

//专供Snake游戏使用的结点，为双向的
//用于储存整个蛇的位置信息、食物的信息等等
class SnakeNode
{
public:       //公有数据类型
    enum Type //存储的信息类型
    {
        snake_wall, //0   蛇或墙壁
        apple,      //1   苹果
        watermelon, //2   西瓜
        straberry,  //3   草莓
        pineapple,  //4   菠萝
        trash,      //5   垃圾
        boomb,      //6   炸弹
        diminution, //7   缩小药水
        rebirth,    //8   重生药水
        growth,     //9   生长药水
        gain        //10  双倍积分
    };

public: //公有数据成员
    SnakeNode *next;
    SnakeNode *prev;
    int row;
    int column;
    Type nodeType;

public: //公有成员函数
    SnakeNode(int const &ROW, int const &COL, SnakeNode *PREV = nullptr, SnakeNode *NEXT = nullptr, Type const &TYPE = snake_wall) : next(NEXT), prev(PREV), row(ROW), column(COL), nodeType(TYPE)
    {
    }

    //取回当前结点的行、列值放入两个形参中
    void getPos(int &ROW, int &COLUMN) const
    {
        ROW = row;
        COLUMN = column;
    }

    Type getType() { return nodeType; }
};


class SnakeList
{
private: //私有数据成员
    int length;
    //SnakeEmpty empty;

protected://受保护的数据成员
    SnakeNode *head;
    SnakeNode *tail;

public: //构造&析构函数
    SnakeList();
    ~SnakeList();

public: //公有成员函数
    //获得链表的头结点
    SnakeNode *getHead();

    //获得链表的尾结点
    SnakeNode *getTail();

    //获得链表的长度信息
    int getLength();

    //表头插入一个结点
    void insert(int const &ROW, int const &COL, SnakeNode::Type const &TYPE = SnakeNode::snake_wall);

    //删除表尾结点
    void remove();

    //判断链表是否为空
    bool isEmpty() const;

    //删除某个特定节点
    void deleteNode(int const &Row, int const &Col);

    //寻找某结点是否出现于链表中
    SnakeNode *exist(int const &Row, int const &Col) const;

    //返回某结点的类型值，未找到则返回-1
    SnakeNode::Type getType(int const &Row, int const &Col);

    //清空链表
    void clear();
};
