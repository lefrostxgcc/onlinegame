#include <catch2/catch.hpp>
#include <coord.h>

TEST_CASE( "Coord constructor", "[constructor]" )
{
	OnlineGame::Coord a{3, 5};
    REQUIRE( a.row == 3 );
    REQUIRE( a.col == 5 );
}

TEST_CASE( "in_size inside size", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{1, 3};
    REQUIRE( coord.in_size(size) );
}

TEST_CASE( "in_size negative row", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{-1, 0};
    REQUIRE_FALSE( coord.in_size(size) );
}

TEST_CASE( "in_size negative col", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{0, -1};
    REQUIRE_FALSE( coord.in_size(size) );
}

TEST_CASE( "in_size zero row", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{0, 0};
    REQUIRE( coord.in_size(size) );
}

TEST_CASE( "in_size zero col", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{0, 0};
    REQUIRE( coord.in_size(size) );
}

TEST_CASE( "in_size row greater size row", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{4, 0};
    REQUIRE_FALSE( coord.in_size(size) );
}

TEST_CASE( "in_size col greater size col", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{0, 6};
    REQUIRE_FALSE( coord.in_size(size) );
}

TEST_CASE( "in_size row equal size row", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{3, 0};
    REQUIRE_FALSE( coord.in_size(size) );
}

TEST_CASE( "in_size col equal size col", "[in_size]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{0, 5};
    REQUIRE_FALSE( coord.in_size(size) );
}

TEST_CASE( "on_side in size", "[on_side]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{1, 3};
    REQUIRE_FALSE( coord.on_side(size) );
}

TEST_CASE( "on_side out size", "[on_side]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{-1, 3};
    REQUIRE_FALSE( coord.on_side(size) );
}

TEST_CASE( "on_side on left side", "[on_side]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{1, 0};
    REQUIRE( coord.on_side(size) );
}

TEST_CASE( "on_side on right side", "[on_side]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{1, 4};
    REQUIRE( coord.on_side(size) );
}

TEST_CASE( "on_side on top side", "[on_side]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{0, 4};
    REQUIRE( coord.on_side(size) );
}

TEST_CASE( "on_side on bottom side", "[on_side]" )
{
	OnlineGame::Coord size{3, 5};
	OnlineGame::Coord coord{2, 3};
    REQUIRE( coord.on_side(size) );
}
