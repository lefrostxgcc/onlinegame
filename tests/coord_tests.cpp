#include <catch2/catch.hpp>
#include <coord.h>

TEST_CASE( "Coord constructor success", "[constructor]" )
{
	OnlineGame::Coord a{3, 5};
    REQUIRE( a.row == 3 );
    REQUIRE( a.col == 5 );
}
