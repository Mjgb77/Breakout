#pragma once
#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

#include "../core/Component.hpp"
#include "../math/vector2.hpp"

class velocity : public Engine::core::component
{
public:
	velocity();

	Engine::Math::Vector2 get_velocity ();

	~velocity();

private:
	Engine::Math::Vector2 mVelocity;
};


#endif /* VELOCITY_HPP_ */
