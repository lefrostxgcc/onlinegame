#ifndef ONLINEGAME_GAME
#define ONLINEGAME_GAME
#include <thread>
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
		void run();
		std::thread mv_thread;
		View view;
		int row{5};
		int col{10};
		int srow{};
		int scol{};
	};
}
#endif /* ONLINEGAME_GAME */
