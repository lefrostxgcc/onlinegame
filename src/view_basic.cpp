#include <ncurses.h>
#include "view_basic.h"

void OnlineGame::ViewBasic::welcome()
{
	printw("Welcome to the Online Game!\n");
}

void OnlineGame::ViewBasic::show(Coord coord, Subject s)
{
	mvaddch(coord.row, coord.col, static_cast<int>(s));
}

void OnlineGame::ViewBasic::clear()
{
	erase();
}

void OnlineGame::ViewBasic::refresh()
{
	::refresh();
}
