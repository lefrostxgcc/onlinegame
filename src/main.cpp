#include "view.h"
#include "game.h"
#include "controller.h"

int main()
{
	OnlineGame::View view;
	OnlineGame::Game game{view};
	OnlineGame::Controller controller{game};

	controller.run();

	return 0;
}
