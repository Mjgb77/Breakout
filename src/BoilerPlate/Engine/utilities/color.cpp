#include "color.hpp"
#include "../math/math_utilities.hpp"

Color::Color(float red, float green, float blue, float alpha) {
	this->red = Engine::Math::MathUtilities::clamp(red, 0.0f, 1.0f);
	this->green = Engine::Math::MathUtilities::clamp(green, 0.0f, 1.0f);
	this->blue = Engine::Math::MathUtilities::clamp(blue, 0.0f, 1.0f);
	this->alpha = Engine::Math::MathUtilities::clamp(alpha, 0.0f, 1.0f);
}
