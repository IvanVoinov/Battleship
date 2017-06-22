#ifndef TWO_DECK_SHIP_H
#define TWO_DECK_SHIP_H

#include "Ship.h"

class TwoDeckShip : public Ship
{
public:
	virtual int getSumShipDecks() const;
private:
	int sumShipDecks_ = 2;
};

#endif TWO_DECK_SHIP_H