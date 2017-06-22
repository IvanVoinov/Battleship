 #include "Computer.h"
#include "Utility.h"
#include "Position.h"
#include "Constants.h"

using namespace Constants;

Position Computer::makeMove()
{
	Position hitPosition;
	do {
		hitPosition.xPosition = Utility::randomInt(FIELD_SIZE);
		hitPosition.yPosition = Utility::randomInt(FIELD_SIZE);
	} while (isMoveAlready(hitPosition));
	hits_.push_back(hitPosition);
	return hitPosition;
}

