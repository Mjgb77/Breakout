# pragma once
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "Engine/core/game_object.hpp"
#include "Engine/core/vertex_object.hpp"
#include "Engine/components/velocity.hpp"

#include "Engine/components/model_matrix.hpp"
#include <vector>

class Block: Engine::core::GameObject {
public:
	Block(Engine::Math::Vector2);

	model_matrix mModelMatrix;
	
	static int * get_indices();
	static float * get_vertices();

};

#endif // !BLOCK_H_INCLUDED

