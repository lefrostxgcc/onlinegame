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
		void start(const Level &level);
		void move(int srow, int scol);
	private:
		void move_user(Coord move_coord);
		void eat_money(Coord money_coord);
		void show_money_count();
		std::unique_ptr<IView> view;
		Level level;
		Coord user1_coord{5, 10};
	};
}
#endif /* ONLINEGAME_GAME_H */
