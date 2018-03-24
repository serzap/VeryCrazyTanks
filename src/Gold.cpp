#include "Gold.h"

Gold::Gold() = default;

Gold::Gold(int x, int y, int hp, char texture) : Entity(x, y, hp), m_texture(texture) {}

void Gold::getDamage() {
    m_hitPoints--;
}

bool Gold::isDestroyed() {
    return m_hitPoints <= 0;
}

std::vector<std::pair<int, int>> Gold::getBounds() {
    std::vector<std::pair<int, int>> bounds;
    bounds.emplace_back(std::make_pair(m_x, m_y));
}

void Gold::update() {}

void Gold::draw(Map& map) {
    map[m_y][m_x] = m_texture;
}

