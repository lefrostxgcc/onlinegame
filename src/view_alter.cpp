#include <ncurses.h>
#include "view_alter.h"

OnlineGame::ViewAlter::ViewAlter()
{
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
}

void OnlineGame::ViewAlter::welcome()
{
	printw("Welcome to the Online Alter Game!\n");
}

void OnlineGame::ViewAlter::show(int row, int col, Subject s)
{
	mvaddch(row, col, static_cast<int>(s));
}

void OnlineGame::ViewAlter::clear()
{
	erase();
}

void OnlineGame::ViewAlter::refresh()
{
	::refresh();
}
