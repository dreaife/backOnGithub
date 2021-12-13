#include "bomb.h"
#include <QString>

Bomb::Bomb()
{
    for(int i=1;i<=BOMB_NUM;i++){
        QString str = QString(BOMB_PATH).arg(i);
        this->pixBomb.push_back(QPixmap(str));
    }

    b_x = 0;
    b_y = 0;

    b_free = true;

    b_idx = 0;
    b_reco = 0;
}

void Bomb::updatePic(){
    if(b_free) return;

    b_reco++;
    if(b_reco<BOMB_INTERVAL) return ;

    b_reco = 0;
    b_idx++;

    if(b_idx>BOMB_MAX - 1){
        b_idx=0;
        b_free = true;
    }
}
