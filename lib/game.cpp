#include "game.h"
OnlineGame::Game::Game(std::unique_ptr<IView> v)
 :	view{std::move(v)}
{
}

void OnlineGame::Game::start(const Level &l)
{
	level = l;
	view->clear();
	view->welcome();
	int row_count = level.get_size().row;
	int col_count = level.get_size().col;
	for (int row = 0; row < row_count; row++)
		for (int col = 0; col < col_count; col++)
			view->show(Coord{row, col}, level[Coord{row, col}]);
	move(0, 0);
}

void OnlineGame::Game::move(int srow, int scol)
{
	Coord move_coord{user1_coord.row + srow, user1_coord.col + scol};
	level[user1_coord] = Subject::space;
	level[move_coord] = Subject::user1;
	view->show(user1_coord, Subject::space);
	view->show(move_coord, Subject::user1);
	user1_coord = move_coord;
	view->refresh();
}
