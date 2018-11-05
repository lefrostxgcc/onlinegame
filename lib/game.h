#ifndef ONLINEGAME_GAME_H
#define ONLINEGAME_GAME_H
#include <memory>
#include "iview.h"
#include "level.h"

namespace OnlineGame
{
	class Game
	{
	public:
		explicit Game(std::unique_ptr<IView> view);
		void start(std::unique_ptr<Level> level);
		void move(int srow, int scol);
	private:
		std::unique_ptr<IView> view;
		std::unique_ptr<Level> level{};
		Coord user1_coord{5, 10};
	};
}
#endif /* ONLINEGAME_GAME_H */
