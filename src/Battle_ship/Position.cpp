#include "Position.h"

Position::Position()
{
}

Position::Position(int x, int y)
	: xPosition(x), yPosition(y)
{
}

bool Position::operator==(const Position& pos) const
{
	return xPosition == pos.xPosition && yPosition == pos.yPosition;
}
