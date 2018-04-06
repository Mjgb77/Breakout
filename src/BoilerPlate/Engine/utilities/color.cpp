#include "color.hpp"
#include "../math/math_utilities.hpp"

Color::Color(float red, float green, float blue, float alpha) {
	this->red = Engine::Math::MathUtilities::Clamp(red, 0.0f, 1.0f);
	this->green = Engine::Math::MathUtilities::Clamp(green, 0.0f, 1.0f);
	this->blue = Engine::Math::MathUtilities::Clamp(blue, 0.0f, 1.0f);
	this->alpha = Engine::Math::MathUtilities::Clamp(alpha, 0.0f, 1.0f);
}
