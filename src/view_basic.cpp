#include <ncurses.h>
#include "view_basic.h"

void OnlineGame::View::welcome()
{
	::erase();
	::printw("Welcome to the Online Game!\n");
}

void OnlineGame::View::show(int row, int col, int symbol)
{
	mvaddch(row, col, symbol);
}

void OnlineGame::View::refresh()
{
	::refresh();
}
