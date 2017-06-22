#ifndef GAME_H
#define GAME_H

#include "Human.h"
#include "Computer.h"
#include "Drawer.h"
#include "DrawerImplBase.h"

class Game
{
public:
	void run();
	void pause();
	void showStatistic(int time, int killed, int alive);
	bool isExtraMoveAvailable() const;
	bool isGameOver() const;
	int gameTimer();
	Game(DrawerImplBase& drawerImpl);
private:
	Human human_;
	Computer computer_;
	Drawer drawer_;
	int gameTime = 0;
};

#endif GAME_H