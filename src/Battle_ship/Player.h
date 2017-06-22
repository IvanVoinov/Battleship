#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "NavyFactory.h"

class Player
{
public:
	virtual Position makeMove() = 0;
	virtual void generateShips();
	virtual void generateSingleShip(const ShipID& shipId);
	virtual bool isPossibleToPlace(const Position& pos, const ShipID& shipId, const ShipOrientation& shipOrient) const;
	virtual bool isInsideBorder(const Position& pos) const;
	virtual bool isPositionFree(const Position& pos) const;
	virtual bool isMoveAlready(const Position& pos) const;
	virtual bool isHitShip(const Position& pos) const;
	virtual bool areAllShipsKilled() const;
	void damageShip(const Position& pos);
	virtual ~Player();
protected:
	std::vector<Ship*> navy_;
	std::vector<Position> hits_;
private:
	bool isPossibleVertical(const Position &pos, int shipSize) const;
	bool isPossibleHorizontal(const Position &pos, int shipSize) const;
	bool isCurrentPossibleToPlace(bool isFutureShip, const Position& current) const;
	const int fieldSize_ = 10;
	const int shipOrient_ = 2;
};

#endif PLAYER_H