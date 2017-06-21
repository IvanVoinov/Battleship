#pragma once

#include "Player.h"
#include "Drawer.h"

class Game
{
public:
	void showStatistic(int time, int killed, int alive);
	void run();
	void pause();
	int gameTimer();
	bool isExtraMoveAvailable();
	bool isGameOver();
private:
	Player* player_;
	Drawer* field_;
	int gameTime = 0;
};
