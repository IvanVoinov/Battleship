#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "Position.h"

enum ShipID
{
	SHIP_ID_ONE_DECK = 1,
	SHIP_ID_TWO_DECK,
	SHIP_ID_THREE_DECK,
	SHIP_ID_FOUR_DECK
};

enum ShipOrientation
{
	SHIP_ORIENTATION_HORIZONTAL = 0,
	SHIP_ORIENTATION_VERTICAL
};

class Ship
{
public:
	virtual void initializeShip(const Position& pos, const ShipOrientation& shipOrient);
	virtual bool isFree(const Position& pos) const;
	virtual int getSumShipDecks() const = 0;
	bool isKilled() const;
	void damage(const Position& pos);
	virtual ~Ship(); 
protected:
	std::vector<Position> position_;
	std::vector<Position> damaged_;
};

#endif SHIP_H