#ifndef VERYCRAZYTANKS_WALL_H
#define VERYCRAZYTANKS_WALL_H

#include "Entity.h"

class Wall : public Entity {
public:
    Wall();
    Wall(int x, int y, int hp, char texture, int length, Position pos);

    std::vector<std::pair<int, int>> getBounds() override ;

    void draw(Map& map) override;
private:
    char m_texture;
    int m_length;
    Position m_pos;
};


#endif //VERYCRAZYTANKS_WALL_H
