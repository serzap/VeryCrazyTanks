#ifndef VERYCRAZYTANKS_BATTLEFIELD_H
#define VERYCRAZYTANKS_BATTLEFIELD_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include "Wall.h"
#include "Tank.h"
#include "Constants.h"


class BattleField {
public:
    BattleField();

    void init();
    void generate();
    void handleInput();
    void handleCollisiion();
    void update();
    void draw();

private:
    Map m_gameMap;

    std::vector<Entity *> m_entities;


    int m_scorePoints;

    Direction m_currDir;
    Direction m_lastMoveDir;

    int m_enemiesCnt;
    clock_t m_start;
    double m_duration;
    bool m_isOver;
    bool m_isVictory;

    int getRandomNumber(int lower, int upper);

};


#endif //VERYCRAZYTANKS_BATTLEFIELD_H
