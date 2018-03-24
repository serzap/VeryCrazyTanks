#include "BattleField.h"


BattleField::BattleField() = default;

void BattleField::init() {
    m_gameMap.init(Constants::MAP_WIDTH, Constants::MAP_HEIGHT);
    m_scorePoints = 0;
    m_enemiesCnt = Constants::ENEMIES_COUNT;
}

void BattleField::generate() {
    //Generate player
    int playerX = m_gameMap.getWidth() / 2;
    int playerY = m_gameMap.getHeight() - 2;
    player = new Tank(playerX, playerY,
                      Constants::PLAYER_HP, Constants::PLAYER_TEXTURE, Constants::PLAYER_SPEED,
                      Direction::STOP, Type::PLAYER);
    //Generate fortress
    int fortressX = m_gameMap.getWidth() / 2 - 5;
    int fortressY = m_gameMap.getHeight() - 2;

    fortress = new Fortress(fortressX, fortressY);
    //Generate walls
    for (int i = 0; i < Constants::WALL_COUNT; ++i) {
        m_entities.push_back(
                new Wall(getRandomNumber(5, m_gameMap.getWidth() - 10), getRandomNumber(5, m_gameMap.getHeight() - 10),
                         Constants::WALL_HP, Constants::WALL_TEXTURE, getRandomNumber(5, 10),
                         static_cast<Position>(getRandomNumber(0, 1))));

    }
    //Generate player
    player = new Tank(m_gameMap.getWidth() / 2, m_gameMap.getHeight() - 2,
                      Constants::PLAYER_HP, Constants::PLAYER_TEXTURE, Constants::PLAYER_SPEED,
                      Direction::STOP, Type::PLAYER);
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
}

void BattleField::handleInput() {
    /*
    if (GetAsyncKeyState(VK_UP))
    {
        player.setDir(direction::UP);
        lastMoveDir = direction::UP;
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        player.setDir(direction::RIGHT);
        lastMoveDir = direction::RIGHT;
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        player.setDir(direction::DOWN);
        lastMoveDir = direction::DOWN;
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        player.setDir(direction::LEFT);
        lastMoveDir = direction::LEFT;
    }
    else if (GetAsyncKeyState(VK_SPACE)) {
     Bullet b = player.shoot();
    }
    else player.setDir(direction::STOP);
*/
    int choice = getRandomNumber(0, 1);
    if (choice == 0) {
        int chanceToMove = 30;
        if (getRandomNumber(1, 100) <= chanceToMove) {
            Direction dir = static_cast<Direction >(getRandomNumber(1, 5));
            player->setDirection(dir);
        }
    }
    else{
        //shoot
        m_entities.push_back(new Bullet(player->getX(),player->getY(),Constants::BULLET_HP,Constants::BULLET_TEXTURE,Constants::BULLET_SPEED,player->getDirection(),Type::PLAYER));
    }
}

void BattleField::update() {
    player->update();
    fortress->draw(m_gameMap);
    for (auto &entity : m_entities) {
        entity->update();
    }
}

void BattleField::handleCollision() {
}


void BattleField::draw() {
    player->draw(m_gameMap);
    fortress->draw(m_gameMap);
    for (auto &entity : m_entities) {
        entity->draw(m_gameMap);
    }
    m_gameMap.display();
}


int BattleField::getRandomNumber(int lower, int upper) {
    return lower + (rand() % (upper - lower + 1));
}


