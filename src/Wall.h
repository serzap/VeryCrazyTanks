#ifndef VERYCRAZYTANKS_WALL_H
#define VERYCRAZYTANKS_WALL_H


#include "Constants.h"
#include "Entity.h"

class Wall : public Entity {
public:
    Wall();
    Wall(int x, int y, int hp, char texture, int length, Position pos);
private:
    int m_length;
    Position m_pos;
};


#endif //VERYCRAZYTANKS_WALL_H
