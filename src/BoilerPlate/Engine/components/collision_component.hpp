#pragma once

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "../core/Component.hpp"
#include "../components/model_matrix.hpp"
#include "../math/math_utilities.hpp"
#include "../math/Vector2.hpp"
#include "../math/Vector3.hpp"
#include"../math/matrix_4.hpp"

class collision_component : Engine::core::component
{
public:
	collision_component();

	int check_collision(model_matrix, model_matrix);

	Engine::Math::Vector2 vector_from_center(model_matrix, model_matrix);

	~collision_component();
};

#endif // !VERTEX_OBJECT_HPP_

