#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand((unsigned int)time(NULL));

    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowTitle(GAME_TITLE);
    this->setWindowIcon(QIcon(GAME_ICON));

    bgm = new QSoundEffect;
    bgm->setSource(QUrl::fromLocalFile(SOUND_BACKGROUND));

    boomMusic = new QSoundEffect;
    boomMusic->setSource(QUrl::fromLocalFile(SOUND_BOMB));

    stageNum = 1;
    stage = new QLabel(this);
    stage->setGeometry(0,0,200,40);

    score = new QLabel(this);
    score->setGeometry(GAME_WIDTH-100,0,200,70);

    idxStage = 0;
    stageInfo = new QLabel("<h1>Next Stage···</h1>",this);
    stageInfo->setGeometry(GAME_WIDTH/2-60,GAME_HEIGHT/2-150,200,60);
    stageInfo->setVisible(false);

    this->timer.setInterval(GAME_RATE);
    this->startGame();

    this->initSence();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::textUpdate(){
    stage->setText(QString("<h1>关卡:%1</h1>").arg(stageNum));
    score->setText(QString("<h2>得分:%1<br></br>击败数:%2</h2>").arg(battleScore).arg(battleNum));
}

void Widget::initSence(){
    battleNum = 0;
    battleScore = 0;

    for(int i=0;i<BULLET_NUM;i++)
        air.m_bullets[i].m_Free = true;

    for(int i=0;i<ENEMY_NUM;i++) if(!this->enemys[i].e_free){
        for(int j=0;j<ENEMY_BULLET_NUM;j++)
            this->enemys[i].m_bullets[j].m_Free = true;
        this->enemys[i].e_free = true;
        enemys[i].e_x = 0,enemys[i].e_y = -200;
    }

    air.m_x = 0.5*GAME_WIDTH-air.m_plane.width()*0.5;
    air.m_y = GAME_HEIGHT-air.m_plane.height() *0.5;

    e_reco = 0;
}

void Widget::updatePosition(){
    map.MapMove();

    if (!isOpen) return;

    //temp_Bullet.m_Free = false;
    //temp_Bullet.updatePosition();

    air.shoot();

    for(int i=0;i<BULLET_NUM;i++)
        if(!air.m_bullets[i].m_Free)
            air.m_bullets[i].updatePosition();

    for(int i=0;i<ENEMY_NUM;i++)
        if(!enemys[i].e_free){
            enemys[i].updateEnemy();
            if(enemys[i].e_y>=enemys[i].e_Rect.height()) enemys[i].shoot();
            for(int j=0;j<ENEMY_BULLET_NUM;j++)
                if(!enemys[i].m_bullets[j].m_Free)
                    enemys[i].m_bullets[j].updatePosition();
        }

    for(int i=0;i<BOMB_NUM;i++)
        if(!airBomb[i].b_free)
            airBomb[i].updatePic();
}

void Widget::enemyCome(){
    if (!isOpen) return;
    e_reco++;
    if(e_reco<ENEMY_INTERVAL) return ;

    e_reco = 0;

    for(int i=0;i<ENEMY_NUM;i++)
        if(enemys[i].e_free){
            enemys[i].e_free = false;
            enemys[i].e_x = rand()%(GAME_WIDTH-enemys[i].e_Rect.width());
            enemys[i].e_y = -enemys[i].e_Rect.height();
            for(int j=0;j<ENEMY_BULLET_NUM;j++) enemys[i].m_bullets[j].m_x=0,enemys[i].m_bullets[j].m_y=0;
            break;
        }
}

