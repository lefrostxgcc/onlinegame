#ifndef ONLINEGAME_CONTROLLER
#define ONLINEGAME_CONTROLLER
#include "view.h"
#include "game.h"
namespace OnlineGame
{
	class Controller
	{
	public:
		explicit Controller(const Game &game);
		void run();
	private:
		Game game;
		View view;
	};
}
#endif /* ONLINEGAME_CONTROLLER */
