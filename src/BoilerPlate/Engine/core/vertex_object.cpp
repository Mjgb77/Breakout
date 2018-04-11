#include "vertex_object.hpp"

VertexObject::VertexObject(Engine::Math::Vector3 pCoord, Color pColor, Engine::Math::Vector2 pGlCoord) : coord(pCoord), color(pColor), glCoord(pGlCoord)
{
}

void VertexObject::copy_info(float * pArr)
{
	*pArr = coord.x;
	*(++pArr) = coord.y;
	*(++pArr) = coord.z;

	*(++pArr) = color.red;
	*(++pArr) = color.green;
	*(++pArr) = color.blue;
	*(++pArr) = color.alpha;

	*(++pArr) = glCoord.x;
	*(++pArr) = glCoord.y;
}
