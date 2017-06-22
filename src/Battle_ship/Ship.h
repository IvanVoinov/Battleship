#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "Position.h"
#include "Constants.h"

class Ship
{
public:
	void initializeShip(const Position& pos, const Constants::ShipOrientation& shipOrient);
	bool isFree(const Position& pos) const;
	void damage(const Position& pos);
	bool isKilled() const;
	virtual int getSumShipDecks() const = 0;
	virtual ~Ship(); 
protected:
	std::vector<Position> position_;
	std::vector<Position> damaged_;
};

#endif SHIP_H