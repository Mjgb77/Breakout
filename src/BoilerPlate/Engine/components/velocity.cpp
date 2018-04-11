#include "velocity.hpp"

#include "../math/Vector2.hpp"

velocity::velocity() : component("velocity")
{
	mVelocity = Engine::Math::Vector2(2.0f);
}

Engine::Math::Vector2 velocity::get_velocity() {
	return mVelocity;
}

velocity::~velocity()
{
}
