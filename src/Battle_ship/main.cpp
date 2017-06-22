#include <time.h>
#include <iostream>
#include <cstdlib>
#include "ConsoleDrawerImpl.h"
#include "Game.h"

int main()
{
	srand(time(NULL));
	ConsoleDrawerImpl drw;
	Game game(drw);
	game.run();
	return 0;
}