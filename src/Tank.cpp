#include "Tank.h"

Tank::Tank() = default;

Tank::Tank(int x, int y, int hp, char texture, int speed, Direction dir, Type type) :
        Entity(x, y, hp, texture), m_speed(speed), m_dir(dir), m_type(type) {}

void Tank::move() {
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

Bullet &Tank::shoot() {
    Bullet b (m_x, m_y, BULLET_HP, BULLET_TEXTURE, BULLET_SPEED, m_dir, m_type);
    b.move();
    return b;
}


std::vector<std::pair<int, int>> Tank::getBounds() {
    std::vector<std::pair<int, int>> bounds;
    bounds.emplace_back(m_x, m_y);
    return bounds;
}

void Tank::draw(char **map) {
    map[m_y][m_x] = m_texture;
}



