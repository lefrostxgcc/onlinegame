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
		iterator begin();
		iterator end();
		Level() = default;
		explicit Level(const Coord &coord);
		void init();
		const Subject& operator[](const Coord &coord) const;
		Subject& operator[](const Coord &coord);
		Coord get_size() const noexcept;
	private:
		Matrix<Subject> map{};
		Coord size{};
	};
}
#endif /* ONLINEGAME_LEVEL_H */
