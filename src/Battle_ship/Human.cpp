#include <iostream>

#include "Human.h"

void Human::makeMove()
{
	int yCoord;
	char xCoord;
	Position pos;
	std::cout << "Enter your turn in a format \" Character + Number\". Like A1." << std::endl;
	while (std::cin >> xCoord >> yCoord) {
		if (xCoord >= 'A' && xCoord <= 'J' && yCoord >= 0 && yCoord <= 9) {
			pos.xPosition = xCoord - 'A';
			pos.yPosition = yCoord;
			hits_.push_back(pos);
			std::cout << pos.xPosition << std::endl;
			std::cout << pos.yPosition << std::endl;
			break;
		}
		else
			std::cout << "Wrong input. Try again." << std::endl;
	}
}

