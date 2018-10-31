#ifndef ONLINEGAME_CONTROLLER_H
#define ONLINEGAME_CONTROLLER_H
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
	};
}
#endif /* ONLINEGAME_CONTROLLER_H */
