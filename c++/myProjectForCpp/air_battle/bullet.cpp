#include "bullet.h"

Bullet::Bullet()
{
    AirBullet.load(QString(BULLET_PATH).arg(8));
    m_x=GAME_WIDTH*0.5;m_y=GAME_HEIGHT*1.3;
    m_Free = true;
    m_speed = BULLET_MOVE_SPEED;

    m_Rect.setWidth(AirBullet.width());
    m_Rect.setHeight(AirBullet.height());
    m_Rect.moveTo(m_x,m_y);
}

void Bullet::updatePosition(){
    if(m_Free) return ;
    m_y -= m_speed;
    m_Rect.moveTo(m_x,m_y);

    if(m_y<=-m_Rect.height()) m_Free = true;
}
