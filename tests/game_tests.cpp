#include <catch2/catch.hpp>
#include <memory>
#include <vector>
#include <algorithm>
#include <game.h>

using namespace OnlineGame;

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
		static std::vector<Coord> shown_coords;
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
		View::shown_coords.push_back(coord);
	}

	void View::show_money_count(Coord coord, int money_count)
	{
	}

	void View::reset_counters()
	{
		View::welcome_count = 0;
		View::clear_count = 0;
		View::refresh_count = 0;
		shown_coords.clear();
	}

	int View::welcome_count = 0;
	int View::clear_count = 0;
	int View::refresh_count = 0;
	std::vector<Coord> View::shown_coords;
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
			{
				size_t i;
				for (i = 0; i < View::shown_coords.size(); i++)
					if (View::shown_coords[i] == Coord{row, col})
					{
						REQUIRE(View::shown_coords[i] == Coord{row, col});
						break;
					}
				if (i == View::shown_coords.size())
					REQUIRE(false);
			}
	}
}
