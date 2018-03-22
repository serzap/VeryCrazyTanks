#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int x, int y, int hp, char texture) : m_x(x), m_y(y), m_hitPoints(hp), m_texture(texture){}

const int &Entity::getX() {
    return m_x;
}

void Entity::setX(int x) {
    m_x = x;
}

const int &Entity::getY() {
    return m_y;
}

void Entity::setY(int y) {
    m_y = y;
}

void Entity::getDamage() {
    m_hitPoints--;
}

bool Entity::isDestroyed() {
    return m_hitPoints <= 0;
}


