#include"block.hpp"

#include "Engine/utilities/palette.hpp"
#include "Engine/math/Vector2.hpp"
#include "Engine/math/Vector3.hpp"

const float WIDTH = 0.5f;
const float HEIGHT = 0.3f;

Block::Block(Engine::Math::Vector2 pPosition)
{
	puts("mmm");
	int * testing = new int[10];

	mIndices = new int[6] { 0,1,3,1,2,3 };

	printf("%d %d\n", sizeof(testing) / sizeof(int), sizeof(mIndices) / sizeof(int));
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x+HEIGHT, pPosition.y+WIDTH), Palette::Cyan, Engine::Math::Vector2(1.0f, 1.0f))
	);
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x + HEIGHT, pPosition.y-WIDTH), Palette::Cyan, Engine::Math::Vector2(1.0f, 0.0f))
	);
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x-WIDTH, pPosition.y-WIDTH), Palette::Cyan, Engine::Math::Vector2(0.0f, 0.0f))
	);
	mVertices.push_back(
		VertexObject(Engine::Math::Vector2(pPosition.x-WIDTH, pPosition.y+WIDTH), Palette::Cyan, Engine::Math::Vector2(0.0f, 1.0f))
	);

	size_t tSize = mVertices.size() * 9;
	getVertices = new float[tSize];
	int id = 0;
	for (VertexObject &V : mVertices) {
		V.copy_info(getVertices + id);
		id += 9;
	}
	
}
