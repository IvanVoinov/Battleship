 #include "Computer.h"
#include "Utility.h"
#include "Position.h"

void Computer::makeMove()
{
	int fieldSize = 10;
	Position hitPosition;

	do {
		hitPosition.xPosition = Utility::randomInt(fieldSize);
		hitPosition.yPosition = Utility::randomInt(fieldSize);
	} while (isMoveAlready(hitPosition));
	hits_.push_back(hitPosition);
}

