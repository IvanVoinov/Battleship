#pragma once

#include "Ship.h"

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

class NavyFactory
{
public:
	static Ship* createShip(Position pos, ShipID shipId, ShipOrientation shipOrient);
};

