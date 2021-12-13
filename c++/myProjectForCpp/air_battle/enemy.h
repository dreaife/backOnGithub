#ifndef ENEMY_H
#define ENEMY_H
#include "config.h"
#include "enemybullet.h"

class Enemy
{
public:
    Enemy();

    QPixmap enemy;

    int e_x,e_y;

    void updateEnemy();

    QRect e_Rect;

    bool e_free;

    int e_speed;

    EnemyBullet m_bullets[BULLET_NUM];
    int m_recorder;
    void shoot();

};

#endif // ENEMY_H
