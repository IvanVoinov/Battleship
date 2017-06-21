#pragma once

struct Position
{
	Position();
	Position(int x, int y);
	int xPosition = 0;
	int yPosition = 0;
	bool operator==(const Position&) const;
};
