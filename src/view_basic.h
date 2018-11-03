#ifndef ONLINEGAME_VIEW_BASIC_H
#define ONLINEGAME_VIEW_BASIC_H
#include <iview.h>
namespace OnlineGame
{
	class ViewBasic : public IView {
	public:
		void welcome() override;
		void show(int row, int col, Subject s) override;
		void clear() override;
		void refresh() override;
	};
}
#endif /* ONLINEGAME_VIEW_BASIC_H */
