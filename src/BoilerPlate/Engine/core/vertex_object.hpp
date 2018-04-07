#pragma once

#ifndef VERTEX_OBJECT_HPP_
#define VERTEX_OBJECT_HPP_

#include "../utilities/palette.hpp"
#include "../math/Vector2.hpp"
#include "../math/Vector3.hpp"

struct VertexObject
{
	Engine::Math::Vector3 coord;
	Color color;
	Engine::Math::Vector2 glCoord;

	VertexObject(Engine::Math::Vector3, Color, Engine::Math::Vector2);
	void copy_info(float *);
};

#endif // !VERTEX_OBJECT_HPP_