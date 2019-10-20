#include "SourceCode/SnakeGame/SnakeRenderer.h"
SnakeRenderer::SnakeRenderer(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle(QStringLiteral("Snake Game"));
    //SnakeRender类变量初始化
    m_timerId = startTimer(SnakeSettings::gameSpeed);
    gameFlag = false;
    gameOverFlashFlag = false;
    newInput_player1 = false;
    newInput_player2 = false;
    newInput_player3 = false;
    player2 = nullptr;
    player3 = nullptr;
}

SnakeRenderer::~SnakeRenderer()
{
    endGame();
}

void SnakeRenderer::startGame()
{
    iniGame();
    gameFlag = true;
    SnakeSound::GameStart();
}

void SnakeRenderer::timerEvent(QTimerEvent *event)
{
    //TimerEvent在到达每个Timer的周期时执行
    //用if语句确认这个Timer事件是我们指定的更新贪吃蛇游戏事件
    //当游戏已经开始且游戏focousIn时渲染，若游戏已经结束，则不再渲染
    if (event->timerId() == m_timerId &&  focusFlag == true && gameFlag == true)
    {
        //初始化newInput变量
        newInput_player1 = false;
        newInput_player2 = false;
        newInput_player3 = false;
        //如果是AutoMode，需要蛇自己判断往哪走,自动往输入栈里添东西
        SnakeJudge::judge(foods, walls, player1, player2, player3);
        if (SnakeSettings::playerNum ==  SnakeSettings::autoPlay)
            SnakeAuto::AutoJudge(player1, foods, walls);

        //以下情况时游戏结束：
        //无路可走：画面已被除食物以外的方块填充满(解决了游戏到最后吃不到食物直接结束的bug)
        //全员终结：剩余玩家数 = 0
        if (SnakeEmpty::emptyList.count() + foods->getLength() == 0  || SnakePlayer::getNumOfAlivePlayers() == 0)
            endGame();
        QWidget::update();
    }
}

void SnakeRenderer::keyPressEvent(QKeyEvent *event)
{
    if (gameFlag == false)
        return;
    switch (SnakeSettings::playerNum)
    {
    case SnakeSettings::autoPlay: break;
    case SnakeSettings::triplePlayer:
        if (event->key() == Qt::Key_I || event->key() == Qt::Key_J ||
                event->key() == Qt::Key_K || event->key() == Qt::Key_L)
        {
            //若本渲染周期内没接受指令，则设置newInput为true
            if (newInput_player3 == false)
            {
                newInput_player3 = true;
                player3->setNewInputFlag(true);
            }
            //判断是哪个键，添加入玩家指令中
            switch(event->key())
            {
            case Qt::Key_J: player3->setDestination(SnakePlayer::left); break;
            case Qt::Key_K: player3->setDestination(SnakePlayer::down);break;
            case Qt::Key_I: player3->setDestination(SnakePlayer::up);break;
            case Qt::Key_L: player3->setDestination(SnakePlayer::right);break;
            }
        }
        [[clang::fallthrough]];
    case SnakeSettings::doublePlayer:
        if (event->key() == Qt::Key_W || event->key() == Qt::Key_A ||
                event->key() == Qt::Key_S || event->key() == Qt::Key_D)
        {
            if (newInput_player2 == false)
            {
                newInput_player2 = true;
                player2->setNewInputFlag(true);
            }
            switch(event->key())
            {
            case Qt::Key_A: player2->setDestination(SnakePlayer::left); break;
            case Qt::Key_S: player2->setDestination(SnakePlayer::down);break;
            case Qt::Key_W: player2->setDestination(SnakePlayer::up);break;
            case Qt::Key_D: player2->setDestination(SnakePlayer::right);break;
            }
        }
        [[clang::fallthrough]];
    case SnakeSettings::singlePlayer:
        if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
                event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
        {
            if (newInput_player1 == false)
            {
                newInput_player1 = true;
                player1->setNewInputFlag(true);
            }
            switch(event->key())
            {
            case Qt::Key_Left:  player1->setDestination(SnakePlayer::left); break;
            case Qt::Key_Down:  player1->setDestination(SnakePlayer::down);break;
            case Qt::Key_Up:    player1->setDestination(SnakePlayer::up);break;
            case Qt::Key_Right: player1->setDestination(SnakePlayer::right);break;
            }
        }
    }
}

