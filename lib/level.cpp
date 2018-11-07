#include "level.h"

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

const OnlineGame::Subject&
OnlineGame::Level::operator[](const Coord &coord) const
{
	return map(coord.row, coord.col);
}

OnlineGame::Subject& OnlineGame::Level::operator[](const Coord &coord)
{
	return map(coord.row, coord.col);
}

OnlineGame::Coord OnlineGame::Level::get_size() const noexcept
{
	return size;
}
