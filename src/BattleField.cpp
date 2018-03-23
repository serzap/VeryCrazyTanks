#include "BattleField.h"

BattleField::BattleField() = default;

void BattleField::init() {
    m_gameMap.init(Constants::MAP_WIDTH, Constants::MAP_HEIGHT);
    m_scorePoints = 0;
    m_enemiesCnt = Constants::ENEMIES_COUNT;
}

void BattleField::generate() {
    //Generate walls
    for (int i = 0; i < Constants::WALL_COUNT; ++i) {
        m_entities.push_back(
                new Wall(getRandomNumber(5, m_gameMap.getWidth() - 10), getRandomNumber(5, m_gameMap.getHeight() - 10),
                         Constants::WALL_HP, Constants::WALL_TEXTURE, getRandomNumber(5, 10),
                         static_cast<Position>(getRandomNumber(0, 1))));

    }
    //Generate player
    m_entities.push_back(new Tank(m_gameMap.getWidth() / 2, m_gameMap.getHeight() - 2,
                                  Constants::PLAYER_HP, Constants::PLAYER_TEXTURE, Constants::PLAYER_SPEED,
                                  Direction::STOP, Type::PLAYER));
    //Generate enemies
    for (int i = 0; i < m_enemiesCnt; ++i) {
        int enemyPosX = 0;
        int enemyPosY = 0;
        int step = m_gameMap.getWidth() / m_enemiesCnt;
        bool posFound = false;
        while (!posFound) {
            enemyPosX = getRandomNumber(step * i, step * (i + 1) - Constants::DISTANCE_BTW_ENTETIES);
            enemyPosY = getRandomNumber(0, m_gameMap.getHeight() - 10);
            //check collision
            if (m_gameMap[enemyPosY][enemyPosX] == ' ') {
                posFound = true;
            }
        }
        m_entities.push_back(new Tank(enemyPosX, enemyPosY,
                                      Constants::ENEMY_HP, Constants::ENEMY_TEXTURE, Constants::ENEMY_SPEED,
                                      Direction::STOP, Type::ENEMY));
    }
    draw();
}

void BattleField::handleInput() {


}

void BattleField::update() {
    /*
    for(int i = 0; i < m_entities.size(); ++i){
        Tank *t = dynamic_cast<Tank *>(m_entities[i]);
        if(t){
            t->move();
        }
        Bullet *b = dynamic_cast<Bullet *>(m_entities[i]);
        if(b){
            b->move();
        }
    }*/

}

void BattleField::handleCollisiion() {
}


void BattleField::draw() {
    for (auto &entity : m_entities) {
        entity->draw(m_gameMap);
    }
    m_gameMap.display();
}


int BattleField::getRandomNumber(int lower, int upper) {
    return lower + (rand() % (upper - lower + 1));
}


