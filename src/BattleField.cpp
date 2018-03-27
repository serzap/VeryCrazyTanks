#include "BattleField.h"


BattleField::BattleField() {
	m_start = std::clock();

	//console size settings
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 680, 800, TRUE);

	m_gameMap.init(Constants::MAP_WIDTH, Constants::MAP_HEIGHT);
	m_scorePoints = 0;
	m_currDir = Direction::UP;
	m_enemiesCnt = Constants::ENEMIES_COUNT;
}

BattleField::~BattleField()
{
	for (size_t i = 0; i < m_entities.size(); ++i) {
		delete m_entities[i];
	}
}

void BattleField::generate() {
	//Generate borders
	for (int i = 0; i < m_gameMap.getHeight(); ++i) {
		for (int j = 0; j < m_gameMap.getWidth(); ++j)
		{
			if (i == 0 || j == 0 || i == m_gameMap.getHeight() - 1 || j == m_gameMap.getWidth() - 1)
			{
				m_entities.push_back(new Border(j, i, Constants::BORDER_HP, new BorderDrawingStrategy()));
			}
		}
	}
	//Generate player
	int playerX = m_gameMap.getWidth() / 2;
	int playerY = m_gameMap.getHeight() - 2;
	m_player = new Tank(playerX, playerY,
		Constants::PLAYER_HP, new PlayerTankDrawingStrategy(), Constants::PLAYER_SPEED,
		Direction::STOP, Type::PLAYER);
	m_entities.push_back(m_player);

	//Generate fortress
	int fortressX = m_gameMap.getWidth() / 2 - 5;
	int fortressY = m_gameMap.getHeight() - 5;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (i == 1 && j == 1)
			{
				m_gold = new Gold(fortressX + j, fortressY + i, Constants::GOLD_HP, new GoldDrawingStrategy());
				m_entities.push_back(m_gold);
			}
			else
			{
				m_entities.push_back(new Wall(fortressX + j, fortressY + i, Constants::WALL_HP, new WallDrawingStrategy()));
			}
		}
	}
	//Generate walls
	int wallPosX = 0;
	int wallPosY = 0;
	for (int i = 0; i < Constants::WALL_COUNT; ++i) {
		int wallLength = getRandomNumber(2, 7);
		int orientation = getRandomNumber(0, 1); //0 - vertical, 1 -horizontal
		wallPosX = getRandomNumber(5, m_gameMap.getWidth() - 10);
		wallPosY = getRandomNumber(5, m_gameMap.getHeight() - 10);
		for (int j = 0; j < wallLength; ++j) {
			if (orientation == 0)
			{
				if (m_gameMap[wallPosY][wallPosX + j] == ' ')
					m_entities.push_back(
						new Wall(wallPosX + j, wallPosY, Constants::WALL_HP, new WallDrawingStrategy()));
			}
			else {
				if (m_gameMap[wallPosY + j][wallPosX] == ' ')
					m_entities.push_back(
						new Wall(wallPosX, wallPosY + j, Constants::WALL_HP, new WallDrawingStrategy()));
			}
		}
	}
	//Generate enemies
	int enemyPosX = 0;
	int enemyPosY = 0;
	for (int i = 0; i < m_enemiesCnt; ++i) {
		int step = m_gameMap.getWidth() / m_enemiesCnt;
		bool posFound = false;
		while (!posFound) {
			enemyPosX = getRandomNumber(step * i, step * (i + 1) - Constants::DISTANCE_BTW_ENTITIES);
			enemyPosY = getRandomNumber(0, m_gameMap.getHeight() - 10);
			if (m_gameMap[enemyPosY][enemyPosX] == ' ') {
				posFound = true;
			}
		}
		m_entities.push_back(new Tank(enemyPosX, enemyPosY,
			Constants::ENEMY_HP, new EnemyTankDrawingStrategy(), Constants::ENEMY_SPEED,
			Direction::STOP, Type::ENEMY));
	}
}

