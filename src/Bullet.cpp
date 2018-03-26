#include "Bullet.h"

Bullet::Bullet() = default;

Bullet::Bullet(int x, int y, int hp, DrawingStrategy* ds, int speed, Direction dir, Type type) :
	Entity(x, y, hp, ds), m_speed(speed), m_dir(dir), m_type(type) {
}

void Bullet::getDamage() {
	m_hitPoints--;
}

bool Bullet::isDestroyed() {
	return m_hitPoints <= 0;
}

void Bullet::update() {
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
};

void Bullet::collideWith(Entity & other)
{
	if (Tank* tank = dynamic_cast<Tank*>(&other)) {
		if (this->m_x == tank->getX() && this->m_y == tank->getY() && (this->m_type != tank->getType())) {
			this->getDamage();
			tank->getDamage();
		}
	}
	else if (Wall* wall = dynamic_cast<Wall*>(&other)) {
		if (this->m_x == wall->getX() && this->m_y == wall->getY()) {
			this->getDamage();
			wall->getDamage();
		}
	}
	else if (Border* border = dynamic_cast<Border*>(&other)) {
		if (this->m_x == border->getX() && this->m_y == border->getY()) {
			this->getDamage();
		}
	}
	else if (Gold* gold = dynamic_cast<Gold*>(&other)) {
		if (this->m_x == gold->getX() && this->m_y == gold->getY() && (this->getType() == Type::ENEMY)) {
			this->getDamage();
			gold->getDamage();
		}
	}
	else {
		//do nothing
	}
}




