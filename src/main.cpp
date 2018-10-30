#include "view.h"
#include "game.h"
#include "controller.h"

int main()
{
	OnlineGame::View view;
	OnlineGame::Game game{std::move(view)};
	OnlineGame::Controller controller{std::move(game)};

	controller.run();

	return 0;
}
