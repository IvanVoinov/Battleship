#include "Drawer.h"
#include "Player.h"

Drawer::Drawer(DrawerImplBase & drawerImpl, Human & human, Computer & computer)
	: drawer_(drawerImpl)
	, human_(human)
	, computer_(computer)
{
}

void Drawer::drawRectangle(int xPos, int yPos)
{
	for (int y = yPos; y < fieldHeight_ + yPos; ++y) {
		for (int x = xPos; x < fieldWight_ + xPos; ++x) {
			if (x == xPos || y == yPos || x == fieldWight_ + xPos - 1 || y == fieldHeight_ + yPos - 1)
				drawer_.drawCell(x, y, CELL_TYPE_WALL);
		}
	}
}

void Drawer::drawVerticalLineCoords(const int xPos, const int yPos)
{
	char ch = '0';
	int x, y;
	for (y = yPos + 1, x = xPos - 1; y < fieldHeight_ + yPos - 1; ++y) {
		drawer_.drawChar(x, y, ch);
		ch++;
	}
}

void Drawer::drawHorizontalLine(const int xPos, const int yPos)
{
	char ch = 'A';
	int x, y;
	for (y = yPos - 1, x = xPos + 1; x < fieldWight_ + xPos - 1; ++x) {
		drawer_.drawChar(x, y, ch);
		ch++;
	}
}

void Drawer::drawField()
{
	drawRectangle(firstFieldCoord, firstFieldCoord);
	drawHorizontalLine(firstFieldCoord, firstFieldCoord);
	drawVerticalLineCoords(firstFieldCoord, firstFieldCoord);
	drawRectangle(secondFieldCoord, firstFieldCoord);
	drawHorizontalLine(secondFieldCoord, firstFieldCoord);
	drawVerticalLineCoords(secondFieldCoord, firstFieldCoord);
}

void Drawer::drawShips(const Player& player)
{
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 10; ++x) {
			Position pos;
			pos.xPosition = x;
			pos.yPosition = y;
			if (!player.isPositionFree(pos))
				drawer_.drawCell(x + firstFieldCoord + 1, y + firstFieldCoord + 1, CELL_TYPE_SHIP);
		}
	}
}

void Drawer::drawHits(const Player& atackPlayer, const Player& defendPlayer, const int& xOffset)
{
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 10; ++x) {
			Position pos(x, y);
			drawHitAtPosition(atackPlayer, defendPlayer, xOffset, pos);
		}
	}
}

void Drawer::drawHitAtPosition(const Player & atackPlayer, const Player & defendPlayer, const int & xOffset, const Position & pos)
{
	if (atackPlayer.isMoveAlready(pos)) {
		if (defendPlayer.isPositionFree(pos))
			drawer_.drawCell(pos.xPosition + xOffset + 1, pos.yPosition + firstFieldCoord + 1, CELL_TYPE_MISSED);
		else {
			drawer_.drawCell(pos.xPosition + xOffset + 1, pos.yPosition + firstFieldCoord + 1, CELL_TYPE_SHOOTED);
		}
	}
}

void Drawer::drawScene()
{
	drawer_.clearScreen();
	drawField();
	drawShips(human_);
	drawHits(human_, computer_, secondFieldCoord);
	drawHits(computer_, human_, firstFieldCoord);
	drawer_.resetCursor(firstFieldCoord, secondFieldCoord + 1);
}