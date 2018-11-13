#include "coord.h"

OnlineGame::Coord::Coord(int r, int c)
 :	row{r},
	col{c}
{
}

bool OnlineGame::Coord::in_size(Coord a) const
{
	return row >= 0 && row < a.row && col >= 0 && col < a.col;
}

bool OnlineGame::Coord::on_side(Coord a) const
{
	if (!in_size(a))
		return false;

	return row == 0 || row == a.row-1 || col == 0 || col == a.col - 1;
}

bool operator==(const OnlineGame::Coord &a, const OnlineGame::Coord &b)
{
	return a.row == b.row && a.col == b.col;
}

bool operator!=(const OnlineGame::Coord &a, const OnlineGame::Coord &b)
{
	return !(a == b);
}
