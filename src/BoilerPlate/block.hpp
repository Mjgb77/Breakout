# pragma once
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "Engine/core/game_object.hpp"
#include "Engine/core/vertex_object.hpp"

#include <vector>

class Block: Engine::core::GameObject {
public:
	Block(Engine::Math::Vector2);
	int mIndices [6];
	float getVertices [4*9];
	std::vector <VertexObject> mVertices;
};

#endif // !BLOCK_H_INCLUDED

