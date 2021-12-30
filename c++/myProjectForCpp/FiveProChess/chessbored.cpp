#include "chessbored.h"
#include "ui_chessbored.h"

chessBored::chessBored(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chessBored)
{
    ui->setupUi(this);

    pressSound = new QSoundEffect;
    pressSound->setSource(QUrl::fromLocalFile(SOUND_PRESS));

    winSound = new QSoundEffect;
    winSound->setSource(QUrl::fromLocalFile(SOUND_WIN));

    initGameSence();

    connect(this->backMenu,&QPushButton::clicked,this,&chessBored::backMenuClicked);

//    connect(this,&chessBored::chessPress,this,&chessBored::chessPressDo);

    connect(reStart,&QPushButton::clicked,this,[=](){
        this->pause();
        this->initGameSence();
        this->update();
    });
}

chessBored::~chessBored()
{
    delete ui;
}

void chessBored::startGame(){
    this->timer.start();
    connect(&timer,&QTimer::timeout,[=](){
        this->update();
        if(timer.interval() != GAME_RATE) return;
        if(counts) counts--;
        QString num=QString::number(counts);
        ui->timeTack->setText(num);
    });
}

void chessBored::backMenuClicked()
{
    this->close();

    emit this->reStart->clicked();
    emit this->backToGameMenu();
}

void chessBored::chessPressDo(){
//    int x=dropI; int y=dropJ;
//    QPainter painter(this);
//    if(chessOnBored[x][y] == 1)
//        painter.drawPixmap( W + LW*y - whiteChess.getWidth()/2,
//                            W + LW*x - whiteChess.getHeight()/2,
//                            whiteChess.getWidth(),whiteChess.getHeight(),
//                            whiteChess.m_chess);
//    else if(chessOnBored[x][y] == -1)
//        painter.drawPixmap( W + LW*y - blackChess.getWidth()/2,
//                            W + LW*x - blackChess.getHeight()/2,
//                            blackChess.getWidth(),blackChess.getHeight(),
//                            blackChess.m_chess);
//    this->update();
}

void chessBored::pause(){
    int remaining = timer.interval()+1;
    timer.stop();
    timer.setInterval(remaining);
}

void chessBored::initGameSence(){
    this->setFixedHeight(GAME_HEIGHT);
    this->setFixedWidth(GAME_WIDTH);
    this->timer.setInterval(GAME_RATE/10);

    this->setWindowTitle(QString("五子棋对决"));
    this->setWindowIcon(QIcon(ICON_PATH));

    counts = 999;
    this->startGame();
    this->timer.setInterval(GAME_RATE);

    this->setMouseTracking(true);
    this->chessDropEnable = false;
    memset(chessOnBored,0,sizeof(chessOnBored));
    times = 0;

    W = GAME_BORED_WIDTH;LW = GAME_BORED_LINE_WIDTH;R=GAME_SCAN_RANGE;

    this->backMenu = new QPushButton("返回",this);
    backMenu->move(680,60);
    backMenu->resize(80,40);

    this->reStart = new QPushButton("重新开始",this);
    reStart->move(680,120);
    reStart->resize(80,40);

    this->gameModel = 1;

    this->PlayerOne = -1;
    this->PlayerTwo = 1;
}

int chessBored::max(int a, int b){
    return (a>b)?a:b;
}

int chessBored::min(int a, int b){
    return (a>b)?b:a;
}

void chessBored::paintEvent(QPaintEvent *){
    blackChess.setChessPic(BLACK_CHESS_PATH);
    whiteChess.setChessPic(WHITE_CHESS_PATH);
    virtualPoint.setChessPic(VIRTUAL_POINT_PATH);

    QPainter painter(this);

    bg.load(BACKGROUND_PATH);
    painter.drawPixmap(0,0,bg);
    painter.drawPixmap(295,0,bg);
    painter.drawPixmap(0,374,bg);
    painter.drawPixmap(295,374,bg);
    painter.drawPixmap(590,0,bg);
    painter.drawPixmap(590,374,bg);

    chessBoreds.load(CHESS_BORED_PATH);
    painter.drawPixmap(5,5 , chessBoreds);

    //painter.setBrush(Qt::yellow);
    painter.drawRect(W,W,15*LW,15*LW);

    painter.setBrush(Qt::black);
    for(int i = W;i<=W+15*LW;i+=LW){
        painter.drawLine(W,i,W+15*LW,i);
        painter.drawLine(i,W,i,W+15*LW);
    }

    for(int i = 0 ; i < 16 ; i ++)
        for(int j = 0 ; j < 16 ; j++){
            if(chessOnBored[i][j] == 1)
                painter.drawPixmap( W + LW*j - whiteChess.getWidth()/2,
                                    W + LW*i - whiteChess.getHeight()/2,
                                    whiteChess.getWidth(),whiteChess.getHeight(),
                                    whiteChess.m_chess);
            else if(chessOnBored[i][j] == -1)
                painter.drawPixmap( W + LW*j - blackChess.getWidth()/2,
                                    W + LW*i - blackChess.getHeight()/2,
                                    blackChess.getWidth(),blackChess.getHeight(),
                                    blackChess.m_chess);
        }
}

