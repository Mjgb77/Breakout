#include "collision_component.hpp"



collision_component::collision_component():component("collision")
{

}

bool collision_component::check_collision (model_matrix pCircleMatrix, model_matrix pAABBMatrix)
{
	Engine::Math::Vector3 tmp = pCircleMatrix.transformPoint(Engine::Math::Vector3());
	Engine::Math::Vector2 circleCenter(tmp.x, tmp.y);
	tmp = pCircleMatrix.transformPoint(Engine::Math::Vector3());
	Engine::Math::Vector2 AABBCenter(tmp.x, tmp.y);

	float x2 = pCircleMatrix.transformPoint(Engine::Math::Vector2(1.0f, 0.0f)).x;
	float x1 = -x2;

	float y2 = pCircleMatrix.transformPoint(Engine::Math::Vector2(0.0f, 1.0f)).y;
	float y1 = -y2;

	Engine::Math::Vector2 toCircle = circleCenter - AABBCenter;

	toCircle.x = Engine::Math::MathUtilities::clamp(x1, x2, toCircle.x);
	toCircle.y = Engine::Math::MathUtilities::clamp(y1, y2, toCircle.y);

	toCircle += AABBCenter;

	return (AABBCenter + toCircle - circleCenter).length < pCircleMatrix.transformPoint(Engine::Math::Vector3()).x;
}



collision_component::~collision_component()
{
}
