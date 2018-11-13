#include <catch2/catch.hpp>
#include <memory>
#include <map>
#include <game.h>

using namespace OnlineGame;

namespace OnlineGame {
	inline bool operator<(const OnlineGame::Coord &a, const OnlineGame::Coord &b)
	{
		if (a.row < b.row)
			return true;
		else if (a.row == b.row)
			return a.col < b.col;
		return false;
	}
}
namespace {
	class View: public IView {
	public:
		View();
		void welcome() override;
		void show(Coord coord, Subject s) override;
		void show_money_count(Coord coord, int money_count) override;
		void clear() override;
		void refresh() override;
		static int welcome_count;
		static int clear_count;
		static int refresh_count;
		static int money_count;
		static std::map<Coord, Subject> shown_coords;
		static void reset_counters();
	};

	View::View()
	{
		reset_counters();
	}

	void View::welcome()
	{
		View::welcome_count++;
	}

	void View::clear()
	{
		View::clear_count++;
	}

	void View::refresh()
	{
		View::refresh_count++;
	}

	void View::show(Coord coord, Subject s)
	{
		View::shown_coords[coord] = s;
	}

	void View::show_money_count(Coord coord, int m_count)
	{
		View::money_count = m_count;
	}

	void View::reset_counters()
	{
		View::welcome_count = 0;
		View::clear_count = 0;
		View::refresh_count = 0;
		View::money_count = 0;
		shown_coords.clear();
	}

	int View::welcome_count = 0;
	int View::clear_count = 0;
	int View::refresh_count = 0;
	int View::money_count = 0;
	std::map<Coord, Subject> View::shown_coords;
}

TEST_CASE("Game start", "[start]")
{
	Game game{std::make_unique<View>()};
	int wc = View::welcome_count;
	int cc = View::clear_count;
	Level level{Coord{3, 5}};

	REQUIRE_NOTHROW(game.start(level));

	SECTION("Game start view clear && view welcome")
	{
		REQUIRE(View::welcome_count == wc + 1);
		REQUIRE(View::clear_count == cc + 1);
	}

	SECTION("Game start show level")
	{
		int rows = level.get_size().row;
		int cols = level.get_size().col;

		for (int row = 0; row < rows; row++)
			for (int col = 0; col < cols; col++)
				REQUIRE(View::shown_coords.find(Coord{row, col}) !=
					View::shown_coords.end());
	}
}

TEST_CASE("Game move", "[move]")
{
	Game game{std::make_unique<View>()};
	Level level{Coord{3, 5}};
	int money = View::money_count;
	int refresh = View::refresh_count;

	game.start(level);

	SECTION("Game move out of level size down")
	{
		auto temp = View::shown_coords;
		game.move(level.get_size().row, 5);
		REQUIRE(temp == View::shown_coords);
		REQUIRE(View::money_count == money);
		REQUIRE(View::refresh_count == refresh);
	}

	SECTION("Game move out of level size up")
	{
		auto temp = View::shown_coords;
		game.move(-level.get_size().row, 0);
		REQUIRE(temp == View::shown_coords);
		REQUIRE(View::money_count == money);
		REQUIRE(View::refresh_count == refresh);
	}

	SECTION("Game move out of level size right")
	{
		auto temp = View::shown_coords;
		game.move(0, level.get_size().col);
		REQUIRE(temp == View::shown_coords);
		REQUIRE(View::money_count == money);
		REQUIRE(View::refresh_count == refresh);
	}

	SECTION("Game move out of level size left")
	{
		auto temp = View::shown_coords;
		game.move(0, -level.get_size().col);
		REQUIRE(temp == View::shown_coords);
		REQUIRE(View::money_count == money);
		REQUIRE(View::refresh_count == refresh);
	}

	SECTION("Game move no move")
	{
		auto temp = View::shown_coords;
		game.move(0, 0);
		REQUIRE(temp == View::shown_coords);
		REQUIRE(View::money_count == money);
	}

	SECTION("Game move up")
	{
		auto temp = View::shown_coords;
		game.move(-1, 0);
		REQUIRE(temp == View::shown_coords);
		REQUIRE(View::money_count == money);
		REQUIRE(View::refresh_count == refresh);
	}

	SECTION("Game move down")
	{
		auto temp = View::shown_coords;
		game.move(1, 0);
		REQUIRE(temp == View::shown_coords);
		REQUIRE(View::money_count == money);
		REQUIRE(View::refresh_count == refresh);
	}

	SECTION("Game move left")
	{
		game.move(0, -1);
		REQUIRE(View::shown_coords.find(Coord{1, 1})->second == Subject::user1);
		REQUIRE(View::shown_coords.find(Coord{1, 2})->second == Subject::space);
		REQUIRE(View::shown_coords.find(Coord{1, 3})->second == Subject::money);
		REQUIRE(View::money_count == money);
		REQUIRE(View::refresh_count == refresh + 1);
	}

	SECTION("Game move right eat money")
	{
		game.move(0, 1);
		REQUIRE(View::shown_coords.find(Coord{1, 1})->second == Subject::money);
		REQUIRE(View::shown_coords.find(Coord{1, 2})->second == Subject::space);
		REQUIRE(View::shown_coords.find(Coord{1, 3})->second == Subject::user1);
		REQUIRE(View::money_count == money + 1);
		REQUIRE(View::refresh_count == refresh + 1);
	}
}