void SnakeRenderer::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    if(gameFlag == true)
    {
        //QColor snakeHeadColor(220, 220, 220);
        QColor snakeColor1(225, 249, 225);
        QColor snakeColor2(255, 234, 240);
        QColor snakeColor3(245, 252, 190);
        QColor wallColor(240, 240, 240);
        //也可以写成QImage snakeHeadImg1("./Images/Snake/SnakeHead_1");
        QImage snakeHeadImg1(":/Image/snake/player1");
        QImage snakeHeadImg2(":/Image/snake/player2");
        QImage snakeHeadImg3(":/Image/snake/player3");
        QImage watermelonImg(":/Image/food/watermelon");
        QImage strawberryImg(":/Image/food/strawberry");
        QImage pineappleImg(":/Image/food/pineapple");
        QImage appleImg(":/Image/food/apple");
        QImage bombImg(":/Image/food/bomb");
        QImage trashImg(":/Image/food/poo");
        QImage greenPotionImg(":/Image/food/greenPotion");
        QImage redPotionImg(":/Image/food/redPotion");
        QImage purplePotionImg(":/Image/food/purplePotion");
        QImage goldenPotionImg(":/Image/food/goldenPotion");
        //填充背景颜色为白色
        painter.fillRect(0, 0, this->width(), this->height(), Qt::white);
        //将地图大小与坐标系初始化
        double scaleWidth = SnakeSettings::maxCol, scaleHeight = SnakeSettings::maxRow;
        painter.scale(width() / scaleWidth, height() / scaleHeight);
        painter.setPen(Qt::NoPen);
        //绘画贪吃蛇界面
        SnakeNode *curNode;
        int rowPos, colPos;

        //画墙
        curNode = walls->getHead()->next;
        while (curNode != walls->getTail())
        {
            curNode->getPos(rowPos, colPos);
            painter.fillRect(colPos, rowPos, 1, 1, wallColor);
            curNode = curNode->next;
        }

        //画玩家
        if (player1 != nullptr && player1->isAlive())
        {
            //画蛇头
            curNode = player1->getHead()->next;
            curNode->getPos(rowPos, colPos);
            painter.fillRect(colPos, rowPos, 1, 1, snakeColor1);
            painter.drawImage(QRectF(colPos, rowPos, 1, 1), snakeHeadImg1);
            //画蛇身
            curNode = curNode->next;
            while (curNode != player1->getTail())
            {
                curNode->getPos(rowPos, colPos);
                painter.fillRect(colPos, rowPos, 1, 1, snakeColor1);
                curNode = curNode->next;
            }
        }
        if (player2 != nullptr && player2->isAlive())
        {
            curNode = player2->getHead()->next;
            curNode->getPos(rowPos, colPos);
            painter.fillRect(colPos, rowPos, 1, 1, snakeColor2);
            painter.drawImage(QRectF(colPos, rowPos, 1, 1), snakeHeadImg2);
            curNode = curNode->next;
            while (curNode != player2->getTail())
            {
                curNode->getPos(rowPos, colPos);
                painter.fillRect(colPos, rowPos, 1, 1, snakeColor2);
                curNode = curNode->next;
            }
        }

        if (player3 != nullptr && player3->isAlive())
        {
            curNode = player3->getHead()->next;
            curNode->getPos(rowPos, colPos);
            painter.fillRect(colPos, rowPos, 1, 1, snakeColor3);
            painter.drawImage(QRectF(colPos, rowPos, 1, 1), snakeHeadImg3);
            curNode = curNode->next;
            while (curNode != player3->getTail())
            {
                curNode->getPos(rowPos, colPos);
                painter.fillRect(colPos, rowPos, 1, 1, snakeColor3);
                curNode = curNode->next;
            }
        }

        //画食物
        curNode = foods->getHead()->next;
        while (curNode != foods->getTail())
        {
            curNode->getPos(rowPos, colPos);
            SnakeNode::Type foodType = curNode->getType();
            switch (foodType) {
            case    SnakeNode::watermelon:  painter.drawImage(QRectF(colPos, rowPos, 1, 1), watermelonImg); break;
            case    SnakeNode::pineapple:   painter.drawImage(QRectF(colPos, rowPos, 1, 1), pineappleImg); break;
            case    SnakeNode::straberry:   painter.drawImage(QRectF(colPos, rowPos, 1, 1), strawberryImg); break;
            case    SnakeNode::apple:       painter.drawImage(QRectF(colPos, rowPos, 1, 1), appleImg); break;
            case    SnakeNode::trash:       painter.drawImage(QRectF(colPos, rowPos, 1, 1), trashImg); break;
            case    SnakeNode::boomb:       painter.drawImage(QRectF(colPos, rowPos, 1, 1), bombImg); break;
            case    SnakeNode::diminution:  painter.drawImage(QRectF(colPos, rowPos, 1, 1), redPotionImg); break;
            case    SnakeNode::rebirth:     painter.drawImage(QRectF(colPos, rowPos, 1, 1), purplePotionImg); break;
            case    SnakeNode::growth:      painter.drawImage(QRectF(colPos, rowPos, 1, 1), greenPotionImg); break;
            case    SnakeNode::gain:        painter.drawImage(QRectF(colPos, rowPos, 1, 1), goldenPotionImg); break;
            case    SnakeNode::snake_wall:  throw "Error. Rendering A Wrong Food Type.";
            }
            curNode = curNode->next;
        }
    }
    else
    {
        painter.fillRect(0, 0, width(), height(), QGradient::SeaLord);

        if (gameOverFlashFlag == true)
        {
            QFont font;
            //设置字体大小和字符间距
            font.setPointSize(22);
            font.setLetterSpacing(QFont::AbsoluteSpacing, 3);
            painter.setFont(font);
            painter.setPen(Qt::white);
            painter.drawText(QRectF(0, 0, width(), height()), Qt::AlignCenter, QStringLiteral("GAME OVER"));
            gameOverFlashFlag = false;
        }
        else
        {
            gameOverFlashFlag = true;
        }
    }
    painter.end();
}

