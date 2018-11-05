#include "level.h"

OnlineGame::Level::Level(const Coord &coord)
 :	map{coord.row, coord.col},
	size{coord}
{
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
