#ifndef ONLINEGAME_CONTROLLER_H
#define ONLINEGAME_CONTROLLER_H
#include <memory>
#include "game.h"
namespace OnlineGame
{
	class Controller
	{
	public:
		explicit Controller(std::unique_ptr<Game> game);
		void run();
	private:
		std::unique_ptr<Game> game;
	};
}
#endif /* ONLINEGAME_CONTROLLER_H */
