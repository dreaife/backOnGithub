#include "enemy.h"

Enemy::Enemy()
{
    srand((unsigned int)time(NULL));
    enemy.load(QString(ENEMY_PATH).arg(1));

    e_x = 0;
    e_y = 0;

    e_free = true;

    e_speed = ENEMY_MOVE_SPEED;

    e_Rect.setWidth(enemy.width());
    e_Rect.setHeight(enemy.height());
    e_Rect.moveTo(e_x,e_y);

    m_recorder = 0;
}

void Enemy::updateEnemy(){
    if(e_free) return ;
    e_y+=e_speed;
    e_Rect.moveTo(e_x,e_y);

    if(e_y>=GAME_HEIGHT) e_free = true;
}

void Enemy::shoot(){
    m_recorder++;
    if(m_recorder<ENEMY_BULLET_INTERVAL) return ;
    m_recorder = 0;

    for(int i=0;i<ENEMY_BULLET_NUM;i++){
        if(m_bullets[i].m_Free){
            m_bullets[i].m_Free = false;

            m_bullets[i].m_x = e_x+e_Rect.width()*0.5-10;
            m_bullets[i].m_y = e_y-25;
            break;
        }
    }
}
