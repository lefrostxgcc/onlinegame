#include <ncurses.h>
#include "view.h"

namespace
{
	void start()
	{
		int row{5}, col{7}, key;
		OnlineGame::View view;

		view.welcome();

		while (true)
		{
			view.show(row, col, 'O');
			refresh();
			key = getch();
			view.show(row, col, ' ');
			switch (key)
			{
				case KEY_DOWN	: row++; break;
				case KEY_UP	: row--; break;
				case KEY_LEFT	: col--; break;
				case KEY_RIGHT	: col++; break;
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
