#ifndef VERYCRAZYTANKS_GAME_H
#define VERYCRAZYTANKS_GAME_H

#include <iomanip>
#include "BattleField.h"
class Game
{
public:
	Game();
	~Game();

	void run();
private:
	BattleField bf;
};

#endif

