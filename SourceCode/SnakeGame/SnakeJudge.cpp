#include "SourceCode/SnakeGame/SnakeJudge.h"

//判断该蛇下一个位置有没有撞墙，撞墙则返回true
bool SnakeJudge::hitWall(SnakePlayer *PLAYER, SnakeWall *WALL)
{
    int nextRow, nextCol;
    PLAYER->nextPos(nextRow, nextCol);
    return WALL->exist(nextRow, nextCol);
}

//判断该蛇下一个位置有没有撞到自己或者其他蛇
bool SnakeJudge::hitSnake(SnakePlayer *PLAYER_A, SnakePlayer *PLAYER_B, SnakePlayer *PLAYER_C)
{
    int nextRow, nextCol;
    PLAYER_A->nextPos(nextRow, nextCol);
    //如果蛇撞到自己，蛇死翘翘
    if (PLAYER_A->isSelfEating() == true)
        return true;
    //如果蛇没撞到，却撞到了其他蛇，蛇也死翘翘,debug: 解决多条蛇前往同一个位置的情况
    else {
        if (PLAYER_B != nullptr && PLAYER_B->isAlive())
        {
            if (PLAYER_B->isHitBody(nextRow, nextCol))
                return true;
            int BnextRow, BnextCol;
            PLAYER_B->nextPos(BnextRow, BnextCol);
            if (BnextRow == nextRow && BnextCol == nextCol)
                return true;
        }


        if (PLAYER_C != nullptr && PLAYER_C->isAlive())
        {
            if (PLAYER_C->isHitBody(nextRow, nextCol))
                return true;
            int CnextRow, CnextCol;
            PLAYER_C->nextPos(CnextRow, CnextCol);
            if (CnextRow == nextRow && CnextCol == nextCol)
                return true;
        }
    }
    return false;
}

//判断该蛇有没有吃到食物，吃到则进行相关操作，没吃到则正常前进
bool SnakeJudge::eatFood(SnakePlayer *PLAYER, SnakeFood *FOOD)
{
    int nextRow, nextCol;
    PLAYER->nextPos(nextRow, nextCol);
    if (FOOD->exist(nextRow, nextCol))
    {
        SnakeNode::Type foodType = FOOD->exist(nextRow, nextCol)->getType();
        FOOD->destroyFood(nextRow, nextCol);
        switch(foodType)
        {
        case    SnakeNode::watermelon:  PLAYER->gainScore(400);   [[clang::fallthrough]];
        case    SnakeNode::pineapple:   PLAYER->gainScore(300);   [[clang::fallthrough]];
        case    SnakeNode::straberry:   PLAYER->gainScore(200);   [[clang::fallthrough]];
        case    SnakeNode::apple:       PLAYER->gainScore(100);   PLAYER->snakeGrow();  SnakeSound::Food();     break;
        case    SnakeNode::trash:       PLAYER->gainScore(-1000); PLAYER->snakeMove();  SnakeSound::Poo();    break;
        case    SnakeNode::boomb:       PLAYER->gainScore(-1 * PLAYER->getScore());  PLAYER->snakeMove();   SnakeSound::Bomb();  break;
        case    SnakeNode::diminution:  PLAYER->snakeHalving();   PLAYER->snakeMove();  SnakeSound::Potion();   break;
        case    SnakeNode::rebirth:     PLAYER->snakeRebirth();   PLAYER->snakeMove();  SnakeSound::Potion();    break;
        case    SnakeNode::growth:      SnakePlayer::setGrowFlag(true);   PLAYER->snakeMove(); SnakeSound::Potion();  break;
        case    SnakeNode::gain:        PLAYER->doubleGain();     PLAYER->snakeMove();  SnakeSound::Potion();    break;
        default: throw "Error. Eating A Wrong Food Type.";
        }
        return true;
    }
    else
    {
        PLAYER->snakeMove();
        return false;
    }
}

