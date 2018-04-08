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
			matrix_4 GetTransposed();

			matrix_4 operator+ (const matrix_4& rhs) const;
			matrix_4 operator- (const matrix_4& rhs) const;
			matrix_4 operator* (const matrix_4& rhs) const;
			matrix_4 operator/ (const matrix_4& rhs) const;

			matrix_4 GetInverse() const;
			Vector3 GetAngle();
			float GetValue(int row, int column) const;
			void Rotate(float angle, Vector3);
			void RotateX(float angle);
			void RotateY(float angle);
			void RotateZ(float angle);

			matrix_4 make_ortho(float pMaximumX, float pMinimumX, float pMaximumY, float pMinimumY, float pMaximumZ, float pMinimumZ);
			matrix_4 make_perspective(float pMaximumZ, float pMinimumZ, float pSizeOfView);
			matrix_4 make_look_at(Vector3 pCurrentLook, Vector3 pNewLook);


			void Translate(Vector3 translationVector);
			Vector3 Transform(Vector3 point);
			Vector4 Transform(Vector4 point);
			void SetIdentity();

			friend std::ostream& operator<< (std::ostream& stream, const matrix_4 & matrix);
		};
	}
}


#endif /* MATRIX4_HPP_ */