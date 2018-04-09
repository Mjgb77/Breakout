#pragma once

#ifndef MATRIX4_HPP_
#define MATRIX4_HPP_

#include <vector>
#include "Vector3.hpp"
#include"Vector4.hpp"


namespace Engine {
	namespace Math {

		struct matrix_4
		{
			std::vector <float> MATRIX;

			matrix_4();
			~matrix_4();
			std::vector <float> Get();
			float * get_pointer();
			matrix_4 get_transposed();

			matrix_4 operator+ (const matrix_4& rhs) const;
			matrix_4 operator- (const matrix_4& rhs) const;
			matrix_4 operator* (const matrix_4& rhs) const;
			matrix_4 operator/ (const matrix_4& rhs) const;

			matrix_4 GetInverse() const;
			Vector3 GetAngle();
			float get_value(int row, int column) const;
			void rotate(float pAngle, Vector3);
			void rotate_x(float pAngle);
			void rotate_y(float pAngle);
			void rotate_z(float pAngle);

			matrix_4 make_ortho(float pMaximumX, float pMinimumX, float pMaximumY, float pMinimumY, float pMaximumZ, float pMinimumZ);
			matrix_4 make_perspective(float pMaximumZ, float pMinimumZ, float pSizeOfView);
			matrix_4 make_look_at(Vector3 pCurrentLook, Vector3 pNewLook);

			void scale(Vector3 pScaleVector);
			void translate(Vector3 pTranslationVector);
			Vector3 transform(Vector3 pPoint);
			Vector4 transform(Vector4 pPoint);
			void set_identity();

			friend std::ostream& operator<< (std::ostream& stream, const matrix_4 & matrix);
		};
	}
}


#endif /* MATRIX4_HPP_ */