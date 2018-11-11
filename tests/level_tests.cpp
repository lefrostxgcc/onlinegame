#include <catch2/catch.hpp>
#include <level.h>

TEST_CASE("Level constructor", "[constructor]")
{
	using OnlineGame::Coord;

	OnlineGame::Level level{Coord{3, 5}};

	// #####
	// # 1$#
	// #####

	SECTION("Level constructor correct size")
	{
		REQUIRE(level.get_size().row == 3);
		REQUIRE(level.get_size().col == 5);
	}

	SECTION("Level constructor correct block coords")
	{
		Coord block_coords[] =
		{
			Coord{0, 0}, Coord{0, 1}, Coord{0, 2}, Coord{0, 3}, Coord{0, 4},
			Coord{1, 0}, Coord{1, 4},
			Coord{2, 0}, Coord{2, 1}, Coord{2, 2}, Coord{2, 3}, Coord{2, 4}
		};

		for (auto x : block_coords)
			REQUIRE(level.get_subject(x) == OnlineGame::Subject::block);
	}

	SECTION("Level constructor correct space coords")
	{
		Coord space_coord{1, 1};
		REQUIRE(level.get_subject(space_coord) == OnlineGame::Subject::space);
	}

	SECTION("Level constructor correct user1 coord")
	{
		Coord user1_coord{1, 2};
		REQUIRE(level.get_subject(user1_coord) == OnlineGame::Subject::user1);
	}

	SECTION("Level constructor correct money coord")
	{
		Coord money_coord{1, 3};
		REQUIRE(level.get_subject(money_coord) == OnlineGame::Subject::money);
	}
}
