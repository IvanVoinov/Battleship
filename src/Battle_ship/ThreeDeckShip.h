#ifndef THREE_DECK_SHIP_H
#define THREE_DECK_SHIP_H

#include "Ship.h"

class ThreeDeckShip : public Ship
{
public:
	virtual int getSumShipDecks() const;
private:
	int sumShipDecks_ = 3;
};

#endif THREE_DECK_SHIP_H