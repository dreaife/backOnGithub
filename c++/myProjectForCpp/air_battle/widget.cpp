#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->initSence();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::initSence(){
    srand((unsigned int)time(NULL));

    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowTitle(GAME_TITLE);
    this->setWindowIcon(QIcon(GAME_ICON));

    this->startGame();
    this->timer.setInterval(GAME_RATE);

    e_reco = 0;
}

void Widget::updatePosition(){
    map.MapMove();

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
    e_reco++;
    if(e_reco<ENEMY_INTERVAL) return ;

    e_reco = 0;

    for(int i=0;i<ENEMY_NUM;i++)
        if(enemys[i].e_free){
            enemys[i].e_free = false;
            enemys[i].e_x = rand()%(GAME_WIDTH-enemys[i].e_Rect.width());
            enemys[i].e_y = -enemys[i].e_Rect.height();
            break;
        }
}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,map.map_one_y,map.map_one);
    painter.drawPixmap(0,map.map_two_y,map.map_two);

    painter.drawPixmap(air.m_x,air.m_y,air.m_plane);

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
                enemys[i].e_free = true;
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
            }
        }
    }
}

void Widget::startGame(){
    this->timer.start();
    connect(&timer,&QTimer::timeout,[=](){
        this->enemyCome();
        this->updatePosition();
        this->update();
        this->DashinDestory();
    });
}

void Widget::keyPressEvent(QKeyEvent *e){
    int x=air.m_x;
    int y=air.m_y;
    if(e->key() == Qt::Key_Right)
        x+=AIR_MOVE_SPEED;
    else if(e->key() == Qt::Key_Left)
        x-=AIR_MOVE_SPEED;
    if(e->key() == Qt::Key_Up)
        y-=AIR_MOVE_SPEED;
    else if(e->key() == Qt::Key_Down)
        y+=AIR_MOVE_SPEED;
/*
    if(e->key() == Qt::Key_Escape)
        this->close();
    if(e->key() == Qt::Key_Enter){
        if(check){
            check = 0;
            this->initSence();
        }
    }
*/
    if(x<=0) x=0;
    if(x>=GAME_WIDTH-air.m_Rect.width()) x=GAME_WIDTH-air.m_Rect.width();

    if(y<=0) y=0;
    if(y>=GAME_HEIGHT-air.m_Rect.height()) y=GAME_HEIGHT-air.m_Rect.height();

    air.setPosition(x,y);
}

void Widget::fail(){
    //this->w->show();
    qDebug()<<"failed";
    emit failed();
    this->close();
}

void Widget::delay(){
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
