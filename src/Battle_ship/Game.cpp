#include "Game.h"


Game::Game(DrawerImplBase& drawerImpl)
	: drawer_(drawerImpl, human_, computer_)
{

}

void Game::showStatistic(int time, int killed, int alive)
{
}

void Game::run()
{
	Position hitPosition;
	human_.generateShips();
	computer_.generateShips();
	drawer_.drawScene();

	do {
		hitPosition = human_.makeMove();
		computer_.damageShip(hitPosition);
		drawer_.drawScene();

		if (isGameOver())
			break;

		hitPosition = computer_.makeMove();
		human_.damageShip(hitPosition);
		drawer_.drawScene();

	} while (!isGameOver());
}

void Game::pause()
{
}

int Game::gameTimer()
{
	return 0;
}

bool Game::isExtraMoveAvailable() const
{
	return false;
}

bool Game::isGameOver() const
{
	if (human_.areAllShipsKilled())
		return true;
	else if (computer_.areAllShipsKilled())
		return true;
	return false;
}
