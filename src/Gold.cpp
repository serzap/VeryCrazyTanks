#include "Gold.h"

Gold::Gold() = default;

Gold::Gold(int x, int y, int hp, DrawingStrategy* ds) : Entity(x, y, hp, ds){}

void Gold::getDamage() {
	m_hitPoints--;
}

bool Gold::isDestroyed() {
	return m_hitPoints <= 0;
}

void Gold::update() {/*nothing*/ }

void Gold::collideWith(Entity & other)
{
	if (Tank* tank = dynamic_cast<Tank*>(&other)) {
		if (this->m_x == tank->getX() && this->m_y == tank->getY()) {
			tank->setDirection(getOppositeDirection(tank->getDirection()));
			tank->update();
		}
	}
	else if (Bullet* bullet = dynamic_cast<Bullet*>(&other)) {
		if (this->m_x == bullet->getX() && this->m_y == bullet->getY() && bullet->getType() == Type::ENEMY) {
			this->getDamage();
			bullet->getDamage();
		}
	}
	else {
		//do nothing
	}
}


