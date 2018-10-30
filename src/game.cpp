#include <chrono>
#include <iostream>
#include "game.h"
#include "view.h"

OnlineGame::Game::Game(const View &v)
	: view{v}
{
}

void OnlineGame::Game::start()
{
	view.welcome();
	move(0, 0);
	mv_thread = std::move(std::thread([this]() {return run();}));
	mv_thread.detach();
}

void OnlineGame::Game::move(int sr, int sc)
{
	srow = sr;
	scol = sc;
}

void OnlineGame::Game::run()
{
	using namespace std::chrono_literals;
	while (true)
	{
		view.show(row, col, ' ');
		row += srow;
		col += scol;
		view.show(row, col, 'O');
		view.refresh();

		std::this_thread::sleep_for(100ms);
	}
}
