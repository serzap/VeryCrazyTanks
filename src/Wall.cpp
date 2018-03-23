#include "Wall.h"

Wall::Wall() = default;

Wall::Wall(int x, int y, int hp, char texture, int length, Position pos) :
        Entity(x, y, hp), m_texture(texture), m_length(length), m_pos(pos) {

}

std::vector<std::pair<int, int>> Wall::getBounds() {
    std::vector<std::pair<int, int>> bounds;
    bounds.emplace_back(m_x, m_y);
    return bounds;
}

void Wall::draw(Map &map) {
    for (int i = 0; i < m_length; ++i) {
        if (m_pos == Position::HORIZONTAL) {
            map[m_y][m_x + i] = m_texture;
        }
        else{
            map[m_y + i][m_x] = m_texture;
        }
    }
}