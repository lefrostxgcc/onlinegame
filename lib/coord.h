#ifndef ONLINEGAME_COORD_H
#define ONLINEGAME_COORD_H
namespace OnlineGame
{
	struct Coord {
		Coord() = default;
		Coord(int row, int col);
		bool in_size(Coord other) const;
		bool on_side(Coord other) const;
		int row{};
		int col{};
	};
}

	bool operator==(const OnlineGame::Coord &a, const OnlineGame::Coord &b);
	bool operator!=(const OnlineGame::Coord &a, const OnlineGame::Coord &b);

#endif /* ONLINEGAME_COORD_H */
