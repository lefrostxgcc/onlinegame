#include <ncurses.h>
#include "view.h"
#include "game.h"
#include "controller.h"

int main()
{
	initscr();
	keypad(stdscr, true);
	noecho();
	OnlineGame::View view;
	OnlineGame::Game game{view};
	OnlineGame::Controller controller{game};
	controller.run();
	endwin();

	return 0;
}
