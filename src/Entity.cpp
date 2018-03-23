#include "Entity.h"

Entity::Entity() = default;

Entity::Entity(int x, int y, int hp) : m_x(x), m_y(y), m_hitPoints(hp){}

const int &Entity::getX() const{
    return m_x;
}

void Entity::setX(const int& x) {
    m_x = x;
}

const int &Entity::getY() const{
    return m_y;
}

void Entity::setY(const int& y) {
    m_y = y;
}

void Entity::getDamage() {
    m_hitPoints--;
}

bool Entity::isDestroyed() {
    return m_hitPoints <= 0;
}


