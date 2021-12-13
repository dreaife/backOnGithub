#include "map.h"

Map::Map()
{
    map_one.load(MAP_PATH);
    map_two.load(MAP_PATH);

    map_one_y=-GAME_HEIGHT;
    map_two_y=0;

    move_speed = MAP_MOVE_SPEED;
}

void Map::MapMove(){
    this->map_one_y+=move_speed;
    if(this->map_one_y>=0)
        this->map_one_y=-GAME_HEIGHT;
    this->map_two_y+=move_speed;
    if(this->map_two_y>=GAME_HEIGHT)
        this->map_two_y=0;
}
