#ifndef ONLINEGAME_GAME_H
#define ONLINEGAME_GAME_H
#include <memory>
#include "iview.h"

namespace OnlineGame
{
	class Game
	{
	public:
		explicit Game(std::unique_ptr<IView> view);
		void start();
		void move(int srow, int scol);
	private:
		std::unique_ptr<IView> view;
		int row{5};
		int col{10};
	};
}
#endif /* ONLINEGAME_GAME_H */
