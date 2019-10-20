#ifndef SNAKEEMPTY_H
#define SNAKEEMPTY_H

#include <QLinkedList>
#include "SourceCode/SnakeGame/SnakeSettings.h"

class SnakeEmpty
{
public:
    struct Point
    {
        int row;
        int col;
        Point(int ROW, int COL):row(ROW), col(COL) {}
        bool operator==(const Point &OtherPoint)
        {
            return (OtherPoint.col == col && OtherPoint.row == row);
        }
        /*
        Point& operator=(const Point &Other)
        {
            if (this != &Other)
            {
                this->row = Other.row;
                this->col = Other.col;
            }
            return *this;
        }
        */
    };
    static QLinkedList<Point> emptyList;

    void static iniSnakeEmpty();

    //得到处在TARGET位置的Point
    Point static get(const int &TARGET);

    //SnakeEmpty(SnakeWall *WALL, SnakeFood *FOOD, SnakePlayer *PLAYER1, SnakePlayer *PLAYER2 = nullptr, SnakePlayer *PLAYER3 = nullptr);

};

#endif // SNAKEEMPTY_H
