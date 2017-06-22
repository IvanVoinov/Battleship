#include "NavyFactory.h"
#include "OneDeckShip.h"
#include "TwoDeckShip.h"
#include "ThreeDeckShip.h"
#include "FourDeckShip.h"

Ship* NavyFactory::createShip(const Position& pos, const ShipID& shipId, const ShipOrientation& shipOrient)
{
	Ship* shipType = 0;
	switch (shipId) {
	case SHIP_ID_ONE_DECK:
		shipType = new OneDeckShip();
		break;
	case SHIP_ID_TWO_DECK:
		shipType = new TwoDeckShip();
		break;
	case SHIP_ID_THREE_DECK:
		shipType = new ThreeDeckShip();
		break;
	case SHIP_ID_FOUR_DECK:
		shipType = new FourDeckShip();
		break;
	}
	if (shipType)
		shipType->initializeShip(pos, shipOrient);
	return shipType;
}
