#ifndef ONLINEGAME_VIEW_COLOR_H
#define ONLINEGAME_VIEW_COLOR_H
#include <iview.h>
namespace OnlineGame
{
	class ViewColor : public IView {
	public:
		explicit ViewColor();
		void welcome() override;
		void show(Coord coord, Subject s) override;
		void clear() override;
		void refresh() override;
	};
}
#endif /* ONLINEGAME_VIEW_COLOR_H */
