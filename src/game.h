#ifndef ONLINEGAME_GAME
#define ONLINEGAME_GAME
#include <thread>
#include <memory>
#include <mutex>
#include "view_color.h"

namespace OnlineGame
{
	class Game
	{
	public:
		explicit Game(ViewColor view);
		void start();
		void move(int srow, int scol);
	private:
		void run();
		std::thread mv_thread;
		std::unique_ptr<std::mutex> srow_scol_mutex;
		ViewColor view;
		int row{5};
		int col{10};
		int srow{};
		int scol{};
	};
}
#endif /* ONLINEGAME_GAME */
