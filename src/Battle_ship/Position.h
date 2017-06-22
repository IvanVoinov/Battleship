#ifndef POSITION_H
#define POSITION_H

struct Position
{
	Position();
	Position(int x, int y);
	int xPosition = 0;
	int yPosition = 0;
	bool operator==(const Position& pos) const;
};

#endif POSITION_H
