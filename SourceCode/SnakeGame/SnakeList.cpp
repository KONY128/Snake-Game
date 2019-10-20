#include "SourceCode/SnakeGame/SnakeList.h"

SnakeList::SnakeList()
{
    head = new SnakeNode(-1,-1);
    tail = new SnakeNode(-1,-1);
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
    length = 0;
}
SnakeList::~SnakeList()
{
    clear();
    delete head;
    delete tail;
}

//获得链表的长度信息
int SnakeList::getLength()
{
    return length;
}

//获得链表的头结点
SnakeNode *SnakeList::getHead()
{
    return head;
}

SnakeNode *SnakeList::getTail()
{
    return tail;
}

//表头插入一个结点
void SnakeList::insert(int const &ROW, int const &COL, SnakeNode::Type const &TYPE)
{
    SnakeEmpty::emptyList.removeAll(SnakeEmpty::Point(ROW, COL));
    SnakeEmpty::emptyList.removeOne(SnakeEmpty::Point(ROW, COL));
    SnakeNode *q = head->next;
    SnakeNode *p = new SnakeNode(ROW, COL, head, head->next, TYPE);
    q->prev = p;
    head->next = p;
    ++length;

}

//删除身表尾结点
void SnakeList::remove()
{

    if (length == 0)
        throw "Error. Removing a empty linked list.";
    SnakeNode *p = tail->prev, *q = p->prev;
    q->next = tail;
    tail->prev = q;
    int ROW, COL;
    p->getPos(ROW, COL);
    SnakeEmpty::emptyList << SnakeEmpty::Point(ROW, COL);
    delete p;

    --length;
}

//判断链表是否为空
bool SnakeList::isEmpty() const
{
    return (length == 0);
}

//删除某个特定节点
void SnakeList::deleteNode(int const &Row, int const &Col)
{
    if (length == 0 || exist(Row, Col) == nullptr)
        return;
    int curRow, curCol;
    SnakeNode *p = head, *q = p->next, *tmp;
    while (q != tail)
    {
        q->getPos(curRow, curCol);
        if (curRow == Row && curCol == Col)
        {
            tmp = q;
            q = q->next;
            p->next = q;
            q->prev = p;
            delete tmp;
            SnakeEmpty::emptyList << SnakeEmpty::Point(curRow, curCol);
            break;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    --length;
}

//寻找该结点是否出现于链表中
SnakeNode *SnakeList::exist(int const &Row, int const &Col) const
{
    if (length == 0)
        return nullptr;
    int curRow, curCol;
    SnakeNode *p = head->next;
    while (p != tail)
    {
        p->getPos(curRow, curCol);
        if (curRow == Row && curCol == Col)
            return p;
        p = p->next;
    }
    return nullptr;
}

//返回某结点的类型值
SnakeNode::Type SnakeList::getType(int const &Row, int const &Col)
{
    SnakeNode *cur = exist(Row, Col);
    if (cur == nullptr)
        throw "Error. Getting Type information of a empty place.";
    return cur->getType();
}

//清空链表
void SnakeList::clear()
{
    if (length == 0)
        return;
    while (length !=0)
        remove();
}
