#ifndef ONLINEGAME_VIEW
#define ONLINEGAME_VIEW
namespace OnlineGame
{
	class View
	{
	public:
		void welcome();
		void show(int row, int col, int symbol);
		void refresh();
	};
}
#endif /* ONLINEGAME_VIEW */
