#include <ncurses.h>
#include "controller.h"
OnlineGame::Controller::Controller(std::unique_ptr<Game> g)
	: game{std::move(g)}
{
}

void OnlineGame::Controller::run()
{
	Level level{Coord{10, 40}};
	game->start(level);

	while (true)
	{
		switch (getch())
		{
			case KEY_DOWN	: game->move(1, 0);		break;
			case KEY_UP		: game->move(-1, 0);	break;
			case KEY_LEFT	: game->move(0, -1);	break;
			case KEY_RIGHT	: game->move(0, 1);		break;
			case 'q'		: return;
		}
	}
}
