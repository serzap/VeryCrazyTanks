#include "Wall.h"

Wall::Wall() = default;

Wall::Wall(int x, int y, int hp, char texture, int length, Position pos) :
        Entity(x, y, hp, texture), m_length, m_pos(pos) {

}
