#include "collision_component.hpp"



collision_component::collision_component():component("collision")
{

}

#include <iostream>

using namespace std;


int collision_component::check_collision (model_matrix pCircleMatrix, model_matrix pAABBMatrix)
{
	Engine::Math::Vector3 tmp = pCircleMatrix.transformPoint(Engine::Math::Vector3());
	Engine::Math::Vector2 circleCenter(tmp.x, tmp.y);

	tmp = pAABBMatrix.transformPoint(Engine::Math::Vector3());
	Engine::Math::Vector2 AABBCenter(tmp.x, tmp.y);

	float x2 = pAABBMatrix.transformPoint(Engine::Math::Vector2(1.0f, 0.0f)).x;
	float x1 = pAABBMatrix.transformPoint(Engine::Math::Vector2(-1.0f, 0.0f)).x;

	float y2 = pAABBMatrix.transformPoint(Engine::Math::Vector2(0.0f, 1.0f)).y;
	float y1 = pAABBMatrix.transformPoint(Engine::Math::Vector2(0.0f, -1.0f)).y;
	
	
	Engine::Math::Vector2 toCircle;

	toCircle.x = Engine::Math::MathUtilities::clamp(circleCenter.x, x1, x2);
	toCircle.y = Engine::Math::MathUtilities::clamp(circleCenter.y, y1, y2);
	
	if ((toCircle - circleCenter).Length() > 0.02f) return 0;
	return toCircle.y == y1 || toCircle.y == y2 ? 2 : 1;
}

Engine::Math::Vector2 collision_component::vector_from_center(model_matrix pCircleMatrix, model_matrix pAABBMatrix)
{
	Engine::Math::Vector3 tmp = pCircleMatrix.transformPoint(Engine::Math::Vector3());
	Engine::Math::Vector2 circleCenter(tmp.x, tmp.y);

	tmp = pAABBMatrix.transformPoint(Engine::Math::Vector3());
	Engine::Math::Vector2 AABBCenter(tmp.x, tmp.y);

	float x2 = pAABBMatrix.transformPoint(Engine::Math::Vector2(1.0f, 0.0f)).x;
	float x1 = pAABBMatrix.transformPoint(Engine::Math::Vector2(-1.0f, 0.0f)).x;

	float y2 = pAABBMatrix.transformPoint(Engine::Math::Vector2(0.0f, 1.0f)).y;
	float y1 = pAABBMatrix.transformPoint(Engine::Math::Vector2(0.0f, -1.0f)).y;


	Engine::Math::Vector2 toCircle;

	toCircle.x = Engine::Math::MathUtilities::clamp(circleCenter.x, x1, x2);
	toCircle.y = Engine::Math::MathUtilities::clamp(circleCenter.y, y1, y2);

	return (toCircle - AABBCenter);
}



collision_component::~collision_component()
{
}
