#include <chrono>
#include "game.h"

OnlineGame::Game::Game(ViewColor v)
 :	view{std::move(v)},
	srow_scol_mutex(new std::mutex{})
{
}

void OnlineGame::Game::start()
{
	view.welcome();
	move(0, 0);
	mv_thread = std::move(std::thread(&Game::run, std::ref(*this)));
	mv_thread.detach();
}

void OnlineGame::Game::move(int sr, int sc)
{
	std::lock_guard<std::mutex> lock(*srow_scol_mutex);
	srow = sr;
	scol = sc;
}

void OnlineGame::Game::run()
{
	using namespace std::chrono_literals;

	while (true)
	{
		view.show(row, col, ' ');
		{
			std::lock_guard<std::mutex> lock(*srow_scol_mutex);
			row += srow;
			col += scol;
		}
		view.show(row, col, 'O');
		view.refresh();

		std::this_thread::sleep_for(100ms);
	}
}