//根据SnakeSettings更新食物信息
void SnakeJudge::updateFood(SnakeFood *FOOD)
{
    int foodLocationIdx, foodTypeIdx, foodCreateIdx, foodRow, foodCol;
    SnakeNode::Type foodType;

    //如果没有水果，还有剩余空间，生成水果，水果生成概率：分数越高越难生成
    if(SnakeEmpty::emptyList.isEmpty() == false && (FOOD->getNumOfFruit() < SnakePlayer::getNumOfAlivePlayers() || SnakePlayer::getGrowFlag()))
    {
        int foodNum;
        if (SnakePlayer::getGrowFlag())
            foodNum = 5;
        else
            foodNum = SnakePlayer::getNumOfAlivePlayers() - FOOD->getNumOfFruit();
        for (int i = 0; i < foodNum; i++)
        {
            if (SnakeEmpty::emptyList.isEmpty())
                break;
            qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
            foodLocationIdx = qrand() % SnakeEmpty::emptyList.count();
            qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
            foodTypeIdx= qrand() % 21;
            if (foodTypeIdx < 9)
                foodType = SnakeNode::apple;
            else if (foodTypeIdx < 15)
                foodType = SnakeNode::straberry;
            else if (foodTypeIdx < 19)
                foodType = SnakeNode::pineapple;
            else if (foodTypeIdx < 21)
                foodType = SnakeNode::watermelon;
            SnakeEmpty::Point pointTmp = SnakeEmpty::get(foodLocationIdx);
            foodRow = pointTmp.row;
            foodCol = pointTmp.col;
            FOOD->createFood(foodRow, foodCol, foodType);
        }
        SnakePlayer::setGrowFlag(false);
    }

    //如果生成垃圾且地图上没有垃圾，有2%几率生成垃圾，垃圾有12.5%可能是炸弹
    if(SnakeSettings::trash && SnakePlayer::getNumOfAlivePlayers() > FOOD->getNumOfTrash() && SnakeEmpty::emptyList.isEmpty() == false)
    {
        qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
        foodCreateIdx = qrand() % 50;
        if (foodCreateIdx < 1)
        {
            qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
            foodLocationIdx = qrand() % SnakeEmpty::emptyList.count();
            qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
            foodTypeIdx= qrand() % 8;
            if (foodTypeIdx < 1)
                foodType = SnakeNode::boomb;
            else if (foodTypeIdx < 8)
                foodType = SnakeNode::trash;
            SnakeEmpty::Point pointTmp = SnakeEmpty::get(foodLocationIdx);
            foodRow = pointTmp.row;
            foodCol = pointTmp.col;
            FOOD->createFood(foodRow, foodCol, foodType);
        }
    }

    //如果设置了生成药水，则有2%几率生成药水
    if (SnakeSettings::SuperPotion == true && SnakePlayer::getNumOfAlivePlayers() > FOOD->getNumOfPotion() && SnakeEmpty::emptyList.isEmpty() == false)
    {
        qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
        foodCreateIdx = qrand() % 50;
        if (foodCreateIdx > 1)
            return;
        qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
        foodLocationIdx = qrand() % SnakeEmpty::emptyList.count();
        qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
        foodTypeIdx= qrand() % 15;
        if (foodTypeIdx < 1)
            foodType = SnakeNode::rebirth;
        else if (foodTypeIdx < 4)
            foodType = SnakeNode::diminution;
        else if (foodTypeIdx < 8)
            foodType = SnakeNode::growth;
        else if (foodTypeIdx < 15)
            foodType = SnakeNode::gain;
        SnakeEmpty::Point pointTmp = SnakeEmpty::get(foodLocationIdx);
        foodRow = pointTmp.row;
        foodCol = pointTmp.col;
        FOOD->createFood(foodRow, foodCol, foodType);
    }
}

