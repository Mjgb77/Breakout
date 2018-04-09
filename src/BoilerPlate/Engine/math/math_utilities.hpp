#pragma once
#ifndef MATHUTILITIES_HPP_
#define MATHUTILITIES_HPP_

#include <algorithm>


namespace Engine {
	namespace Math {

		class MathUtilities {

		public:
			static const float PI;

			static int nearest_int(float x);
			static int nearest_even(float x); //Return the nearest even integer, if there is a tie return the greatest

			static int rand_int(int);
			static float rand_float(); //Return a random float from 0.0 to 1.0

			static float to_deg(float rad);
			static float to_rad(float deg);

			static float calculate_angular_distance_in_deg(float startAngle, float endAngle);
			static float calculate_angular_distance_in_rad(float startAngle, float endAngle);

			static bool is_power_of_two(int x);

			template <typename T>
			static T get_max(T x) { return x; }

			template<typename T, typename... Args>
			static T get_max(T x, Args... args) {
				return std::max(x, getMax(args...));
			}

			template <typename T>
			static T get_min(T x) { return x; }

			template<typename T, typename... Args>
			static T get_min(T x, Args ... args) {
				return std::min(x, getMin(args...));
			}

			template <typename T>
			static T clamp(T x, T startValue, T endValue) {
				return std::min(std::max(startValue, x), endValue);
			}

			template <typename T>
			static T interpolate(T startValue, T endValue, float fraction) {
				return startValue + static_cast<T>((endValue - startValue)*fraction);
			}
		};
	}
}

#endif /* MATHUTILITIES_HPP_ */
