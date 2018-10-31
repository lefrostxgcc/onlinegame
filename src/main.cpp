#include <ncurses.h>
#include "view_color.h"
#include "game.h"
#include "controller.h"

int main()
{
	initscr();
	start_color();
 	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	timeout(100);

	OnlineGame::ViewColor view;
	OnlineGame::Game game{view};
	OnlineGame::Controller controller{game};

	controller.run();

	endwin();

	return 0;
}
