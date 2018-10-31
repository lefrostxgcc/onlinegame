#include "game.h"

OnlineGame::Game::Game(const ViewColor &v)
 :	view{v}
{
}

void OnlineGame::Game::start()
{
	view.welcome();
	move(0, 0);
}

void OnlineGame::Game::move(int srow, int scol)
{
	view.show(row, col, ' ');
	row += srow;
	col += scol;
	view.show(row, col, 'O');
	view.refresh();
}
