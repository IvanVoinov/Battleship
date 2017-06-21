#include <time.h>
#include <iostream>
#include <cstdlib>
#include "Position.h"
#include "Human.h"


int main()
{
	Human human;
	human.makeMove();
	srand(time(NULL));

	system("pause");
}