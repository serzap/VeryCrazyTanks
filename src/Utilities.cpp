#include "Utilities.h"
int getRandomNumber(int lower, int upper) {
	return lower + (rand() % (upper - lower + 1));
}

Direction getOppositeDirection(Direction dir)
{
	switch (dir) {
	case Direction::UP:
		return Direction::DOWN;
		break;
	case Direction::RIGHT:
		return Direction::LEFT;
		break;
	case Direction::DOWN:
		return Direction::UP;
		break;
	case Direction::LEFT:
		return Direction::RIGHT;
		break;
	default:
		return Direction::STOP;
	}
}

void getTime(int& seconds, int& minutes)
{
	minutes = seconds / 60;
	seconds = seconds % 60;
}
