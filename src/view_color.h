#ifndef ONLINEGAME_VIEW_COLOR_H
#define ONLINEGAME_VIEW_COLOR_H
namespace OnlineGame
{
	class ViewColor
	{
	public:
		ViewColor();
		void welcome();
		void show(int row, int col, int symbol);
		void refresh();
	};
}
#endif /* ONLINEGAME_VIEW_COLOR_H */
