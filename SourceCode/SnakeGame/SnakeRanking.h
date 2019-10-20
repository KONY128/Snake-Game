#ifndef SNAKERANKING_H
#define SNAKERANKING_H
#include <QFile>
#include <QList>
#include <QTextStream>

struct RankingInf
{
    void InputInf(const QString &Name, const int &Score)
    {
        name = Name;
        score = Score;
    }
    void OutputInf(QString &Name, int &Score)
    {
        Name = name;
        Score = score;
    }
    //用于升序排列排行榜
    bool operator<(const RankingInf &Other)
    {
        return this->score > Other.score;
    }
    QString name;
    int score;
};

class SnakeRanking
{
public:
    SnakeRanking();
    ~SnakeRanking();

    //将本地Ranking文件取入内存
    bool LoadRanking();

    //将内存Ranking文件存入本地文件
    bool SaveRanking();

    //新增一份排名记录
    bool AddRanking(const QString &Name, const int &Score);

    //将raningList里的排名进行排行，保证其长度小于特定值
    void SortRanking();

    QList<RankingInf> rankingList;

private:
    //rankingList最大长度限制
    static const int lengthLimit;
};

#endif // SNAKERANKING_H
