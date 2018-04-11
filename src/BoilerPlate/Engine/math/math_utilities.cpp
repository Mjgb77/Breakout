#include "math_utilities.hpp"
#include <intrin.h>
#include <cmath>
#include <ctime>

namespace Engine {
	namespace Math {
		const float MathUtilities::PI = acosf(-1);


		void RandSeed() {
			static bool seeded = false;
			if (!seeded) {
				srand(static_cast<unsigned int>(time(NULL)));
				seeded = true;
			}
		}

		int MathUtilities::nearest_int(float x) {
			return static_cast<int>(round(x));
		}

		int MathUtilities::nearest_even(float x) {
			int xLow = static_cast<int>(floor(x)), xUp = static_cast<int>(ceil(x));
			if (xLow == xUp) return xUp + 1;
			return xLow & 1 ? xUp : xLow;
		}

		int MathUtilities::rand_int(int max) {
			RandSeed();
			return rand() % max;
		}

		float MathUtilities::rand_float() {
			RandSeed();
			return float(rand()) / RAND_MAX;
		}

		float MathUtilities::to_deg(float rad) {
			return rad * 180 / PI;
		}

		float MathUtilities::to_rad(float deg) {
			return deg * PI / 180;
		}

		float MathUtilities::calculate_angular_distance_in_deg(float startAngle, float endAngle) {
			float dis = endAngle - startAngle;
			return dis < 0 ? dis + 360 : dis;
		}

		float MathUtilities::calculate_angular_distance_in_rad(float startAngle, float endAngle) {
			float dis = endAngle - startAngle;
			return dis < 0 ? dis + 2 * PI : dis;
		}

		bool MathUtilities::is_power_of_two(int x) {
			int bitCount = __popcnt(x);
			return bitCount == 1;
		}

	}
}