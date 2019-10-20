#include "SourceCode/SnakeGame/SnakeEmpty.h"

QLinkedList<SnakeEmpty::Point> SnakeEmpty::emptyList;

void SnakeEmpty::iniSnakeEmpty()
{
    emptyList.clear();
    for (int i = 0; i < SnakeSettings::maxRow; ++i)
    {
        for (int j = 0; j < SnakeSettings::maxCol; ++j)
        {
            emptyList << Point(i, j);
        }
    }
}

//得到处在TARGET位置的Point
SnakeEmpty::Point SnakeEmpty::get(const int &TARGET)
{
    QLinkedList<Point>::iterator iter = emptyList.begin();
    for (int i = 0; i < TARGET; i++)
        iter++;
    //Point tmp((*iter).row, (*iter).col);
    return *iter;
}
