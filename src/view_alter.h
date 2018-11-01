#ifndef ONLINEGAME_VIEW_ALTER_H
#define ONLINEGAME_VIEW_ALTER_H
#include "iview.h"
namespace OnlineGame
{
	class ViewAlter : public IView {
	public:
		explicit ViewAlter();
		void welcome() override;
		void show(int row, int col, int symbol) override;
		void clear() override;
		void refresh() override;
	};
}
#endif /* ONLINEGAME_VIEW_ALTER_H */
