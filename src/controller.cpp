#include "controller.h"
#include <ncurses.h>

OnlineGame::Controller::Controller(Game g)
	: game{std::move(g)}
{
	::initscr();
	::clear();
	::keypad(stdscr, true);
	::noecho();
	game.start();
}

OnlineGame::Controller::~Controller()
{
	::endwin();
}

void OnlineGame::Controller::run()
{
	while (true)
	{
		view.refresh();
		int key = getch();
		switch (key)
		{
			case KEY_DOWN	: game.move(1, 0);	break;
			case KEY_UP	: game.move(-1, 0);	break;
			case KEY_LEFT	: game.move(0, -1);	break;
			case KEY_RIGHT	: game.move(0, 1);	break;
			case 'q'	: return;
		}
	}
}
