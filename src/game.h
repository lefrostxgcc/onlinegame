#ifndef ONLINEGAME_GAME_H
#define ONLINEGAME_GAME_H
#include "view_color.h"

namespace OnlineGame
{
	class Game
	{
	public:
		explicit Game(const ViewColor &view);
		void start();
		void move(int srow, int scol);
	private:
		ViewColor view;
		int row{5};
		int col{10};
	};
}
#endif /* ONLINEGAME_GAME_H */
