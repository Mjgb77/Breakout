# pragma once
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "Engine/core/game_object.hpp"
#include "Engine/core/vertex_object.hpp"

#include <vector>

class Block: Engine::core::GameObject {
public:
	Block();

	std::vector <float> mVertexes;
	std::vector <int> indexes;
	//int indexes[6] = { 0, 1, 3, 1, 2, 3 };
};

#endif // !BLOCK_H_INCLUDED

