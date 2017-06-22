#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "NavyFactory.h"
#include "Constants.h"

class Player
{
public:
	virtual Position makeMove() = 0;
	void generateShips();
	void generateSingleShip(const Constants::ShipID& shipId);
	bool isPossibleToPlace(const Position& pos, const Constants::ShipID& shipId, const Constants::ShipOrientation& shipOrient) const;
	bool isInsideBorder(const Position& pos) const;
	bool isPositionFree(const Position& pos) const;
	bool isMoveAlready(const Position& pos) const;
	bool isHitShip(const Position& pos) const;
	bool areAllShipsKilled() const;
	void damageShip(const Position& pos);
	virtual ~Player();
protected:
	std::vector<Ship*> navy_;
	std::vector<Position> hits_;
private:
	bool isPossibleVertical(const Position &pos, int shipSize) const;
	bool isPossibleHorizontal(const Position &pos, int shipSize) const;
	bool isCurrentPossibleToPlace(bool isFutureShip, const Position& current) const;
};

#endif PLAYER_H