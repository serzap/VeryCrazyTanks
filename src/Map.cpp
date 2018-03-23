#include "Map.h"

Map::Map() = default;

void Map::init(int width, int height) {
    m_width = width;
    m_height = height;
    for(int i = 0; i < m_height; ++i){
        m_field.emplace_back(m_width,' ');
    }
}

const int &Map::getWidth() const {
    return m_width;
}

const int &Map::getHeight() const {
    return m_height;
}


void Map::clear() {
    for(int i = 0; i < m_height; ++i){
        m_field.emplace_back(m_width,' ');
    }
}

void Map::display() {
    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            std::cout << m_field[i][j] << std::flush;
        }
        std::cout << std::endl;
    }
}
