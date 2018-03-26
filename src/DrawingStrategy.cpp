#include "DrawingStrategy.h"

void BorderDrawingStrategy::execute(Map & map, int x, int y)
{
	map[y][x] = Constants::BORDER_TEXTURE;
}

void WallDrawingStrategy::execute(Map & map, int x, int y)
{
	map[y][x] = Constants::WALL_TEXTURE;
}

void GoldDrawingStrategy::execute(Map & map, int x, int y)
{
	map[y][x] = Constants::GOLD_TEXTURE;
}

void PlayerBulletDrawingStrategy::execute(Map & map, int x, int y)
{
	map[y][x] = Constants::PLAYER_BULLET_TEXTURE;
}

void EnemyBulletDrawingStrategy::execute(Map & map, int x, int y)
{
	map[y][x] = Constants::ENEMY_BULLET_TEXTURE;
}

void PlayerTankDrawingStrategy::execute(Map & map, int x, int y)
{
	map[y][x] = Constants::PLAYER_TEXTURE;
}

void EnemyTankDrawingStrategy::execute(Map & map, int x, int y)
{
	map[y][x] = Constants::ENEMY_TEXTURE;
}
