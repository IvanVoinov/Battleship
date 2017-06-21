#include "Player.h"
#include "Position.h"
#include "Ship.h"
#include "Utility.h"

bool Player::isPossibleToPlace(Position pos, ShipID shipId, ShipOrientation shipOrient)
{
	int shipSize = shipId;
	if (shipOrient == SHIP_ORIENTATION_HORIZONTAL) {
		for (int x = pos.xPosition - 1; x < shipSize + 2; ++x) {
			for (int y = pos.yPosition - 1; y < pos.yPosition + 3; ++y) {
				Position current(x, y);
				if (pos.xPosition <= x && x < pos.xPosition + shipSize && y == pos.yPosition) {
					if (!isInsideBorder(current) || !isPositionFree(current)) {
						return false;
					}
				}
				else if (!isPositionFree(current))
					return false;
			}
		}
	}
	else if (shipOrient == SHIP_ORIENTATION_VERTICAL) {
		for (int x = pos.xPosition - 1; x < pos.xPosition + 3; ++x) {
			for (int y = pos.yPosition - 1; y < shipSize + 2; ++y) {
				Position current(x, y);
				if (pos.xPosition == x && y < pos.yPosition + shipSize && pos.yPosition <= y) {
					if (!isInsideBorder(current) || !isPositionFree(current)) {
						return false;
					}
				}
				else if (!isPositionFree(current))
					return false;
				}
			}
	}
	return true;
}

bool Player::isInsideBorder(Position pos)
{
	if (pos.xPosition >= 0 && pos.xPosition < 10 && pos.yPosition >= 0 && pos.yPosition < 10)
		return true;
	return false;
}

bool Player::isPositionFree(Position pos)
{
	for (int i = 0; i < navy_.size(); ++i) {
		if (!navy_[i]->isFree(pos))
			return false;
	}
	return true;
}

void Player::generateShips()
{
	for (int i = 0; i < 10; ++i) {
		if (i == 0)
			generateSingleShip(SHIP_ID_FOUR_DECK);
		else if (i > 0 && i <= 2)
			generateSingleShip(SHIP_ID_THREE_DECK);
		else if (i > 2 && i <=5)
			generateSingleShip(SHIP_ID_TWO_DECK);
		else
			generateSingleShip(SHIP_ID_TWO_DECK);
	}
}

void Player::generateSingleShip(ShipID shipId)
{
	int fieldSize = 10;
	int orientation = 2;
	ShipOrientation shipOrient;
	Position shipPos;
	do  {
		shipPos.xPosition = Utility::randomInt(fieldSize);
		shipPos.yPosition = Utility::randomInt(fieldSize);
		orientation = Utility::randomInt(orientation);
		shipOrient = static_cast<ShipOrientation>(orientation);
	} while (isPossibleToPlace(shipPos, shipId, shipOrient));

	navy_.push_back(NavyFactory::createShip(shipPos, shipId, shipOrient));
}

bool Player::isMoveAlready(Position pos)
{
		for (int i = 0; i < hits_.size(); ++i) {
			if (pos == hits_[i])
				return true;
		}
		return false;
}

bool Player::isHitShip(Position pos)
{
	for (int i = 0; i < navy_.size(); ++i) {
		if (navy_[i]->isFree(pos))
			return false;
	}
	return true;
}

Player::~Player()
{
}

