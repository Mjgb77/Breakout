#pragma once
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include "game_object.hpp"
#include "vertex.hpp"

namespace Engine {
	namespace core {
		class Block: GameObject {
		public:
			Block();

			Vertex mVertexes[4] ={
				{0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f},   // top right
			{ 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f },  // bottom right
			{ -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f },  // bottom left
			{ -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f }   // top left 
			};
			int indexes[6] = { 0, 1, 2, 1, 3, 2 };

		};
	}
}

#endif // !BLOCK_H_INCLUDED

