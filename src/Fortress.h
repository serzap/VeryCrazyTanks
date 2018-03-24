#ifndef VERYCRAZYTANKS_FORTRESS_H
#define VERYCRAZYTANKS_FORTRESS_H

#include <vector>
#include "Wall.h"
#include "Gold.h"

class Fortress : public Entity {
public:
    Fortress();

    Fortress(int x, int y);

    void getDamage() override;

    bool isDestroyed() override;

    std::vector<std::pair<int, int>> getBounds() override;

    void update() override ;

    void draw(Map& map) override;
private:
    std::vector<Wall> walls;
    Gold* gold;
};


#endif //VERYCRAZYTANKS_FORTRESS_H
