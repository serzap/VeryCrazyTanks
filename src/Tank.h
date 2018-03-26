#ifndef VERYCRAZYTANKS_TANK_H
#define VERYCRAZYTANKS_TANK_H

#include "Utilities.h"
#include "Entity.h"
#include "Border.h"
#include "Wall.h"
#include "Gold.h"
#include "Bullet.h"

class Border;
class Wall;
class Gold;
class Bullet;

class Tank : public Entity {
public:
	Tank();

	Tank(int x, int y, int hp, DrawingStrategy* ds, int speed, Direction dir, Type type);

	inline const Direction &getDirection() const { return m_dir; }

	inline void setDirection(const Direction &dir) { m_dir = dir; }

	inline const Type &getType() const { return m_type; }

	inline void setType(const Type& type) { m_type = type; }

	void getDamage() override;

	bool isDestroyed() override;

	void update() override;

	void collideWith(Entity& other) override;

private:
	int m_speed;
	Direction m_dir;
	Type m_type;
};


#endif //VERYCRAZYTANKS_TANK_H
