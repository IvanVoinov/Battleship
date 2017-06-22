#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer: public Player
{
public:
	virtual Position makeMove();
private:
	const int filedSize_ = 10;
};

#endif COMPUTER_H