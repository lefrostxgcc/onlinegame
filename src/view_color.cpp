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

void OnlineGame::ViewColor::show(Coord coord, Subject s)
{
	mvaddch(coord.row, coord.col, static_cast<int>(s));
}

void OnlineGame::ViewColor::clear()
{
	erase();
}

void OnlineGame::ViewColor::refresh()
{
	::refresh();
}
