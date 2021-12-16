#ifndef MAP_H
#define MAP_H
#include "config.h"

class Map
{
public:
    Map();
    QPixmap map_one;
    QPixmap map_two;

    int map_one_y;
    int map_two_y;

    void MapMove();

    int move_speed;

};

#endif // MAP_H
