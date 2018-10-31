#include <utility>
#include <ncurses.h>
#include "controller.h"

OnlineGame::Controller::Controller(const Game &g)
	: game{g}
{
	game.start();
}

void OnlineGame::Controller::run()
{
	int key = ERR, newkey = ERR;

	while (true)
	{
		if ((newkey = getch()) != ERR)
			key = newkey;
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
