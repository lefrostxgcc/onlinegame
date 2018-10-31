#ifndef ONLINEGAME_CONTROLLER
#define ONLINEGAME_CONTROLLER
#include "view_basic.h"
#include "game.h"
namespace OnlineGame
{
	class Controller
	{
	public:
		explicit Controller(Game game);
		~Controller();
		void run();
	private:
		Game game;
		ViewBasic view;
	};
}
#endif /* ONLINEGAME_CONTROLLER */
