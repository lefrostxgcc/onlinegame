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

void OnlineGame::ViewBasic::show_money_count(Coord coord, int money_count)
{
	mvprintw(coord.row, coord.col, "Money: %d", money_count);
}

void OnlineGame::ViewBasic::clear()
{
	erase();
}

void OnlineGame::ViewBasic::refresh()
{
	::refresh();
}
