#ifndef NAVY_FACTORY_H
#define NAVY_FACTORY_H

#include "Ship.h"
#include "Position.h"
#include "Constants.h"

class NavyFactory
{
public:
	static Ship* createShip(const Position& pos, const Constants::ShipID& shipId, const Constants::ShipOrientation& shipOrient);
};

#endif NAVY_FACTORY_H