#include "Bullet.h"

Bullet::Bullet() = default;

Bullet::Bullet(int x, int y, int hp, char texture, int speed, Direction dir, Type type) :
        Entity(x,y, hp), m_texture(texture), m_speed(speed), m_dir(dir), m_type(type) {
}

void Bullet::move() {
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

std::vector<std::pair<int, int>> Bullet::getBounds() {
    std::vector<std::pair<int,int>> bounds;
    bounds.emplace_back(m_x, m_y);
}

void Bullet::draw(Map& map) {
    map[m_y][m_x] = m_texture;
};




