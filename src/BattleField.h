#ifndef VERYCRAZYTANKS_BATTLEFIELD_H
#define VERYCRAZYTANKS_BATTLEFIELD_H

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "Wall.h"
#include "Tank.h"
#include "Constants.h"
#include "Utilities.h"


class BattleField {
public:
	BattleField();
	~BattleField();

	void generate();
	void handleInput();
	void handleCollision();
	void update();
	void draw();

	bool isOver();
	bool isVictory();

private:
	Map m_gameMap;

	Entity * m_player;
	Entity* m_gold;
	std::vector<Entity*> m_entities;

	Direction m_currDir;
	int m_scorePoints;
	int m_enemiesCnt;

	clock_t m_start;
	double m_duration;

	bool m_over;
	bool m_victory;
};


#endif //VERYCRAZYTANKS_BATTLEFIELD_H
