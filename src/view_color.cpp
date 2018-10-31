#include <ncurses.h>
#include "view_color.h"

OnlineGame::ViewColor::ViewColor()
{

}

OnlineGame::ViewColor::~ViewColor()
{
	//attroff(COLOR_PAIR(1));
}

void OnlineGame::ViewColor::welcome()
{
	erase();
	printw("Welcome to the Online Game!\n");
}

void OnlineGame::ViewColor::show(int row, int col, int symbol)
{
	mvaddch(row, col, symbol);
}

void OnlineGame::ViewColor::refresh()
{
	::refresh();
}
