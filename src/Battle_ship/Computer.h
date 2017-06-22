#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer: public Player
{
public:
	virtual Position makeMove();
};

#endif COMPUTER_H