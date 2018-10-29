#include <ncurses.h>

namespace
{
	void start()
	{
		printw("Welcome to the Online Game!\n");
		refresh();
		getch();
	}
}

int main()
{
	initscr();
	start();
	endwin();

	return 0;
}
