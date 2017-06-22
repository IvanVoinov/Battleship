 #include "Computer.h"
#include "Utility.h"
#include "Position.h"

Position Computer::makeMove()
{
	Position hitPosition;
	do {
		hitPosition.xPosition = Utility::randomInt(filedSize_);
		hitPosition.yPosition = Utility::randomInt(filedSize_);
	} while (isMoveAlready(hitPosition));
	hits_.push_back(hitPosition);
	return hitPosition;
}

