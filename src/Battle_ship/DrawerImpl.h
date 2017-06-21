#pragma once

enum CellType
{
	CELL_TYPE_EMPTY = 0,
	CELL_TYPE_WALL,
	CELL_TYPE_SHOOTED,
	CELL_TYPE_MISSED
};

class DrawerImpl
{
public:
	virtual void drawCell(int xPos, int yPos, CellType) = 0;
	virtual ~DrawerImpl() = 0;
};