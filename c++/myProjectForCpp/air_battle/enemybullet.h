#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "config.h"

class EnemyBullet
{
public:
    EnemyBullet();

    QPixmap enemybullet;

    void updatePosition();

    int m_x,m_y;
    int m_speed;
    bool m_Free;
    QRect m_Rect;
};

#endif // ENEMYBULLET_H
