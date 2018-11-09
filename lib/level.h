#ifndef ONLINEGAME_LEVEL_H
#define ONLINEGAME_LEVEL_H
#include "coord.h"
#include "subject.h"
#include "matrix.hpp"
namespace OnlineGame
{
	class Level {
	public:
		using iterator = typename Matrix<Subject>::iterator;
		Level() = default;
		explicit Level(const Coord &coord);
		void init();
		iterator begin();
		iterator end();
		iterator find_first(Subject s);
		iterator find_random(Subject s);
		void set_subject(const Coord &coord, Subject subject);
		Subject get_subject(const Coord &coord) const;
		Coord get_size() const noexcept;
		void eat_money(Coord money_coord);
		int get_money_count() const noexcept;
	private:
		Matrix<Subject> map{};
		Coord size{};
		int money_count{};
	};
}
#endif /* ONLINEGAME_LEVEL_H */
