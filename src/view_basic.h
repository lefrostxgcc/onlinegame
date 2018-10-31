#ifndef ONLINEGAME_VIEW_BASIC_H
#define ONLINEGAME_VIEW_BASIC_H
namespace OnlineGame
{
	class ViewBasic
	{
	public:
		void welcome();
		void show(int row, int col, int symbol);
		void refresh();
	};
}
#endif /* ONLINEGAME_VIEW_BASIC_H */
