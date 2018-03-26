#ifndef VERYCRAZYTANKS_DRAWING_STRATEGY_H
#define VERYCRAZYTANKS_DRAWING_STRATEGY_H

#include "Constants.h"
#include "Map.h"

class DrawingStrategy
{
public:
	virtual void execute(Map& map, int x, int y) = 0;
};

class BorderDrawingStrategy : public DrawingStrategy {
public:
	void execute(Map& map, int x, int y) override;
};

class WallDrawingStrategy : public DrawingStrategy {
public:
	void execute(Map& map, int x, int y) override;
};

class GoldDrawingStrategy : public DrawingStrategy {
public:
	void execute(Map& map, int x, int y) override;
};

class PlayerBulletDrawingStrategy : public DrawingStrategy {
public:
	void execute(Map& map, int x, int y) override;
};

class EnemyBulletDrawingStrategy : public DrawingStrategy {
public:
	void execute(Map& map, int x, int y) override;
};

class PlayerTankDrawingStrategy : public DrawingStrategy {
public:
	void execute(Map& map, int x, int y) override;
};

class EnemyTankDrawingStrategy : public DrawingStrategy {
public:
	void execute(Map& map, int x, int y) override;
};

#endif
