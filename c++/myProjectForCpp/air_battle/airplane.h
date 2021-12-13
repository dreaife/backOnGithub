#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "config.h"
#include "bullet.h"

class AirPlane
{
public:
    AirPlane();

    void shoot();
    void setPosition(int x,int y);

    QPixmap m_plane;

    int m_x,m_y;

    QRect m_Rect;

    Bullet m_bullets[BULLET_NUM];
    int m_recorder;
};

#endif // AIRPLANE_H
