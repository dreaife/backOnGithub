#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "map.h"
#include "airplane.h"
#include "bullet.h"
#include "enemy.h"
#include "bomb.h"
#include "enemybullet.h"
#include <QCoreApplication>
#include <QTime>
#include <ctime>
#include <QEventLoop>
#include <QSoundEffect>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void initSence();
    bool isOpen = false;

    QSoundEffect *bgm;
    QSoundEffect* boomMusic;

    QLabel *score;
    QLabel *stage;
    QLabel *stageInfo;
    int idxStage;
    int stageNum;
    int battleScore;
    int battleNum;
    void textUpdate();

    void stageUpdate();

    Map map;
    AirPlane air;

    void paintEvent(QPaintEvent *);
    void updatePosition();

    QTimer timer;
    //Bullet temp_Bullet;

    void startGame();
    void keyPressEvent(QKeyEvent* e);

    //enemy creat
    void enemyCome();
    Enemy enemys[ENEMY_NUM];
    int e_reco;

    void DashinDestory();

    //Bombs
    Bomb airBomb[BOMB_MAX];

    //fail
    void fail();
    void delay();
    bool check = 0;

signals:
    void failed();
    void succes();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
