#include <ncurses.h>
#include "view_color.h"

OnlineGame::ViewColor::ViewColor()
{
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
}

void OnlineGame::ViewColor::welcome()
{
	printw("Welcome to the Online Game!\n");
}

void OnlineGame::ViewColor::show(int row, int col, int symbol)
{
	mvaddch(row, col, symbol);
}

void OnlineGame::ViewColor::clear()
{
	erase();
}

void OnlineGame::ViewColor::refresh()
{
	::refresh();
}
