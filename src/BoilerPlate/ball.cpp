#include "ball.hpp"

#include "Engine/utilities/palette.hpp"
#include "Engine/math/Vector2.hpp"
#include "Engine/math/Vector3.hpp"

const float RADIUS = 0.03f;
#include <iostream>
using namespace std;

ball::ball(Engine::Math::Vector2 pPosition)
{

}

int * ball::get_indices()
{
	static int indices[6];
	static bool loaded = false;
	if (!loaded) {
		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 3;
		indices[3] = 1;
		indices[4] = 2;
		indices[5] = 3;

		loaded = true;
	}

	return indices;
}

float * ball::get_vertices()
{
	static bool loaded = false;
	static float mVertices[36];
	if (!loaded) {
		std::vector <VertexObject> vertices;

		vertices.push_back(
			VertexObject(Engine::Math::Vector2(RADIUS, RADIUS), Palette::Flame, Engine::Math::Vector2(1.0f, 1.0f))
		);
		vertices.push_back(
			VertexObject(Engine::Math::Vector2(RADIUS, -RADIUS), Palette::Flame, Engine::Math::Vector2(1.0f, 0.0f))
		);
		vertices.push_back(
			VertexObject(Engine::Math::Vector2(-RADIUS, -RADIUS), Palette::Flame, Engine::Math::Vector2(0.0f, 0.0f))
		);
		vertices.push_back(
			VertexObject(Engine::Math::Vector2(-RADIUS, RADIUS), Palette::Flame, Engine::Math::Vector2(0.0f, 1.0f))
		);

		int id = 0;
		for (VertexObject &V : vertices) {
			V.copy_info(mVertices + id);
			id += 9;
		}

		loaded = true;
	}
	return mVertices;
}