//如果开了harshTerrian（随机地形），有5%的可能性会随机生成一个墙壁
//debug：墙壁不会生成在蛇前进的地方
void SnakeJudge::updateWall(SnakeWall *WALL, SnakePlayer *PLAYER_A, SnakePlayer *PLAYER_B, SnakePlayer *PLAYER_C)
{
    if (SnakeSettings::harshTerrain == false || SnakeEmpty::emptyList.count() < 10)
        return;

    int A_nextCol, A_nextRow, B_nextCol = -1, B_nextRow = -1, C_nextCol = -1, C_nextRow = -1;
    int wallLocationIdx, wallCreateIdx, wallRow, wallCol;
    bool noBug = false;

    qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
    wallCreateIdx = qrand() % 20;
    if (wallCreateIdx > 0)
        return;

    switch (SnakeSettings::playerNum) {
    case SnakeSettings::triplePlayer:  PLAYER_C->nextPos(C_nextRow, C_nextCol); [[clang::fallthrough]];
    case SnakeSettings::doublePlayer:  PLAYER_B->nextPos(B_nextRow, B_nextCol); [[clang::fallthrough]];
    case SnakeSettings::singlePlayer:
    case SnakeSettings::autoPlay:      PLAYER_A->nextPos(A_nextRow, A_nextCol);
    }

    while (noBug == false)
    {
        qsrand(static_cast<unsigned>(QTime(0,0,0).msecsTo(QTime::currentTime())));
        wallLocationIdx = qrand() % SnakeEmpty::emptyList.count();
        SnakeEmpty::Point pointTmp = SnakeEmpty::get(wallLocationIdx);
        wallRow = pointTmp.row;
        wallCol = pointTmp.col;
        noBug = true;
        switch (SnakeSettings::playerNum) {
        case SnakeSettings::triplePlayer:  if (C_nextRow == wallRow && C_nextCol == wallCol) noBug = false; [[clang::fallthrough]];
        case SnakeSettings::doublePlayer:  if (B_nextRow == wallRow && B_nextCol == wallCol) noBug = false; [[clang::fallthrough]];
        case SnakeSettings::singlePlayer:
        case SnakeSettings::autoPlay:      if (A_nextRow == wallRow && A_nextCol == wallCol) noBug = false;
        }
    }
    WALL->createWall(wallRow, wallCol);
}

//输入游戏信息，进行游戏判断，若游戏在此过程中结束(蛇都死完了)，则返回false
bool SnakeJudge::judge(SnakeFood *FOOD, SnakeWall *WALL, SnakePlayer *PLAYER_A, SnakePlayer *PLAYER_B, SnakePlayer *PLAYER_C)
{
    bool isADead = !PLAYER_A->isAlive();
    bool isBDead = true;
    bool isCDead = true;
    if (PLAYER_B != nullptr)
        isBDead = !PLAYER_B->isAlive();
    if (PLAYER_C != nullptr)
        isCDead = !PLAYER_C->isAlive();

    //如果蛇撞墙、撞到自己、撞到其他人，则蛇死翘翘(已debug:多条蛇撞到一起的情况)
    switch (SnakeSettings::playerNum) {
    case SnakeSettings::triplePlayer:
        if(!isCDead)
            if (hitSnake(PLAYER_C, PLAYER_B, PLAYER_A) || hitWall(PLAYER_C, WALL))
                isCDead = true;
        [[clang::fallthrough]];
    case SnakeSettings::doublePlayer:
        if(!isBDead)
            if (hitSnake(PLAYER_B, PLAYER_C, PLAYER_A) || hitWall(PLAYER_B, WALL))
                isBDead = true;
        [[clang::fallthrough]];
    case SnakeSettings::singlePlayer:
    case SnakeSettings::autoPlay:
        if(!isADead)
            if (hitSnake(PLAYER_A, PLAYER_B, PLAYER_C) || hitWall(PLAYER_A, WALL))
                isADead = true;
    }

    //判断蛇有没有吃到食物，执行相关操作
    switch (SnakeSettings::playerNum) {
    case SnakeSettings::triplePlayer:  if(!isCDead) eatFood(PLAYER_C, FOOD); [[clang::fallthrough]];
    case SnakeSettings::doublePlayer:  if(!isBDead) eatFood(PLAYER_B, FOOD); [[clang::fallthrough]];
    case SnakeSettings::singlePlayer:
    case SnakeSettings::autoPlay:      if(!isADead) eatFood(PLAYER_A, FOOD);
    }

    //设置蛇是否死亡
    switch (SnakeSettings::playerNum) {
    case SnakeSettings::triplePlayer:  PLAYER_C->setAliveFlag(!isCDead);  [[clang::fallthrough]];
    case SnakeSettings::doublePlayer:  PLAYER_B->setAliveFlag(!isBDead);  [[clang::fallthrough]];
    case SnakeSettings::singlePlayer:
    case SnakeSettings::autoPlay:      PLAYER_A->setAliveFlag(!isADead);
    }

    //更新地图上的食物与墙壁
    updateFood(FOOD);
    updateWall(WALL, PLAYER_A, PLAYER_B, PLAYER_C);
    return SnakePlayer::getNumOfAlivePlayers();
}
