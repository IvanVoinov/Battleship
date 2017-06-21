#pragma once
#include "DrawerImpl.h"

class Drawer
{
public:
	void drawScene();
	void drawField();
	void drawShips();
	void drawHits();
private:	
	static const int wight_ = 13;
	static const int height_ = 29;
	Drawer* drawer_;
	char field_[wight_][height_] = {
		"  ABCDEFGHIJ     ABCDEFGHIJ ",
		" ############   ############",
		"0|          |  0|          |",
		"1|          |  1|          |",
		"2|          |  2|          |",
		"3|          |  3|          |",
		"4|          |  4|          |",
		"5|          |  5|          |",
		"6|          |  6|          |",
		"7|          |  7|          |",
		"8|          |  8|          |",
		"9|          |  9|          |",
		" ############   ############" };
};
