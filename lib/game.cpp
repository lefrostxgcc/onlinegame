#include "game.h"

OnlineGame::Game::Game(std::unique_ptr<IView> v)
 :	view{std::move(v)}
{
}

void OnlineGame::Game::start(std::unique_ptr<Level> l)
{
	level.swap(l);
	view->clear();
	view->welcome();
	move(0, 0);
}

void OnlineGame::Game::move(int srow, int scol)
{
	Coord move_coord{user1_coord.row + srow, user1_coord.col + scol};
	(*level)[user1_coord] = Subject::space;
	(*level)[move_coord] = Subject::user1;
	view->show(user1_coord, Subject::space);
	view->show(move_coord, Subject::user1);
	user1_coord = move_coord;
	view->refresh();
}
