#ifndef ONLINEGAME_GAME
#define ONLINEGAME_GAME
#include "view.h"

namespace OnlineGame
{
	class Game
	{
	public:
		Game(const View &view);
		void start();
		void move(int srow, int scol);
	private:
		View view;
		int row{5};
		int col{10};
	};
}
#endif /* ONLINEGAME_GAME */
