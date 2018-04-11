#include "velocity.hpp"

#include "../math/Vector2.hpp"

velocity::velocity() : component("velocity")
{
}

velocity::velocity(Engine::Math::Vector2 pVelocity) : component("velocity")
{
	mVelocity = pVelocity;
}

Engine::Math::Vector2 velocity::get_velocity() {
	return mVelocity;
}

void velocity::reverse_x_direction()
{
	mVelocity.x *= -1;
}

void velocity::reverse_y_direction()
{
	mVelocity.y *= -1;
}

void velocity::sum_velocity(Engine::Math::Vector2 pVelocity)
{
	mVelocity += pVelocity;
}



velocity::~velocity()
{
}
