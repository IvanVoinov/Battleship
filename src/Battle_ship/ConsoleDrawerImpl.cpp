#include <windows.h>
#include "ConsoleDrawerImpl.h"

using namespace Constants;

ConsoleDrawerImpl::ConsoleDrawerImpl() :
	handleOut_(GetStdHandle(STD_OUTPUT_HANDLE))
{
	CONSOLE_CURSOR_INFO ci = {};
	ci.bVisible = false;
	ci.dwSize = sizeof(CONSOLE_CURSOR_INFO);
	SetConsoleCursorInfo(handleOut_, &ci);
}

void ConsoleDrawerImpl::drawCell(const int& xPos, const int& yPos, const CellType& cellType)
{
	resetCursor(xPos, yPos);
	switch (cellType) {
	case CELL_TYPE_EMPTY:
		std::cout << " ";
		break;
	case CELL_TYPE_WALL:
		std::cout << "#";
		break;
	case CELL_TYPE_SHOOTED:
		std::cout << "X";
		break;
	case CELL_TYPE_MISSED:
		std::cout << "O";
		break;
	case CELL_TYPE_SHIP:
		std::cout << "@";
		break;
	}
}

void ConsoleDrawerImpl::drawChar(const int & xPos, const int & yPos, char& ch)
{
	resetCursor(xPos, yPos);
	std::cout << ch;
}

void ConsoleDrawerImpl::resetCursor(const int& xPos, const int& yPos)
{
	COORD coords{ xPos, yPos };
	SetConsoleCursorPosition(handleOut_, coords);
}

void ConsoleDrawerImpl::clearScreen()
{
	system("cls");
}
