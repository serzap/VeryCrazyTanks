#include "Wall.h"

Wall::Wall() = default;

Wall::Wall(int x, int y, int hp, DrawingStrategy* ds) : Entity(x, y, hp, ds)  {}

void Wall::getDamage() {
	m_hitPoints--;
}

bool Wall::isDestroyed() {
	return m_hitPoints <= 0;
}

void Wall::update() {/*nothing*/}

void Wall::collideWith(Entity & other)
{
	if (Tank* tank = dynamic_cast<Tank*>(&other)) {
		if (this->m_x == tank->getX() && this->m_y == tank->getY()) {
			tank->setDirection(getOppositeDirection(tank->getDirection()));
			tank->update();
		}	
	}
	else if (Bullet* bullet = dynamic_cast<Bullet*>(&other)) {
		if (this->m_x == bullet->getX() && this->m_y == bullet->getY()) {
			this->getDamage();
			bullet->getDamage();
		}
	}
	else {
		//do nothing
	}
}


