#include "SnakeRanking.h"
const int SnakeRanking::lengthLimit = 9;    //rankingList最大长度限制

SnakeRanking::SnakeRanking()
{
    LoadRanking();
}

SnakeRanking::~SnakeRanking()
{
    SaveRanking();
}

bool SnakeRanking::LoadRanking()
{
    QFile file(QStringLiteral("./Ranking/Ranking.txt"));

    if (!file.open(QIODevice::ReadOnly))
        return false;
    else
    {
        QTextStream in(&file);
        QString name;
        QString score_string;
        int score_int;
        RankingInf tmpInf;
        while (!in.atEnd())
        {
            name = in.readLine();
            score_string = in.readLine();
            score_int = score_string.toInt();
            tmpInf.InputInf(name, score_int);
            rankingList.append(tmpInf);
        }
        file.close();
        return true;
    }
}

bool SnakeRanking::SaveRanking()
{
    SortRanking(); //保存前先排序凌乱的rankingList
    QFile file(QStringLiteral("./Ranking/Ranking.txt"));
    if (!file.open(QIODevice::WriteOnly))
        return false;
    else
    {
        int saveLimit = lengthLimit;
        QTextStream out(&file);
        QString name;
        int score;
        RankingInf tmpInf;
        auto iter = rankingList.begin();
        while (iter != rankingList.end() && saveLimit > 0)
        {
            tmpInf = *iter;
            tmpInf.OutputInf(name, score);
            out << name << endl << score << endl;
            --saveLimit;
            iter++;
        }
        file.close();
        return true;
    }
}

bool SnakeRanking::AddRanking(const QString &Name, const int &Score)
{
    if (Name == QString("") || Score == int())
        return false;
    RankingInf tmpInf;
    tmpInf.InputInf(Name, Score);
    rankingList.append(tmpInf);
    return true;
}

void SnakeRanking::SortRanking()
{
    std::sort(rankingList.begin(), rankingList.end());
    while(rankingList.count() > lengthLimit)
        rankingList.pop_back();
}
