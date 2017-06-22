#include <iostream>
#include <cctype>
#include <string>

#include "Human.h"

Position Human::makeMove()
{
	int yCoord;
	char xCoord;
	Position pos;
	std::cout << "Enter your turn in a format \" Character + Number\". Like A1." << std::endl;
	do 
	{
		std::cin >> xCoord >> yCoord;
		xCoord = std::toupper(xCoord);
		if (std::cin && xCoord >= 'A' && xCoord <= 'J' && yCoord >= 0 && yCoord <= 9) {
			pos.xPosition = xCoord - 'A';
			pos.yPosition = yCoord;
			if (!isMoveAlready(pos)) {
				hits_.push_back(pos);
				break;
			}
			else {
				std::cout << "Choose another coordinates, buddy!\n";
			}
		}
		else {
			std::string line;
			std::cin.clear();
			std::getline(std::cin, line);
			std::cout << "Wrong input. Try again." << std::endl;
			//std::cin.ignore(INT_MAX, '\n');
		}
	} while (true);

	return pos;
}

