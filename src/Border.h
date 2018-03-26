#ifndef VERYCRAZYTANKS_BORDER_H
#define VERYCRAZYTANKS_BORDER_H

#include "Entity.h"
#include "Tank.h"
#include "Bullet.h"

class Entity;
class Bullet;
class Tank;

class Border : public Entity {
public:
	Border();
	Border(int x, int y, int hp, DrawingStrategy* ds);
	~Border();

	void getDamage() override;

	bool isDestroyed() override;

	void update() override;

	void collideWith(Entity& other) override;

};

#endif