void Widget::stageUpdate(){
    stageNum++;

    if(stageNum>5) {
        this->close();
        this->isOpen = false;
        emit succes();
    }

    map.map_one.load(QString(MAP_PATH).arg(stageNum));
    map.map_two.load(QString(MAP_PATH).arg(stageNum));

    for(int i=0;i<BULLET_NUM;i++)
        air.m_bullets[i].AirBullet.load(QString(BULLET_PATH).arg(stageNum+7));
    for(int i=0;i<ENEMY_NUM;i++){
        enemys[i].enemy.load(QString(ENEMY_PATH).arg(stageNum));
        for(int j=0;j<ENEMY_BULLET_NUM;j++)
            enemys[i].m_bullets[j].enemybullet.load(QString(ENEMY_BULLET_PATH).arg(stageNum));
    }

    stageInfo->setVisible(true);

    initSence();
}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,map.map_one_y,map.map_one);
    painter.drawPixmap(0,map.map_two_y,map.map_two);

    painter.drawPixmap(air.m_x,air.m_y,air.m_plane);

    if (!isOpen) return;

    //painter.drawPixmap(temp_Bullet.m_x,temp_Bullet.m_y,temp_Bullet.AirBullet);

    for(int i=0;i<BULLET_NUM;i++)
        if(!air.m_bullets[i].m_Free)
            painter.drawPixmap(air.m_bullets[i].m_x,air.m_bullets[i].m_y,air.m_bullets[i].AirBullet);

    for(int i=0;i<ENEMY_NUM;i++)
        if(!enemys[i].e_free){
            painter.drawPixmap(enemys[i].e_x,enemys[i].e_y,enemys[i].enemy);
            for(int j=0;j<ENEMY_BULLET_NUM;j++)
                if(!enemys[i].m_bullets[j].m_Free)
                    painter.drawPixmap(enemys[i].m_bullets[j].m_x,enemys[i].m_bullets[j].m_y,enemys[i].m_bullets[j].enemybullet);
        }

    for(int i=0;i<BOMB_NUM;i++)
        if(!airBomb[i].b_free)
            painter.drawPixmap(airBomb[i].b_x,airBomb[i].b_y,airBomb[i].pixBomb[airBomb[i].b_idx]);

}

void Widget::DashinDestory(){
    if (!isOpen) return;
    for(int i=0;i<ENEMY_NUM;i++){
        if(enemys[i].e_free) continue;
        for(int j=0;j<ENEMY_BULLET_NUM;j++){
            if(enemys[i].m_bullets[j].m_Free) continue;
            if(air.m_Rect.intersects(enemys[i].m_bullets[j].m_Rect))
                this->fail();
        }
        for(int j=0;j<BULLET_NUM;j++){
            if(air.m_bullets[i].m_Free) continue;
            if(enemys[i].e_Rect.intersects(air.m_bullets[j].m_Rect)){
                boomMusic->play();
                enemys[i].e_free = true;
                battleNum++;
                battleScore += 100;
                for(int k = 0;k < ENEMY_BULLET_NUM;k++)
                    enemys[i].m_bullets[k].m_Free = true;
                air.m_bullets[j].m_Free = true;
                for(int k = 0;k < BOMB_NUM ; k++)
                    if(airBomb[k].b_free){
                        airBomb[k].b_free = false;

                        airBomb[k].b_x = enemys[i].e_x;
                        airBomb[k].b_y = enemys[i].e_y;
                        break;
                    }
                enemys[i].e_x = 0,enemys[i].e_y = -enemys[i].enemy.height();
            }
        }
    }
}

void Widget::startGame(){
    this->timer.start();
    connect(&timer,&QTimer::timeout,[=](){
        if(battleNum>30) this->stageUpdate();
        if(stageInfo->isVisible()){
            idxStage++;
            if(idxStage>100) stageInfo->setVisible(false);
        }
        this->textUpdate();
        this->enemyCome();
        this->updatePosition();
        this->DashinDestory();
        this->update();
    });
}

void Widget::keyPressEvent(QKeyEvent *e){
    if (!isOpen) return;
    if(e->key() == Qt::Key_Escape) this->close();
    int x=air.m_x;
    int y=air.m_y;
    if(e->key() == Qt::Key_Right||e->key() == Qt::Key_D)
        x+=AIR_MOVE_SPEED;
    else if(e->key() == Qt::Key_Left||e->key() == Qt::Key_A)
        x-=AIR_MOVE_SPEED;
    if(e->key() == Qt::Key_Up||e->key() == Qt::Key_W)
        y-=AIR_MOVE_SPEED;
    else if(e->key() == Qt::Key_Down||e->key() == Qt::Key_S)
        y+=AIR_MOVE_SPEED;

//    if(e->key() == Qt::Key_Escape)
//        this->close();
//    if(e->key() == Qt::Key_Enter){
//        if(check){
//            check = 0;
//            this->initSence();
//        }
//    }

    if(x<=0) x=0;
    if(x>=GAME_WIDTH-air.m_Rect.width()) x=GAME_WIDTH-air.m_Rect.width();

    if(y<=0) y=0;
    if(y>=GAME_HEIGHT-air.m_Rect.height()) y=GAME_HEIGHT-air.m_Rect.height();

    air.setPosition(x,y);
}

void Widget::fail(){
    if (!isOpen) return;
    //this->w->show();
    qDebug()<<"failed";
    emit failed();
    this->isOpen = false;
    this->close();
}

void Widget::delay(){
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
