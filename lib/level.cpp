#include <algorithm>
#include <vector>
#include <random>
#include "level.h"

OnlineGame::Level::Level(const Coord &coord)
 :	map{coord.row, coord.col},
	size{coord}
{
	init();
}

void OnlineGame::Level::init()
{
	for (auto &x : map)
		if (x.coord().on_side(size))
			map(x.coord().row, x.coord().col) = Subject::block;
		else
			map(x.coord().row, x.coord().col) = Subject::space;

	map(map.row_count()/2, map.col_count()/2) = Subject::user1;
	map(map.row_count()/2, map.col_count()/2 + 1) = Subject::money;
}

void OnlineGame::Level::set_subject(const Coord &coord, Subject subject)
{
	if (coord.in_size(size))
		map(coord.row, coord.col) = subject;
}

OnlineGame::Subject OnlineGame::Level::get_subject(const Coord &coord) const
{
	if (coord.in_size(size))
		return map(coord.row, coord.col);
	return Subject::nulls;
}

OnlineGame::Level::iterator OnlineGame::Level::find_first(Subject s)
{
	return std::find(map.begin(), map.end(), s);
}

OnlineGame::Level::iterator OnlineGame::Level::find_random(Subject s)
{
	std::vector<iterator> v;

	for (auto p = begin(); p != end(); p++)
		if (p->data() == s)
			v.push_back(p);

	using index_type = std::vector<iterator>::size_type;

	if (v.empty())
		return end();

	std::uniform_int_distribution<index_type> dist{0, v.size() - 1};
	std::random_device dev;

	auto it_v = v[dist(dev)];
	for (auto p = begin(); p != end(); p++)
		if (p == it_v)
			return p;
	
	return end();
}

OnlineGame::Coord OnlineGame::Level::get_size() const noexcept
{
	return size;
}

OnlineGame::Level::iterator OnlineGame::Level::begin()
{
	return map.begin();
}

OnlineGame::Level::iterator OnlineGame::Level::end()
{
	return map.end();
}

void OnlineGame::Level::eat_money(Coord money_coord)
{
	if (get_subject(money_coord) == Subject::money)
		money_count++;
}

int OnlineGame::Level::get_money_count() const noexcept
{
	return money_count;
}
