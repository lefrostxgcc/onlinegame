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

	user1_coord = level.find_first(Subject::user1)->coord();
	move(0, 0);
}

void OnlineGame::Game::move(int srow, int scol)
{
	Coord move_coord{user1_coord.row + srow, user1_coord.col + scol};
	if (!move_coord.in_size(level.get_size()))
		return;
	Subject s = level.get_subject(move_coord);
	if (s == Subject::nulls)
		return;
	else if (s == Subject::block)
		return;
	else if (s == Subject::space)
	{
		level.set_subject(user1_coord, Subject::space);
		level.set_subject(move_coord, Subject::user1);
		view->show(user1_coord, Subject::space);
		view->show(move_coord, Subject::user1);
		user1_coord = move_coord;
		view->refresh();
	}
}
