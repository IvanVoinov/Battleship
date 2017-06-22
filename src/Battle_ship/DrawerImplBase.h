#ifndef DRAWER_IMPL_BASE_H
#define DRAWER_IMPL_BASE_H
#include "Constants.h"

class DrawerImplBase
{
public:
	virtual void drawCell(const int& xPos, const int& yPos, const Constants::CellType& cellType) = 0;
	virtual void drawChar(const int& xPos, const int& yPos, char& ch) = 0;
	virtual void resetCursor(const int& xPos, const int& yPos) = 0;
	virtual void clearScreen() = 0;
	virtual ~DrawerImplBase();
};

#endif DRAWER_IMPL_BASE_H