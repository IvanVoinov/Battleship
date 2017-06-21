#pragma once

#include <vector>

#include "Position.h"

class Ship
{
public:
	virtual void initializeShip() = 0;
	virtual bool isFree(Position pos);
	virtual ~Ship(); 
private:
	std::vector<Position> position_;
};