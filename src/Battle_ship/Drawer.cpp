#include "Drawer.h"
#include "Player.h"
#include "Constants.h"
using namespace Constants;

Drawer::Drawer(DrawerImplBase & drawerImpl, Human & human, Computer & computer)
	: drawer_(drawerImpl)
	, human_(human)
	, computer_(computer)
{
}

void Drawer::drawRectangle(int xPos, int yPos)
{
	for (int y = yPos; y < BATTLE_FIELD_HEIGHT + yPos; ++y) {
		for (int x = xPos; x < BATTLE_FIELD_WIGHT + xPos; ++x) {
			if (x == xPos || y == yPos || x == BATTLE_FIELD_WIGHT + xPos - 1 || y == BATTLE_FIELD_HEIGHT + yPos - 1)
				drawer_.drawCell(x, y, CELL_TYPE_WALL);
		}
	}
}

void Drawer::drawVerticalLineCoords(const int xPos, const int yPos)
{
	char ch = '0';
	int x, y;
	for (y = yPos + 1, x = xPos - 1; y < BATTLE_FIELD_HEIGHT + yPos - 1; ++y) {
		drawer_.drawChar(x, y, ch);
		ch++;
	}
}

void Drawer::drawHorizontalLineCoords(const int xPos, const int yPos)
{
	char ch = 'A';
	int x, y;
	for (y = yPos - 1, x = xPos + 1; x < BATTLE_FIELD_WIGHT + xPos - 1; ++x) {
		drawer_.drawChar(x, y, ch);
		ch++;
	}
}

void Drawer::drawField()
{
	drawRectangle(FIRST_FIELD_COORD, FIRST_FIELD_COORD);
	drawHorizontalLineCoords(FIRST_FIELD_COORD, FIRST_FIELD_COORD);
	drawVerticalLineCoords(FIRST_FIELD_COORD, FIRST_FIELD_COORD);
	drawRectangle(SECOND_FIELD_COORD, FIRST_FIELD_COORD);
	drawHorizontalLineCoords(SECOND_FIELD_COORD, FIRST_FIELD_COORD);
	drawVerticalLineCoords(SECOND_FIELD_COORD, FIRST_FIELD_COORD);
}

void Drawer::drawShips(const Player& player)
{
	for (int y = 0; y < FIELD_SIZE; ++y) {
		for (int x = 0; x < FIELD_SIZE; ++x) {
			Position pos;
			pos.xPosition = x;
			pos.yPosition = y;
			if (!player.isPositionFree(pos))
				drawer_.drawCell(x + FIRST_FIELD_COORD + 1, y + FIRST_FIELD_COORD + 1, CELL_TYPE_SHIP);
		}
	}
}

void Drawer::drawHits(const Player& atackPlayer, const Player& defendPlayer, const int& xOffset)
{
	for (int y = 0; y < FIELD_SIZE; ++y) {
		for (int x = 0; x < FIELD_SIZE; ++x) {
			Position pos(x, y);
			drawHitAtPosition(atackPlayer, defendPlayer, xOffset, pos);
		}
	}
}

void Drawer::drawHitAtPosition(const Player & atackPlayer, const Player & defendPlayer, const int & xOffset, const Position & pos)
{
	if (atackPlayer.isMoveAlready(pos)) {
		if (defendPlayer.isPositionFree(pos))
			drawer_.drawCell(pos.xPosition + xOffset + 1, pos.yPosition + FIRST_FIELD_COORD + 1, CELL_TYPE_MISSED);
		else {
			drawer_.drawCell(pos.xPosition + xOffset + 1, pos.yPosition + FIRST_FIELD_COORD + 1, CELL_TYPE_SHOOTED);
		}
	}
}

void Drawer::drawScene()
{
	drawer_.clearScreen();
	drawField();
	drawShips(human_);
	drawHits(human_, computer_, SECOND_FIELD_COORD);
	drawHits(computer_, human_, FIRST_FIELD_COORD);
	drawer_.resetCursor(FIRST_FIELD_COORD, SECOND_FIELD_COORD + 1);
}