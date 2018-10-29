#include <ncurses.h>
#include "view.h"
#include "game.h"

namespace
{
	void start()
	{
		OnlineGame::View view;
		OnlineGame::Game game{view};

		game.start();

		while (true)
		{
			refresh();
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
}

int main()
{
	initscr();
	keypad(stdscr, true);
	noecho();
	start();
	endwin();

	return 0;
}
