#include "Tank.h"

Tank::Tank() = default;

Tank::Tank(int x, int y, int hp, DrawingStrategy* ds, int speed, Direction dir, Type type) :
	Entity(x, y, hp, ds), m_speed(speed), m_dir(dir), m_type(type) {}

void Tank::getDamage() {
	m_hitPoints--;
}

bool Tank::isDestroyed() {
	return m_hitPoints <= 0;
}

void Tank::update() {
	switch (m_dir) {
	case Direction::UP:
		m_y -= m_speed;
		break;
	case Direction::RIGHT:
		m_x += m_speed;
		break;
	case Direction::DOWN:
		m_y += m_speed;
		break;
	case Direction::LEFT:
		m_x -= m_speed;
		break;
	case Direction::STOP:
		break;
	}
}

void Tank::collideWith(Entity & other)
{
	if (Tank* tank = dynamic_cast<Tank*>(&other)) {
		if (this->m_x == tank->getX() && this->m_y == tank->getY()) {
			this->setDirection(getOppositeDirection(this->getDirection()));
			this->update();
		}
	}
	else if (Bullet* bullet = dynamic_cast<Bullet*>(&other)) {
		if (this->m_x == bullet->getX() && this->m_y == bullet->getY() && (this->m_type != bullet->getType())) {
			this->getDamage();
			bullet->getDamage();
		}
	}
	else if (Border* border = dynamic_cast<Border*>(&other)) {
		if (this->m_x == border->getX() && this->m_y == border->getY()) {
			this->setDirection(getOppositeDirection(this->getDirection()));
			this->update();
		}
	}
	else if (Wall* wall = dynamic_cast<Wall*>(&other)) {
		if (this->m_x == wall->getX() && this->m_y == wall->getY()) {
			this->setDirection(getOppositeDirection(this->getDirection()));
			this->update();
		}
	}
	else if (Gold* gold = dynamic_cast<Gold*>(&other)) {
		if (this->m_x == gold->getX() && this->m_y == gold->getY()) {
			this->setDirection(getOppositeDirection(this->getDirection()));
			this->update();
		}
	}
	else {
		//do nothing
	}
}





