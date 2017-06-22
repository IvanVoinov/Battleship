#ifndef DRAWER_H
#define DRAWER_H

#include "DrawerImplBase.h"
#include "Human.h"
#include "Computer.h"

enum PlayerTurn
{
	PLAYER_TURN_COMPUTER = 1,
	PLAYER_TURN_HUMAN
};

class Drawer
{
public:
	Drawer(DrawerImplBase& drawerImpl, Human& human, Computer& computer);
	void drawRectangle(int xPos, int yPos);
	void drawVerticalLineCoords(const int xPos, const int yPos);
	void drawHorizontalLineCoords(const int xPos, const int yPos);
	void drawScene();
	void drawField();
	void drawShips(const Player& player);
	void drawHits(const Player& atackPlayer, const Player& defendPlayer, const int& xOffset);
	void drawHitAtPosition(const Player& atackPlayer, const Player& defendPlayer, const int& xOffset, const Position& pos);
private:	
	DrawerImplBase& drawer_;
	Human&  human_;
	Computer& computer_;
};

#endif DRAWER_H
