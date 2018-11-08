#include "coord.h"

OnlineGame::Coord::Coord(int r, int c)
 :	row{r},
	col{c}
{
}

bool OnlineGame::Coord::in_size(const Coord &other) const
{
	return row >= 0 && row < other.row && col >= 0 && col < other.col;
}
