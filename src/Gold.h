#ifndef VERYCRAZYTANKS_GOLD_H
#define VERYCRAZYTANKS_GOLD_H

#include "Entity.h"
#include "Tank.h"
#include "Bullet.h"

class Entity;
class Bullet;
class Tank;

class Gold : public Entity {
public:
	Gold();
	Gold(int x, int y, int hp, DrawingStrategy* ds);

	void getDamage() override;

	bool isDestroyed() override;

	void update() override;

	void collideWith(Entity& other) override;
};

#endif //VERYCRAZYTANKS_GOLD_H
