#ifndef VERYCRAZYTANKS_CONSTANTS_H
#define VERYCRAZYTANKS_CONSTANTS_H

enum class Direction {
	STOP = 0, UP, RIGHT, DOWN, LEFT
};

enum class Type {
	PLAYER, ENEMY
};

namespace Constants {
	//Border
	const int BORDER_HP = 1;
	const int BORDER_TEXTURE = '#';
	//Map
	const int MAP_WIDTH = 80;
	const int MAP_HEIGHT = 40;
	const int WALL_COUNT = 20;
	const int ENEMIES_COUNT = 5;
	const int DISTANCE_BTW_ENTITIES = 3;
	//Player
	const int PLAYER_HP = 3;
	const int PLAYER_SPEED = 1;
	const int PLAYER_TEXTURE = 'X';
	//Enemy
	const int ENEMY_HP = 1;
	const int ENEMY_SPEED = 1;
	const int ENEMY_TEXTURE = '0';
	//Wall
	const int WALL_HP = 3;
	const char WALL_TEXTURE = 'W';
	//Bullet
	const int BULLET_SPEED = 1;
	const int BULLET_HP = 1;
	const char PLAYER_BULLET_TEXTURE = '*';
	const char ENEMY_BULLET_TEXTURE = '+';
	//Gold
	const int GOLD_HP = 1;
	const int GOLD_TEXTURE = 'G';
}

#endif //VERYCRAZYTANKS_CONSTANTS_H
