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
		void set_subject(const Coord &coord, Subject subject);
		Subject get_subject(const Coord &coord) const;
		Coord get_size() const noexcept;
	private:
		Matrix<Subject> map{};
		Coord size{};
	};
}
#endif /* ONLINEGAME_LEVEL_H */
