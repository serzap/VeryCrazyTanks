#ifndef VERYCRAZYTANKS_WALL_H
#define VERYCRAZYTANKS_WALL_H

#include "Entity.h"
#include "Tank.h"
#include "Bullet.h"

class Entity;
class Bullet;
class Tank;

class Wall : public Entity {
public:
	Wall();
	Wall(int x, int y, int hp, DrawingStrategy* ds);

	void getDamage() override;

	bool isDestroyed() override;

	void update() override;

	void collideWith(Entity& other) override;

};

#endif //VERYCRAZYTANKS_WALL_H
