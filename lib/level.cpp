#include "level.h"
#include <algorithm>

OnlineGame::Level::Level(const Coord &coord)
 :	map{coord.row, coord.col},
	size{coord}
{
	init();
}

void OnlineGame::Level::init()
{
	int row_count = map.row_count();
	int col_count = map.col_count();

	for (int row = 0; row < row_count; row++)
		for (int col = 0; col < col_count; col++)
			if (row == 0 || row == row_count-1 ||
				col == 0 || col == col_count-1)
					map(row, col) = Subject::block;
			else
				map(row, col) = Subject::space;

	map(row_count/2, col_count/2) = Subject::user1;
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
