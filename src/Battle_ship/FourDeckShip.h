#ifndef FOUR_DECK_SHIP_H
#define FOUR_DECK_SHIP_H

#include "Ship.h"

class FourDeckShip : public Ship
{
public:
	virtual int getSumShipDecks() const;
private:
	const int sumShipDecks = 4;
};

#endif FOUR_DECK_SHIP_H