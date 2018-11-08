#ifndef ONLINEGAME_COORD_H
#define ONLINEGAME_COORD_H
namespace OnlineGame
{
	struct Coord {
		Coord() = default;
		Coord(int row, int col);
		bool in_size(const Coord &other) const;
		int row{};
		int col{};
	};
}
#endif /* ONLINEGAME_COORD_H */