bool chessBored::isGameOver(int x,int y){
    //竖直
    int num = 1;
    for(int i=max(1,x-4);i<=min(15,x+5);i++){
        if(chessOnBored[i][y] == chessOnBored[i-1][y]&&chessOnBored[i-1][y]) num++;
        else num = 1;
        if(num >= 5) return true;
    }

    //水平
    num = 1;
    for(int j=max(1,y-4);j<=min(15,y+5);j++){
        if(chessOnBored[x][j] == chessOnBored[x][j-1]&&chessOnBored[x][j-1]) num++;
        else num = 1;
        if(num >= 5) return true;
    }

    //左斜
    int i = x, j = y;
    num = 5;
    while(i>=1&&j>=1&&num>1){i--;j--;num--;}
    num = 1;
    for(i,j;i<=min(15,x+5)&&j<=min(15,y+5);i++,j++){
        if(chessOnBored[i][j] == chessOnBored[i-1][j-1]&&chessOnBored[i-1][j-1]) num++;
        else num = 1;
        if(num >= 5) return true;
    }

    //右斜
    i = x;j = y;
    num = 5;
    while(i>=1&&j<=14&&num>1){i--;j++;num--;}
    num = 1;
    for(i,j;i<=min(15,x+5)&&j>=max(0,y-5);i++,j--){
        if(chessOnBored[i][j] == chessOnBored[i-1][j+1]&&chessOnBored[i-1][j+1]) num++;
        else num = 1;
        if(num >= 5) return true;
    }

    return false;
}

bool chessBored::isGameDead(){
    return times>CHESS_NUM;
}

void chessBored::mouseMoveEvent(QMouseEvent *e){
    if(!gameModel) return;
    if(e->x()<W-R||e->x()>W+15*LW+R||
       e->y()<W-R||e->y()>W+15*LW+R){
        this->chessDropEnable = false;
        //virtualPoint.chessHide();
        this->setCursor(Qt::ArrowCursor);
        return;
    }
    //qDebug()<<"virtual finding";
    dropJ = (e->x()-W)/LW;
    dropI = (e->y()-W)/LW;
    double check = LW*LW;
    for(int i = dropI ; i<dropI + 2 ; i++)
        for(int j = dropJ ; j<dropJ + 2 ; j++){
            if(i>15||j>15){
                //this->chessDropEnable = false;
                this->setCursor(Qt::ArrowCursor);
                //virtualPoint.chessHide();
                continue;
            }
            else{
                double t = (e->x()-(W+j*LW))*(e->x()-(W+j*LW))+
                             (e->y()-(W+i*LW))*(e->y()-(W+i*LW));
                if(check>=t){
                    check = t;
                    dropI = i;
                    dropJ = j;
                    this->chessDropEnable = true;
                }
            }
    }
    virtualPoint.chessMove(dropI,dropJ);
    this->setCursor(Qt::PointingHandCursor);
    //qDebug()<<"111";
    this->update();
}

void chessBored::mousePressEvent(QMouseEvent *e){
    if(!gameModel) return ;
    if(chessDropEnable == false) return ;

    if(isGameDead()||!counts){
        timer.stop();
        QMessageBox::information(this,"游戏结束","平局");
        return ;
    }

    if(e->button() == Qt::LeftButton){
        rightDropI = dropI;rightDropJ = dropJ;
        if(this->chessOnBored[rightDropI][rightDropJ] != 0) return;
        pressSound->play();
        if(times%2){
            times++;
            chessOnBored[rightDropI][rightDropJ] = 1;
//            emit chessPress();
            if(isGameOver(rightDropI,rightDropJ)){
                timer.stop();
                emit gameEnd(counts);
               winSound->play();
                QMessageBox::information(this,"游戏结束","白方胜利");
                gameModel = 0;
                //return ;
            }
        }else{
            if(this->chessOnBored[rightDropI][rightDropJ] != 0) return;
            pressSound->play();
                times++;
                chessOnBored[rightDropI][rightDropJ] = -1;
//                emit chessPress();
                if(isGameOver(rightDropI,rightDropJ)){
                    timer.stop();
                    qDebug()<<counts;
                    emit gameEnd(counts);
                    winSound->play();
                    QMessageBox::information(this,"游戏结束","黑方胜利");
                    gameModel = 0;
                    //return ;
                }
        }
        qDebug()<<rightDropI<<' '<<rightDropJ;
        update();
        robotChess();
    }update();
    //QTimer::singleShot(5,this,SLOT(robotChess()));
}

void chessBored::GameLevelDefine(QString *e){
    if(*e == "prim") this->GameLevel = 1;
    else if(*e == "midd") this->GameLevel = 2;
    else this->GameLevel = 3;
}

void chessBored::sleep_msec(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void chessBored::robotChess(){
    if(!gameModel) return;
    if(isGameDead()||!counts){
        timer.stop();
        emit gameEnd(counts);
        QMessageBox::information(this,"游戏结束","平局");
        return ;
    }
    cP t;
    t.x=rightDropI;t.y=rightDropJ;
    while(this->chessOnBored[t.x][t.y] != 0){
        if(GameLevel == 1) t = rob.getPointPrim(chessOnBored);
        else if(GameLevel == 2) t = rob.getPointMidd(chessOnBored);
        else t = rob.getPointProf(chessOnBored);
        rightDropI=t.x;rightDropJ=t.y;
    }rightDropI=t.x;rightDropJ=t.y;
    qDebug()<<rightDropI<<' '<<t.y;
    sleep_msec(500);
    pressSound->play();
    if(times%2){
        times++;
        chessOnBored[rightDropI][rightDropJ] = 1;
//        emit chessPress();
        if(isGameOver(rightDropI,rightDropJ)){
            timer.stop();
            QMessageBox::information(this,"游戏结束","白方胜利");
            gameModel = 0;
            return ;
        }
    }else{
        times++;
        chessOnBored[rightDropI][rightDropJ] = -1;
//        emit chessPress();
        if(isGameOver(rightDropI,rightDropJ)){
            timer.stop();
            QMessageBox::information(this,"游戏结束","黑方胜利");
            gameModel = 0;
            return ;
        }
    }update();
}
