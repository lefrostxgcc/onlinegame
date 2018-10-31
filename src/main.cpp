#include "view_color.h"
#include "game.h"
#include "controller.h"
#include <ncurses.h>

int main()
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
	keypad(stdscr, true);
	noecho();

	OnlineGame::ViewColor view;
	OnlineGame::Game game{std::move(view)};
	OnlineGame::Controller controller{std::move(game)};

	controller.run();

	attroff(COLOR_PAIR(1));
	endwin();

	return 0;
}
