#include "game.h"

OnlineGame::Game::Game(std::unique_ptr<IView> v)
 :	view{std::move(v)}
{
}

void OnlineGame::Game::start()
{
	view->clear();
	view->welcome();
	move(0, 0);
}

void OnlineGame::Game::move(int srow, int scol)
{
	view->show(row, col, Subject::space);
	row += srow;
	col += scol;
	view->show(row, col, Subject::user1);
	view->refresh();
}
