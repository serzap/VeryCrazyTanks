#include "Game.h"



Game::Game(){}


Game::~Game(){}

void Game::run()
{
	bf.generate();
	while (!(bf.isOver() || bf.isVictory())) {
		system("CLS");
		bf.handleInput();
		bf.update();
		bf.handleCollision();
		bf.draw();
		Sleep(50);
	}
	system("CLS");
	std::cout << "\n\n\n\n\n" << std::setfill(' ') << std::setw(37) << (bf.isOver() ? "YOU LOSE" : "YOU WIN") << std::endl;
}
