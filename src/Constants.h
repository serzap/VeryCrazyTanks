#ifndef VERYCRAZYTANKS_CONSTANTS_H
#define VERYCRAZYTANKS_CONSTANTS_H

enum class Direction {STOP = 0, UP, RIGHT, DOWN, LEFT};
enum class Type {PLAYER, ENEMY};
enum class Position {HORIZONTAL, VERTICAL};

//Bullet
char BULLET_TEXTURE = '*';
int BULLET_SPEED = 1;
int BULLET_HP = 1;

//BattleField
int MAP_WIDTH = 100;
int MAP_HEIGHT = 100;

#endif //VERYCRAZYTANKS_CONSTANTS_H
