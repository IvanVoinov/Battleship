#include "Ship.h"

void Ship::initializeShip(const Position & pos, const ShipOrientation & shipOrient)
{
	Position shipPos;
	int shipDecks = getSumShipDecks();
	if (shipOrient == SHIP_ORIENTATION_HORIZONTAL) {
		position_.push_back(pos);
		for (int i = 1; i < shipDecks; ++i) {
			shipPos.xPosition = pos.xPosition + i;
			shipPos.yPosition = pos.yPosition;
			position_.push_back(shipPos);
		}
	}
	else {
		position_.push_back(pos);
		for (int i = 1; i < shipDecks; ++i) {
			shipPos.xPosition = pos.xPosition;
			shipPos.yPosition = pos.yPosition + i;
			position_.push_back(shipPos);
		}
	}
}

bool Ship::isFree(const Position& pos) const
{
	for (int i = 0; i < position_.size(); ++i) {
		if (position_[i] == pos)
			return false;
	}
	return true;
}

bool Ship::isKilled() const
{
	return position_.size() == damaged_.size();
}

void Ship::damage(const Position & pos)
{
	for (int i = 0; i < position_.size(); ++i) {
		if (position_[i] == pos) {
			damaged_.push_back(pos);
			break;
		}
	}
}

Ship::~Ship()
{

}
