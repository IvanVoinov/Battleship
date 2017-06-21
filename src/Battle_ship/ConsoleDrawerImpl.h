#pragma once

#include "DrawerImpl.h"
#include "Position.h"

class ConsoleDrawerImpl
{
public:
	virtual void drawCell(int xPos, int yPos, CellType);
private:
	int xPosition;
	int yPosition;
};
