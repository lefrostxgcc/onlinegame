#ifndef ONLINEGAME_LEVEL_H
#define ONLINEGAME_LEVEL_H
#include "coord.h"
#include "subject.h"
#include "matrix.hpp"
namespace OnlineGame
{
	class Level {
	public:
		explicit Level(const Coord &coord);
		const Subject& operator[](const Coord &coord) const;
		Subject& operator[](const Coord &coord);
	private:
		Matrix<Subject> map;
		Coord size;
	};
}
#endif /* ONLINEGAME_LEVEL_H */
