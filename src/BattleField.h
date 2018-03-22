#ifndef VERYCRAZYTANKS_BATTLEFIELD_H
#define VERYCRAZYTANKS_BATTLEFIELD_H

#include <vector>
#include <ctime>
#include "Constants.h"
#include "Wall.h"
#include "Tank.h"


class BattleField {
public:
    BattleField();

    void generate();
    void handleInput();
    void handleCollisiion();
    void update();
    void draw();

private:
    static const int m_height = MAP_HEIGHT;
    static const int m_width = MAP_WIDTH;
    char m_gameMap[m_height][m_width];

    std::vector<Wall> m_walls;
    Tank m_player;
    int m_scorePoints;

    Direction m_currDir;
    Direction m_lastMoveDir;

    std::vector<Tank> m_enemies;
    int m_enemiesCnt;

    clock_t m_start;
    double m_duration;

    std::vector<Bullet> m_bullets;
    bool m_isOver;
    bool m_isVictory;

    void cleanMap();
};


#endif //VERYCRAZYTANKS_BATTLEFIELD_H
