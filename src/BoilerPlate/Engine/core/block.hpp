# pragma once
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include "game_object.hpp"
#include "vertex.hpp"

#include <vector>

namespace Engine {
	namespace core {
		class Block: GameObject {
		public:
			Block();

			std::vector <float> mVertexes;
			std::vector <int> indexes;
			//int indexes[6] = { 0, 1, 3, 1, 2, 3 };
		};
	}
}

#endif // !BLOCK_H_INCLUDED

