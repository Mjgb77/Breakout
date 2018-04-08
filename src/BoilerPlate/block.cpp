#include "block.hpp"

#include "Engine/utilities/palette.hpp"
#include "Engine/math/Vector2.hpp"
#include "Engine/math/Vector3.hpp"

const float WIDTH = 0.5f;
const float HEIGHT = 0.3f;
#include <iostream>
using namespace std;

Block::Block(Engine::Math::Vector2 pPosition) :mIndices{ 0,1,3,1,2,3 }
{
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x+WIDTH, pPosition.y+HEIGHT), Palette::Cyan, Engine::Math::Vector2(1.0f, 1.0f))
	);
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x+WIDTH, pPosition.y-HEIGHT), Palette::Cyan, Engine::Math::Vector2(1.0f, 0.0f))
	);
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x-WIDTH, pPosition.y-HEIGHT), Palette::Cyan, Engine::Math::Vector2(0.0f, 0.0f))
	);
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x-WIDTH, pPosition.y+HEIGHT), Palette::Cyan, Engine::Math::Vector2(0.0f, 1.0f))
	);

	int id = 0;
	for (VertexObject &V : mVertices) {
		V.copy_info(getVertices + id);
		id += 9;
	}

	
}
