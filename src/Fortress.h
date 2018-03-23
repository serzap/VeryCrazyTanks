#ifndef VERYCRAZYTANKS_FORTRESS_H
#define VERYCRAZYTANKS_FORTRESS_H

#include <vector>
#include "Wall.h"
#include "Gold.h"

class Fortress {
public:
    Fortress();
private:
    std::vector<Wall> walls;
    Gold gold;
};


#endif //VERYCRAZYTANKS_FORTRESS_H
