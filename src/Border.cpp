#include "Border.h"

Border::Border(){}

Border::Border(int x, int y, int hp, DrawingStrategy* ds) : Entity(x, y, hp, ds) {}

Border::~Border(){}

void Border::getDamage(){}

bool Border::isDestroyed(){return false;}

void Border::update(){}

void Border::collideWith(Entity & other)
{
	if (Tank* tank = dynamic_cast<Tank*>(&other)) {
		if (this->m_x == tank->getX() && this->m_y == tank->getY()) {
			tank->setDirection(getOppositeDirection(tank->getDirection()));
			tank->update();
		}
	}
	else if (Bullet* bullet = dynamic_cast<Bullet*>(&other)) {
		if (this->m_x == bullet->getX() && this->m_y == bullet->getY()) {
			bullet->getDamage();
		}
	}
	else {
		//do nothing
	}
}

