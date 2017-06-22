#ifndef THRE_DECK_SHIP_H
#define THRE_DECK_SHIP_H

#include "Ship.h"

class ThreeDeckShip : public Ship
{
public:
	virtual int getSumShipDecks() const;
private:
	const int sumShipDecks = 3;
};

#endif THRE_DECK_SHIP_H