void SnakeRenderer::focusInEvent(QFocusEvent *event)
{
    QWidget::focusInEvent(event);
    focusFlag = true;
}

void SnakeRenderer::focusOutEvent(QFocusEvent *event)
{
    QWidget::focusOutEvent(event);
    focusFlag = false;
}

//初始化游戏内容
void SnakeRenderer::iniGame()
{
    this->resize(20 * SnakeSettings::maxCol, 20 * SnakeSettings::maxRow);
    SnakeEmpty::iniSnakeEmpty();

    //玩家一二三的初始位置分别为(3, 3), (5, 3), (7, 3)
    switch (SnakeSettings::playerNum) {
    case SnakeSettings::triplePlayer: player3 = new SnakePlayer; player3->iniPlayer(7, 3, SnakePlayer::right); [[clang::fallthrough]];
    case SnakeSettings::doublePlayer: player2 = new SnakePlayer; player2->iniPlayer(5, 3, SnakePlayer::right); [[clang::fallthrough]];
    case SnakeSettings::singlePlayer:
    case SnakeSettings::autoPlay:     player1 = new SnakePlayer; break;
    }
    walls = new SnakeWall();
    foods = new SnakeFood();
}

//游戏结束了
void SnakeRenderer::endGame()
{
    gameFlag = false;
    int highestScore = -100000;
    int highestId = 1;
    switch (SnakeSettings::playerNum) {
    case SnakeSettings::triplePlayer: if (player3->getScore() > highestScore) {highestScore = player3->getScore(); highestId = 3;} [[clang::fallthrough]];
    case SnakeSettings::doublePlayer: if (player2->getScore() > highestScore) {highestScore = player2->getScore(); highestId = 2;} [[clang::fallthrough]];
    case SnakeSettings::singlePlayer:
    case SnakeSettings::autoPlay: if (player1->getScore() > highestScore) {highestScore = player1->getScore(); highestId = 1;} break;
    }
    emit saveGameData(highestScore, highestId);
    clearGame();
    QWidget::update();
    emit gameOver();
}

//强行退出游戏（不保存）
void SnakeRenderer::exitGame()
{
    gameFlag = false;
    clearGame();
}

//清除游戏内容
void SnakeRenderer::clearGame()
{
    delete player1;
    delete player2;
    delete player3;
    delete walls;
    delete foods;
}
