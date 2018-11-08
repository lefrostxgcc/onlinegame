#include "game.h"
#include <numeric>

OnlineGame::Game::Game(std::unique_ptr<IView> v)
 :	view{std::move(v)}
{
}

void OnlineGame::Game::start(const Level &l)
{
	level = l;
	view->clear();
	view->welcome();

	for (auto x : level)
		view->show(x.coord(), x.data());

	user1_coord = Coord{level.get_size().row / 2, level.get_size().col / 2};
	move(0, 0);
}

void OnlineGame::Game::move(int srow, int scol)
{
	Coord move_coord{user1_coord.row + srow, user1_coord.col + scol};
	level[user1_coord] = Subject::space;
	level[move_coord] = Subject::user1;
	view->show(user1_coord, Subject::space);
	view->show(move_coord, Subject::user1);
	user1_coord = move_coord;
	view->refresh();
}
