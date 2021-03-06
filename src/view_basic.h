#ifndef ONLINEGAME_VIEW_BASIC_H
#define ONLINEGAME_VIEW_BASIC_H
#include <iview.h>
namespace OnlineGame
{
	class ViewBasic : public IView {
	public:
		void welcome() override;
		void show(Coord coord, Subject s) override;
		void show_money_count(Coord coord, int money_count) override;
		void clear() override;
		void refresh() override;
	};
}
#endif /* ONLINEGAME_VIEW_BASIC_H */
