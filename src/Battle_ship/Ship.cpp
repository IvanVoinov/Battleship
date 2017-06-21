#include "Ship.h"

bool Ship::isFree(Position pos)
{
	for (int i = 0; i < position_.size(); ++i) {
		if (position_[i] == pos)
			return false;
	}
	return true;
}

Ship::~Ship()
{
}