void BattleField::handleInput() {
	if (GetAsyncKeyState(0x57))
	{
		static_cast<Tank*>(m_player)->setDirection(Direction::UP);
		m_currDir = Direction::UP;
	}
	else if (GetAsyncKeyState(0x44))
	{
		static_cast<Tank*>(m_player)->setDirection(Direction::RIGHT);
		m_currDir = Direction::RIGHT;
	}
	else if (GetAsyncKeyState(0x53))
	{
		static_cast<Tank*>(m_player)->setDirection(Direction::DOWN);
		m_currDir = Direction::DOWN;
	}
	else if (GetAsyncKeyState(0x41))
	{
		static_cast<Tank*>(m_player)->setDirection(Direction::LEFT);
		m_currDir = Direction::LEFT;
	}
	else if (GetAsyncKeyState(VK_SPACE)) {
		//shoot
		m_entities.push_back(new Bullet(m_player->getX(), m_player->getY(), Constants::BULLET_HP, new PlayerBulletDrawingStrategy(), Constants::BULLET_SPEED, m_currDir, Type::PLAYER));
	}
	else static_cast<Tank*>(m_player)->setDirection(Direction::STOP);
}

void BattleField::update() {
	for (size_t i = 0; i < m_entities.size(); ++i) {
		if (typeid(*m_entities[i]) == typeid(Tank) && m_entities[i] != m_player)
		{
			int chanceToMove = 80;
			if (getRandomNumber(1, 100) <= chanceToMove) {
				static_cast<Tank*>(m_entities[i])->setDirection(static_cast<Direction>(getRandomNumber(1, 4)));
			}
			else {
				static_cast<Tank*>(m_entities[i])->setDirection(Direction::STOP);
			}
			int chanceToShoot = 10;
			if (getRandomNumber(1, 100) <= chanceToShoot) {
				m_entities.push_back(new Bullet(m_entities[i]->getX(), m_entities[i]->getY(), Constants::BULLET_HP, new EnemyBulletDrawingStrategy(), Constants::BULLET_SPEED, static_cast<Direction>(getRandomNumber(1,4)), Type::ENEMY));
			}
		}
		m_entities[i]->update();
	}
}

void BattleField::handleCollision() {
	for (size_t i = 0; i < m_entities.size() - 1; ++i) {
		for (size_t j = i + 1; j < m_entities.size(); ++j) {
			m_entities[i]->collideWith(*m_entities[j]);
		}
	}
	for (size_t i = 0; i < m_entities.size(); ++i) {
		if (m_entities[i]->isDestroyed()) {
			Tank* t = dynamic_cast<Tank*>(m_entities[i]);
			if (t && t->getType() == Type::ENEMY) {
				m_enemiesCnt--;
				m_scorePoints++;
			}
		}
	}
	for (size_t i = 0; i < m_entities.size(); ++i) {
		m_entities.erase(
			std::remove_if(m_entities.begin(), m_entities.end(), [&](Entity* entity) {
			return (entity->isDestroyed()); }),
			m_entities.end());
	}
}

void BattleField::draw() {
	for (size_t i = 0; i < m_entities.size(); ++i) {
		m_entities[i]->draw(m_gameMap);
	}
	m_gameMap.display();
	std::cout << std::endl;
	std::cout << " HEALTH POINTS - " << m_player->getHP() << std::endl;
	std::cout << " PLAYER SCORE - " << m_scorePoints << std::endl;
	m_duration = (std::clock() - m_start) / (double)CLOCKS_PER_SEC;
	int seconds = static_cast<int>(m_duration);
	int minutes = 0;
	getTime(seconds, minutes);
	std::cout << " GAME DURATION - " << ((minutes >= 10) ? ' ' : '0') << minutes << "::" << ((seconds >= 10) ? ' ' : '0') << seconds << std::endl;
	m_gameMap.clear();
}

bool BattleField::isOver()
{
	return m_gold->isDestroyed() || m_player->isDestroyed();
}

bool BattleField::isVictory()
{
	return m_enemiesCnt == 0;
}



