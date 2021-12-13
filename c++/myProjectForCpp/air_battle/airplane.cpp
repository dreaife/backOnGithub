#include "airplane.h"

AirPlane::AirPlane()
{
    m_plane.load(AIR_PATH);

    m_x=0.5*GAME_WIDTH-m_plane.width()*0.5;
    m_y=GAME_HEIGHT-m_plane.height();

    m_Rect.setWidth(m_plane.width());
    m_Rect.setHeight(m_plane.height());
    m_Rect.moveTo(m_x,m_y);

    m_recorder = 0;
}

void AirPlane::setPosition(int x, int y){
    m_x = x;
    m_y = y;

    m_Rect.moveTo(m_x,m_y);
}

void AirPlane::shoot(){
    m_recorder++;
    if(m_recorder<BULLET_INTERVAL) return ;
    m_recorder = 0;

    for(int i=0;i<BULLET_NUM;i++){
        if(m_bullets[i].m_Free){
            m_bullets[i].m_Free = false;

            m_bullets[i].m_x = m_x+m_Rect.width()*0.5-10;
            m_bullets[i].m_y = m_y-25;
            break;
        }
    }
}
