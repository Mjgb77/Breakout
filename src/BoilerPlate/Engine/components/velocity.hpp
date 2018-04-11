#pragma once
#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

#include "../core/Component.hpp"
#include "../math/vector2.hpp"

class velocity : public Engine::core::component
{
public:
	velocity();
	velocity(Engine::Math::Vector2);

	Engine::Math::Vector2 get_velocity ();

	void reverse_x_direction();
	void reverse_y_direction();

	void sum_velocity(Engine::Math::Vector2);

	~velocity();

private:
	Engine::Math::Vector2 mVelocity;
};


#endif /* VELOCITY_HPP_ */
