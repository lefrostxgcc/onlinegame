#include <ncurses.h>
#include "view_color.h"

void OnlineGame::ViewColor::welcome()
{
	::erase();
	::printw("Welcome to the Online Game!\n");
}

void OnlineGame::ViewColor::show(int row, int col, int symbol)
{
	mvaddch(row, col, symbol);
}

void OnlineGame::ViewColor::refresh()
{
	::refresh();
}
