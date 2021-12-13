#include "enemybullet.h"

EnemyBullet::EnemyBullet()
{
    enemybullet.load(ENEMY_BULLET_PATH);
    m_x=0;m_y=-GAME_HEIGHT;
    m_Free = true;
    m_speed = ENEMY_BULLET_MOVE_SPEED;

    m_Rect.setWidth(enemybullet.width());
    m_Rect.setHeight(enemybullet.height());
    m_Rect.moveTo(m_x,m_y);
}

void EnemyBullet::updatePosition(){
    if(m_Free) return ;
    m_y += m_speed;
    m_Rect.moveTo(m_x,m_y);

    if(m_y>m_Rect.height()+GAME_HEIGHT) m_Free = true;
}
