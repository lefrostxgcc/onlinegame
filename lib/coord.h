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

	bool operator==(OnlineGame::Coord a, OnlineGame::Coord b);
	bool operator!=(OnlineGame::Coord a, OnlineGame::Coord b);

#endif /* ONLINEGAME_COORD_H */
