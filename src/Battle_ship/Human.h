#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player
{
public:
	virtual Position makeMove();
};

#endif HUMAN_H
