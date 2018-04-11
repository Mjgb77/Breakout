#pragma once
#ifndef MODEL_MATRIX_HPP_
#define MODEL_MATRIX_HPP_

#include "../core/Component.hpp"
#include "../math/matrix_4.hpp"

class model_matrix : Engine::core::component
{
public:
	model_matrix();

	float * get_pointer_table();
	void scale(Engine::Math::Vector3);
	void translate(Engine::Math::Vector3);
	Engine::Math::Vector3 transformPoint(Engine::Math::Vector3);

	~model_matrix();
private:
	Engine::Math::matrix_4 mMatrix;
};

#endif /* MODEL_MATRIX_HPP_ */


