#include <ncurses.h>
#include "view_basic.h"

void OnlineGame::ViewBasic::welcome()
{
	printw("Welcome to the Online Game!\n");
}

void OnlineGame::ViewBasic::show(int row, int col, int symbol)
{
	mvaddch(row, col, symbol);
}

void OnlineGame::ViewBasic::clear()
{
	erase();
}

void OnlineGame::ViewBasic::refresh()
{
	::refresh();
}
