#include <algorithm>
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
