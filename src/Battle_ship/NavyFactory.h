#ifndef NAVY_FACTORY_H
#define NAVY_FACTORY_H

#include "Ship.h"
#include "Position.h"

class NavyFactory
{
public:
	static Ship* createShip(const Position& pos, const ShipID& shipId, const ShipOrientation& shipOrient);
};

#endif NAVY_FACTORY_H


