#ifndef VERYCRAZYTANKS_ENTITY_H
#define VERYCRAZYTANKS_ENTITY_H

#include <utility>
#include <vector>
#include "Constants.h"
#include "DrawingStrategy.h"
#include "Map.h"

class Entity {
public:
	Entity();

	Entity(int x, int y, int hp, DrawingStrategy* ds);

	virtual ~Entity();

	//Getters and Setters
	inline const int &getX() const { return m_x; }

	void setX(const int &x) { m_x = x; }

	const int &getY() const { return m_y; }

	void setY(const int &y) { m_y = y; }

	const int &getHP() const { return m_hitPoints; }

	void setHP(const int &hp) { m_hitPoints = hp; }

	const  DrawingStrategy *getDrawingSrategy() const { return m_ds; }

	void setHP(DrawingStrategy * ds) { m_ds = ds; }

	//Functions
	virtual void getDamage() = 0;

	virtual bool isDestroyed() = 0;

	virtual void update() = 0;

	virtual void collideWith(Entity& other) = 0;

	virtual void draw(Map &map);

protected:
	int m_x;
	int m_y;
	int m_hitPoints;
	DrawingStrategy* m_ds;
};

#endif //VERYCRAZYTANKS_ENTITY_H
