#ifndef VERYCRAZYTANKS_BULLET_H
#define VERYCRAZYTANKS_BULLET_H

#include "Entity.h"
#include "Border.h"
#include "Tank.h"
#include "Wall.h"

class Border;
class Wall;
class Gold;
class Tank;
class Map;

class Bullet : public Entity {
public:
	Bullet();

	Bullet(int x, int y, int hp, DrawingStrategy* ds, int speed, Direction dir, Type type);

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


#endif //VERYCRAZYTANKS_BULLET_H
