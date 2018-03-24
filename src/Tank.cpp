#include "Tank.h"

Tank::Tank() = default;

Tank::Tank(int x, int y, int hp, char texture, int speed, Direction dir, Type type) :
        Entity(x, y, hp), m_texture(texture), m_speed(speed), m_dir(dir), m_type(type) {}

void Tank::getDamage() {
    m_hitPoints--;
}

bool Tank::isDestroyed() {
    return m_hitPoints <= 0;
}
std::vector<std::pair<int, int>> Tank::getBounds() {
    std::vector<std::pair<int, int>> bounds;
    bounds.emplace_back(m_x, m_y);
    return bounds;
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

void Tank::draw(Map& map) {
    map[m_y][m_x] = m_texture;
}




