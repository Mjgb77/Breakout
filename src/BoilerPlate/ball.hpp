# pragma once
#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "Engine/core/game_object.hpp"
#include "Engine/core/vertex_object.hpp"
#include "Engine/components/velocity.hpp"

#include "Engine/components/model_matrix.hpp"
#include <vector>

class ball : Engine::core::GameObject {
public:
	ball(Engine::Math::Vector2);

	model_matrix mModelMatrix;

	static int * get_indices();
	static float * get_vertices();

};

#endif // !BALL_H_INCLUDED

