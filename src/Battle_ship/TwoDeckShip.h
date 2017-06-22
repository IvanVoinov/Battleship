#ifndef THREE_DECK_SHIP_H
#define THREE_DECK_SHIP_H

#include "Ship.h"

class TwoDeckShip : public Ship
{
public:
	virtual int getSumShipDecks() const;
private:
	const int sumShipDecks = 2;
};

#endif THREE_DECK_SHIP_H