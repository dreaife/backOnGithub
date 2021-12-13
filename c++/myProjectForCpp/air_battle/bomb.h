#ifndef BOMB_H
#define BOMB_H
#include <QVector>
#include "config.h"

class Bomb
{
public:
    Bomb();

    void updatePic();

    QVector<QPixmap> pixBomb;

    int b_x,b_y;

    bool b_free;

    int b_reco;

    int b_idx;
};

#endif // BOMB_H
