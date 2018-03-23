#ifndef VERYCRAZYTANKS_GOLD_H
#define VERYCRAZYTANKS_GOLD_H

#include "Entity.h"

class Gold : Entity {
public:
    Gold();
    Gold(int x, int y, int hp, char texture);

    std::vector<std::pair<int, int>> getBounds() override ;

    void draw(Map& map) override;
private:
    char m_texture;
};


#endif //VERYCRAZYTANKS_GOLD_H
