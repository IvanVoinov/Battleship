#pragma once

#include <vector>

#include "NavyFactory.h"


class Player
{
public:
	virtual bool isPossibleToPlace(Position pos, ShipID shipId, ShipOrientation shipOrient);
	virtual bool isInsideBorder(Position pos);
	virtual bool isPositionFree(Position pos);
	virtual void generateShips();
	virtual void generateSingleShip(ShipID shipId);
	virtual void makeMove() = 0;
	virtual bool isMoveAlready(Position pos);
	virtual bool isHitShip(Position pos);
	virtual ~Player();
protected:
	std::vector<Ship*> navy_;
	std::vector<Position> hits_;
};
