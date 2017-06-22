#include "Player.h"
#include "Position.h"
#include "Ship.h"
#include "Utility.h"

bool Player::isPossibleToPlace(const Position& pos, const ShipID& shipId, const ShipOrientation& shipOrient) const
{
	int shipSize = shipId;
	if (shipOrient == SHIP_ORIENTATION_HORIZONTAL) {
		return isPossibleHorizontal(pos, shipSize);
	}
	else if (shipOrient == SHIP_ORIENTATION_VERTICAL) {
		return isPossibleVertical(pos, shipSize);

	}
	return true;
}

bool Player::isPossibleVertical(const Position &pos, int shipSize) const
{
	for (int x = pos.xPosition - 1; x < pos.xPosition + 3; ++x) {
		for (int y = pos.yPosition - 1; y < pos.yPosition + shipSize + 2; ++y) {
			Position current(x, y);
			bool isFutureShip = pos.xPosition == x && y < pos.yPosition + shipSize && pos.yPosition <= y;
			if (!isCurrentPossibleToPlace(isFutureShip, current))
				return false;
		}
	}
	return true;
}

bool Player::isPossibleHorizontal(const Position &pos, int shipSize) const
{
	for (int x = pos.xPosition - 1; x < pos.xPosition + shipSize + 2; ++x) {
		for (int y = pos.yPosition - 1; y < pos.yPosition + 3; ++y) {
			Position current(x, y);
			bool isFutureShip = pos.xPosition <= x && x < pos.xPosition + shipSize && y == pos.yPosition;
			if (!isCurrentPossibleToPlace(isFutureShip, current))
				return false;
		}
	}
	return true;
}

bool Player::isCurrentPossibleToPlace(bool isFutureShip, const Position& current) const
{
	if (isFutureShip) {
		if (!isInsideBorder(current) || !isPositionFree(current)) {
			return false;
		}
	}
	else if (!isPositionFree(current))
		return false;
}

bool Player::isInsideBorder(const Position& pos) const
{
	if (pos.xPosition >= 0 && pos.xPosition < 10 && pos.yPosition >= 0 && pos.yPosition < 10)
		return true;
	return false;
}

bool Player::isPositionFree(const Position& pos) const
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
			generateSingleShip(SHIP_ID_ONE_DECK);
	}
}

void Player::generateSingleShip(const ShipID& shipId)
{
	int orientation;
	ShipOrientation shipOrient;
	Position shipPos;
	do  {
		shipPos.xPosition = Utility::randomInt(fieldSize_);
		shipPos.yPosition = Utility::randomInt(fieldSize_);
		orientation = Utility::randomInt(shipOrient_);
		shipOrient = static_cast<ShipOrientation>(orientation);
	} while (!isPossibleToPlace(shipPos, shipId, shipOrient));
	navy_.push_back(NavyFactory::createShip(shipPos, shipId, shipOrient));
}

bool Player::isMoveAlready(const Position& pos) const
{
		for (int i = 0; i < hits_.size(); ++i) {
			if (pos == hits_[i])
				return true;
		}
		return false;
}

bool Player::isHitShip(const Position& pos) const
{
	for (int i = 0; i < navy_.size(); ++i) {
		if (navy_[i]->isFree(pos))
			return false;
	}
	return true;
}

bool Player::areAllShipsKilled() const
{
	int killedCounter = 0;
	for (int i = 0; i < navy_.size(); ++i) {
		if (navy_[i]->isKilled())
			killedCounter++;
	}

	return killedCounter == navy_.size();
}

void Player::damageShip(const Position & pos)
{
	for (int i = 0; i < navy_.size(); ++i) {
		navy_[i]->damage(pos);
	}
}

Player::~Player()
{
	for (int i = 0; i < navy_.size(); ++i)
		delete navy_[i];
}

