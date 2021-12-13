#ifndef BULLET_H
#define BULLET_H
#include "config.h"

class Bullet
{
public:
    Bullet();

    QPixmap AirBullet;

    void updatePosition();

    int m_x,m_y;
    int m_speed;
    bool m_Free;
    QRect m_Rect;
};

#endif // BULLET_H
