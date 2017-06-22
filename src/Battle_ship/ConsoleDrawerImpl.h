#ifndef CONSOLE_DRAWER_IMPL_H
#define CONSOLE_DRAWER_IMPL_H

#include <windows.h>
#include <iostream>

#include "DrawerImplBase.h"
#include "Position.h"

class ConsoleDrawerImpl : public DrawerImplBase
{
public:
	ConsoleDrawerImpl();
	virtual void drawCell(const int& xPos, const int& yPos, const CellType& cellType);
	void drawChar(const int& xPos, const int& yPos, char& ch);
	virtual void resetCursor(const int& xPos, const int& yPos);
	void clearScreen();
private:
	HANDLE handleOut_;
};

#endif CONSOLE_DRAWER_IMPL_H