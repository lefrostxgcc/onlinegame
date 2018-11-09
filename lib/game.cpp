#include <stdexcept>
#include "game.h"

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

	auto p = level.find_first(Subject::user1);
	if ( p != level.end())
		user1_coord = p->coord();
	else
		throw std::logic_error{"User1 is not on the map"};

	move(0, 0);
}

void OnlineGame::Game::move(int srow, int scol)
{
	Coord move_coord{user1_coord.row + srow, user1_coord.col + scol};
	if (!move_coord.in_size(level.get_size()))
		return;
	Subject s = level.get_subject(move_coord);
	if (s == Subject::money)
	{
		eat_money(move_coord);
		move_user(move_coord);
	}
	else if (s == Subject::space)
		move_user(move_coord);

	show_money_count();
}

void OnlineGame::Game::move_user(Coord move_coord)
{
	level.set_subject(user1_coord, Subject::space);
	level.set_subject(move_coord, Subject::user1);
	view->show(user1_coord, Subject::space);
	view->show(move_coord, Subject::user1);
	user1_coord = move_coord;
	view->refresh();
}

void OnlineGame::Game::eat_money(Coord money_coord)
{
	auto p = level.find_random(Subject::space);
	if (p != level.end())
	{
		level.eat_money(money_coord);
		level.set_subject(money_coord, Subject::space);
		level.set_subject(p->coord(), Subject::money);
		view->show(money_coord, Subject::space);
		view->show(p->coord(), Subject::money);
		show_money_count();
	}
}

void OnlineGame::Game::show_money_count()
{
	view->show_money_count(Coord{0, level.get_size().col + 1},
		level.get_money_count());
}
