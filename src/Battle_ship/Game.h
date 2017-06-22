#ifndef GAME_H
#define GAME_H

#include "Human.h"
#include "Computer.h"
#include "Drawer.h"
#include "DrawerImplBase.h"

class Game
{
public:
	Game(DrawerImplBase& drawerImpl);
	void run();
	void pause();
	void showStatistic(const int& time, const int& killed, const int& alive);
	bool isExtraMoveAvailable() const;
	bool isGameOver() const;
	int gameTimer();
private:
	Human human_;
	Computer computer_;
	Drawer drawer_;
	int gameTime_ = 0;
};

#endif GAME_H