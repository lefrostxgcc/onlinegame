#ifndef ONLINEGAME_IVIEW_H
#define ONLINEGAME_IVIEW_H
#include "subject.h"
namespace OnlineGame
{
	class IView {
	public:
		virtual ~IView(){}
		virtual void welcome() = 0;
		virtual void show(int row, int col, Subject s) = 0;
		virtual void clear() = 0;
		virtual void refresh() = 0;
	};
}
#endif /* ONLINEGAME_IVIEW_H */
