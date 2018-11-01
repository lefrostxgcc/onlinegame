#include <ncurses.h>
#include <memory>
#include <utility>
#include "view_basic.h"
#include "view_color.h"
#include "game.h"
#include "controller.h"

int main()
{
	using namespace OnlineGame;

	initscr();
	start_color();
 	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	std::unique_ptr<IView> view = std::make_unique<ViewColor>();
	std::unique_ptr<Game> game = std::make_unique<Game>(std::move(view));
	Controller controller {std::move(game)};

	controller.run();

	endwin();

	return 0;
}
