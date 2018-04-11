#include "matrix_4.hpp"
#include "math_utilities.hpp"
#include <iostream>
#define MATRIX_SIZE 4

namespace Engine {
	
	namespace Math {

		matrix_4::matrix_4()
		{
			set_identity();
		}

		matrix_4::~matrix_4() {
		}

		void matrix_4::set_identity()
		{
			//RESET VALUES (0)
			MATRIX = std::vector<float>(16, 0.0f);
			//SET ONES ON MAIN DIAGONAL
			for (int i = 0; i < MATRIX_SIZE; i++)
				MATRIX[i * 4 + i] = 1.0f;
		}


		std::vector <float> matrix_4::Get()
		{
			return MATRIX;
		}

		float * matrix_4::get_pointer()
		{
			return MATRIX.data();
		}

		matrix_4 matrix_4::GetInverse() const
		{
			float inv[16], det;

			inv[0] = MATRIX[5] * MATRIX[10] * MATRIX[15] -
				MATRIX[5] * MATRIX[11] * MATRIX[14] -
				MATRIX[9] * MATRIX[6] * MATRIX[15] +
				MATRIX[9] * MATRIX[7] * MATRIX[14] +
				MATRIX[13] * MATRIX[6] * MATRIX[11] -
				MATRIX[13] * MATRIX[7] * MATRIX[10];

			inv[4] = -MATRIX[4] * MATRIX[10] * MATRIX[15] +
				MATRIX[4] * MATRIX[11] * MATRIX[14] +
				MATRIX[8] * MATRIX[6] * MATRIX[15] -
				MATRIX[8] * MATRIX[7] * MATRIX[14] -
				MATRIX[12] * MATRIX[6] * MATRIX[11] +
				MATRIX[12] * MATRIX[7] * MATRIX[10];

			inv[8] = MATRIX[4] * MATRIX[9] * MATRIX[15] -
				MATRIX[4] * MATRIX[11] * MATRIX[13] -
				MATRIX[8] * MATRIX[5] * MATRIX[15] +
				MATRIX[8] * MATRIX[7] * MATRIX[13] +
				MATRIX[12] * MATRIX[5] * MATRIX[11] -
				MATRIX[12] * MATRIX[7] * MATRIX[9];

			inv[12] = -MATRIX[4] * MATRIX[9] * MATRIX[14] +
				MATRIX[4] * MATRIX[10] * MATRIX[13] +
				MATRIX[8] * MATRIX[5] * MATRIX[14] -
				MATRIX[8] * MATRIX[6] * MATRIX[13] -
				MATRIX[12] * MATRIX[5] * MATRIX[10] +
				MATRIX[12] * MATRIX[6] * MATRIX[9];

			inv[1] = -MATRIX[1] * MATRIX[10] * MATRIX[15] +
				MATRIX[1] * MATRIX[11] * MATRIX[14] +
				MATRIX[9] * MATRIX[2] * MATRIX[15] -
				MATRIX[9] * MATRIX[3] * MATRIX[14] -
				MATRIX[13] * MATRIX[2] * MATRIX[11] +
				MATRIX[13] * MATRIX[3] * MATRIX[10];

			inv[5] = MATRIX[0] * MATRIX[10] * MATRIX[15] -
				MATRIX[0] * MATRIX[11] * MATRIX[14] -
				MATRIX[8] * MATRIX[2] * MATRIX[15] +
				MATRIX[8] * MATRIX[3] * MATRIX[14] +
				MATRIX[12] * MATRIX[2] * MATRIX[11] -
				MATRIX[12] * MATRIX[3] * MATRIX[10];

			inv[9] = -MATRIX[0] * MATRIX[9] * MATRIX[15] +
				MATRIX[0] * MATRIX[11] * MATRIX[13] +
				MATRIX[8] * MATRIX[1] * MATRIX[15] -
				MATRIX[8] * MATRIX[3] * MATRIX[13] -
				MATRIX[12] * MATRIX[1] * MATRIX[11] +
				MATRIX[12] * MATRIX[3] * MATRIX[9];

			inv[13] = MATRIX[0] * MATRIX[9] * MATRIX[14] -
				MATRIX[0] * MATRIX[10] * MATRIX[13] -
				MATRIX[8] * MATRIX[1] * MATRIX[14] +
				MATRIX[8] * MATRIX[2] * MATRIX[13] +
				MATRIX[12] * MATRIX[1] * MATRIX[10] -
				MATRIX[12] * MATRIX[2] * MATRIX[9];

			inv[2] = MATRIX[1] * MATRIX[6] * MATRIX[15] -
				MATRIX[1] * MATRIX[7] * MATRIX[14] -
				MATRIX[5] * MATRIX[2] * MATRIX[15] +
				MATRIX[5] * MATRIX[3] * MATRIX[14] +
				MATRIX[13] * MATRIX[2] * MATRIX[7] -
				MATRIX[13] * MATRIX[3] * MATRIX[6];

			inv[6] = -MATRIX[0] * MATRIX[6] * MATRIX[15] +
				MATRIX[0] * MATRIX[7] * MATRIX[14] +
				MATRIX[4] * MATRIX[2] * MATRIX[15] -
				MATRIX[4] * MATRIX[3] * MATRIX[14] -
				MATRIX[12] * MATRIX[2] * MATRIX[7] +
				MATRIX[12] * MATRIX[3] * MATRIX[6];

			inv[10] = MATRIX[0] * MATRIX[5] * MATRIX[15] -
				MATRIX[0] * MATRIX[7] * MATRIX[13] -
				MATRIX[4] * MATRIX[1] * MATRIX[15] +
				MATRIX[4] * MATRIX[3] * MATRIX[13] +
				MATRIX[12] * MATRIX[1] * MATRIX[7] -
				MATRIX[12] * MATRIX[3] * MATRIX[5];

			inv[14] = -MATRIX[0] * MATRIX[5] * MATRIX[14] +
				MATRIX[0] * MATRIX[6] * MATRIX[13] +
				MATRIX[4] * MATRIX[1] * MATRIX[14] -
				MATRIX[4] * MATRIX[2] * MATRIX[13] -
				MATRIX[12] * MATRIX[1] * MATRIX[6] +
				MATRIX[12] * MATRIX[2] * MATRIX[5];

			inv[3] = -MATRIX[1] * MATRIX[6] * MATRIX[11] +
				MATRIX[1] * MATRIX[7] * MATRIX[10] +
				MATRIX[5] * MATRIX[2] * MATRIX[11] -
				MATRIX[5] * MATRIX[3] * MATRIX[10] -
				MATRIX[9] * MATRIX[2] * MATRIX[7] +
				MATRIX[9] * MATRIX[3] * MATRIX[6];

			inv[7] = MATRIX[0] * MATRIX[6] * MATRIX[11] -
				MATRIX[0] * MATRIX[7] * MATRIX[10] -
				MATRIX[4] * MATRIX[2] * MATRIX[11] +
				MATRIX[4] * MATRIX[3] * MATRIX[10] +
				MATRIX[8] * MATRIX[2] * MATRIX[7] -
				MATRIX[8] * MATRIX[3] * MATRIX[6];

			inv[11] = -MATRIX[0] * MATRIX[5] * MATRIX[11] +
				MATRIX[0] * MATRIX[7] * MATRIX[9] +
				MATRIX[4] * MATRIX[1] * MATRIX[11] -
				MATRIX[4] * MATRIX[3] * MATRIX[9] -
				MATRIX[8] * MATRIX[1] * MATRIX[7] +
				MATRIX[8] * MATRIX[3] * MATRIX[5];

			inv[15] = MATRIX[0] * MATRIX[5] * MATRIX[10] -
				MATRIX[0] * MATRIX[6] * MATRIX[9] -
				MATRIX[4] * MATRIX[1] * MATRIX[10] +
				MATRIX[4] * MATRIX[2] * MATRIX[9] +
				MATRIX[8] * MATRIX[1] * MATRIX[6] -
				MATRIX[8] * MATRIX[2] * MATRIX[5];

			det = MATRIX[0] * inv[0] + MATRIX[1] * inv[4] + MATRIX[2] * inv[8] + MATRIX[3] * inv[12];

			det = 1.0f / det;

			matrix_4 mat;
			for (int i = 0; i < 16; i++) mat.MATRIX[i] = inv[i] * det;
			return mat;
		}

		Vector3 matrix_4::GetAngle()
		{
			float roll, yaw, pitch;
			if (MATRIX[0] == 1.0f)
			{
				yaw = atan2f(MATRIX[8], MATRIX[10]);
				pitch = 0;
				roll = 0;
			}
			else if (MATRIX[0] == -1.0f)
			{
				yaw = atan2f(MATRIX[8], MATRIX[14]);
				pitch = 0;
				roll = 0;
			}
			else
			{
				yaw = atan2(-MATRIX[3], MATRIX[0]);
				pitch = asin(MATRIX[1]);
				roll = atan2(-MATRIX[9], MATRIX[5]);
			}

			return Vector3(pitch, yaw, roll);
		}

		float matrix_4::get_value (int row, int column) const
		{
			return MATRIX[column * 4 + row];
		}


		matrix_4 matrix_4::get_transposed()
		{
			matrix_4 transposed;
			for (int i = 0; i < MATRIX_SIZE; i++) {
				for (int j = 0; j < MATRIX_SIZE; j++) {
					transposed.MATRIX[i * 4 + j] = MATRIX[j * 4 + i];
				}
			}
			return transposed;
		}

		matrix_4 matrix_4::operator+(const matrix_4& rhs) const
		{
			matrix_4 mat = *this;
			for (int i = 0; i < MATRIX_SIZE*MATRIX_SIZE; i++) mat.MATRIX[i] += rhs.MATRIX[i];
			return mat;
		}

		matrix_4 matrix_4::operator-(const matrix_4& rhs) const
		{
			matrix_4 mat = *this;
			for (int i = 0; i < MATRIX_SIZE*MATRIX_SIZE; i++) mat.MATRIX[i] -= rhs.MATRIX[i];
			return mat;
		}

		matrix_4 matrix_4::operator*(const matrix_4& rhs) const
		{

			matrix_4 returnMatrix = *this;
			returnMatrix.MATRIX[0] = returnMatrix.MATRIX[0] * rhs.MATRIX[0] + returnMatrix.MATRIX[1] * rhs.MATRIX[4] + returnMatrix.MATRIX[2] * rhs.MATRIX[8] + returnMatrix.MATRIX[3] * rhs.MATRIX[12];
			returnMatrix.MATRIX[1] = returnMatrix.MATRIX[0] * rhs.MATRIX[1] + returnMatrix.MATRIX[1] * rhs.MATRIX[5] + returnMatrix.MATRIX[2] * rhs.MATRIX[9] + returnMatrix.MATRIX[3] * rhs.MATRIX[13];
			returnMatrix.MATRIX[2] = returnMatrix.MATRIX[0] * rhs.MATRIX[2] + returnMatrix.MATRIX[1] * rhs.MATRIX[6] + returnMatrix.MATRIX[2] * rhs.MATRIX[10] + returnMatrix.MATRIX[3] * rhs.MATRIX[14];
			returnMatrix.MATRIX[3] = returnMatrix.MATRIX[0] * rhs.MATRIX[3] + returnMatrix.MATRIX[1] * rhs.MATRIX[7] + returnMatrix.MATRIX[2] * rhs.MATRIX[11] + returnMatrix.MATRIX[3] * rhs.MATRIX[15];
			returnMatrix.MATRIX[4] = returnMatrix.MATRIX[4] * rhs.MATRIX[0] + returnMatrix.MATRIX[5] * rhs.MATRIX[4] + returnMatrix.MATRIX[6] * rhs.MATRIX[8] + returnMatrix.MATRIX[7] * rhs.MATRIX[12];
			returnMatrix.MATRIX[5] = returnMatrix.MATRIX[4] * rhs.MATRIX[1] + returnMatrix.MATRIX[5] * rhs.MATRIX[5] + returnMatrix.MATRIX[6] * rhs.MATRIX[9] + returnMatrix.MATRIX[7] * rhs.MATRIX[13];
			returnMatrix.MATRIX[6] = returnMatrix.MATRIX[4] * rhs.MATRIX[2] + returnMatrix.MATRIX[5] * rhs.MATRIX[6] + returnMatrix.MATRIX[6] * rhs.MATRIX[10] + returnMatrix.MATRIX[7] * rhs.MATRIX[14];
			returnMatrix.MATRIX[7] = returnMatrix.MATRIX[4] * rhs.MATRIX[3] + returnMatrix.MATRIX[5] * rhs.MATRIX[7] + returnMatrix.MATRIX[6] * rhs.MATRIX[11] + returnMatrix.MATRIX[7] * rhs.MATRIX[15];
			returnMatrix.MATRIX[8] = returnMatrix.MATRIX[8] * rhs.MATRIX[0] + returnMatrix.MATRIX[9] * rhs.MATRIX[4] + returnMatrix.MATRIX[10] * rhs.MATRIX[8] + returnMatrix.MATRIX[11] * rhs.MATRIX[12];
			returnMatrix.MATRIX[9] = returnMatrix.MATRIX[8] * rhs.MATRIX[1] + returnMatrix.MATRIX[9] * rhs.MATRIX[5] + returnMatrix.MATRIX[10] * rhs.MATRIX[9] + returnMatrix.MATRIX[11] * rhs.MATRIX[13];
			returnMatrix.MATRIX[10] = returnMatrix.MATRIX[8] * rhs.MATRIX[2] + returnMatrix.MATRIX[9] * rhs.MATRIX[6] + returnMatrix.MATRIX[10] * rhs.MATRIX[10] + returnMatrix.MATRIX[11] * rhs.MATRIX[14];
			returnMatrix.MATRIX[11] = returnMatrix.MATRIX[8] * rhs.MATRIX[3] + returnMatrix.MATRIX[9] * rhs.MATRIX[7] + returnMatrix.MATRIX[10] * rhs.MATRIX[11] + returnMatrix.MATRIX[11] * rhs.MATRIX[15];
			returnMatrix.MATRIX[12] = returnMatrix.MATRIX[12] * rhs.MATRIX[0] + returnMatrix.MATRIX[13] * rhs.MATRIX[4] + returnMatrix.MATRIX[14] * rhs.MATRIX[8] + returnMatrix.MATRIX[15] * rhs.MATRIX[12];
			returnMatrix.MATRIX[13] = returnMatrix.MATRIX[12] * rhs.MATRIX[1] + returnMatrix.MATRIX[13] * rhs.MATRIX[5] + returnMatrix.MATRIX[14] * rhs.MATRIX[9] + returnMatrix.MATRIX[15] * rhs.MATRIX[13];
			returnMatrix.MATRIX[14] = returnMatrix.MATRIX[12] * rhs.MATRIX[2] + returnMatrix.MATRIX[13] * rhs.MATRIX[6] + returnMatrix.MATRIX[14] * rhs.MATRIX[10] + returnMatrix.MATRIX[15] * rhs.MATRIX[14];
			returnMatrix.MATRIX[15] = returnMatrix.MATRIX[12] * rhs.MATRIX[3] + returnMatrix.MATRIX[13] * rhs.MATRIX[7] + returnMatrix.MATRIX[14] * rhs.MATRIX[11] + returnMatrix.MATRIX[15] * rhs.MATRIX[15];
			return returnMatrix;
		}

		matrix_4 matrix_4::operator/(const matrix_4& rhs) const
		{
			matrix_4 mat = *this;
			mat = mat * rhs.GetInverse();
			return mat;
		}


		void matrix_4::rotate(float angle, Vector3 axis)
		{
			axis.Normalize();
			float c = cos(angle);
			float s = sin(angle);
			float t = 1 - c;

			matrix_4 Rotation;
			Rotation.MATRIX[0] = t * axis.x * axis.x + c;
			Rotation.MATRIX[1] = t * axis.x * axis.y + axis.z * s;
			Rotation.MATRIX[2] = t * axis.x * axis.z - axis.y * s;

			Rotation.MATRIX[4] = t * axis.x * axis.y - axis.z * s;
			Rotation.MATRIX[5] = t * axis.y * axis.y + c;
			Rotation.MATRIX[6] = t * axis.y * axis.z + axis.x * s;

			Rotation.MATRIX[7] = t * axis.x * axis.z + axis.y * c;
			Rotation.MATRIX[8] = t * axis.y * axis.z - axis.x * s;
			Rotation.MATRIX[9] = t * axis.z * axis.z + c;

			*this = (*this)*Rotation;
		}

		void matrix_4::rotate_x(float angle)
		{
			matrix_4 MRotate;
			MRotate.MATRIX[5] = cos(-angle);
			MRotate.MATRIX[6] = sin(-angle);
			MRotate.MATRIX[9] = -sin(-angle);
			MRotate.MATRIX[10] = cos(-angle);
			*this = (*this)*MRotate;
		}

		void matrix_4::rotate_y(float angle)
		{
			matrix_4 MRotate;
			MRotate.MATRIX[0] = cos(-angle);
			MRotate.MATRIX[8] = sin(-angle);
			MRotate.MATRIX[2] = -sin(-angle);
			MRotate.MATRIX[10] = cos(-angle);
			*this = (*this)*MRotate;
		}

		void matrix_4::rotate_z(float angle)
		{
			matrix_4 MRotate;
			MRotate.MATRIX[0] = cos(-angle);
			MRotate.MATRIX[1] = -sin(-angle);
			MRotate.MATRIX[4] = sin(-angle);
			MRotate.MATRIX[5] = cos(-angle);
			*this = (*this)*MRotate;
		}

		void matrix_4::scale(Vector3 pScaleVector)
		{
			MATRIX[0] *= pScaleVector.x;
			MATRIX[5] *= pScaleVector.y;
			MATRIX[10] *= pScaleVector.z;
		}

		void matrix_4::translate(Vector3 translationVector)
		{
			matrix_4 MTranslation = matrix_4();
			MTranslation.MATRIX[12] = translationVector.x;
			MTranslation.MATRIX[13] = translationVector.y;
			MTranslation.MATRIX[14] = translationVector.z;
			(*this) = MTranslation * (*this);
		}

		Vector3 matrix_4::transform(Vector3 point)
		{
			matrix_4 MPoint = matrix_4();
			MPoint.MATRIX[12] = point.x;
			MPoint.MATRIX[13] = point.y;
			MPoint.MATRIX[14] = point.z;
			MPoint = MPoint * (*this);

			return Vector3(MPoint.MATRIX[12], MPoint.MATRIX[13], MPoint.MATRIX[14]);
		}


		Vector4 matrix_4::transform(Vector4 point)
		{
			matrix_4 MPoint = matrix_4();
			MPoint.MATRIX[12] = point.x;
			MPoint.MATRIX[13] = point.y;
			MPoint.MATRIX[14] = point.z;
			MPoint.MATRIX[15] = point.z;
			return Vector4(MPoint.MATRIX[12], MPoint.MATRIX[13], MPoint.MATRIX[14], MPoint.MATRIX[15]);
		}


		std::ostream & operator<<(std::ostream & stream, const matrix_4 & matrix)
		{
			for (int i = 0; i < MATRIX_SIZE; i++)
				stream << matrix.MATRIX[i] << " " << matrix.MATRIX[i + 4] << " " << matrix.MATRIX[i + 8] << " " << matrix.MATRIX[i + 12] << '\n';
			return stream;
		}

		matrix_4 matrix_4::make_ortho(float pMaximumX, float pMinimumX, float pMaximumY, float pMinimumY, float pMaximumZ, float pMinimumZ) {


			MATRIX[0] = 2.0f / (pMaximumX - pMinimumX);
			MATRIX[5] = 2.0f / (pMaximumY - pMinimumY);
			MATRIX[10] = -2.0f / (pMaximumZ - pMinimumZ);
			MATRIX[12] = -(pMaximumX + pMinimumX) / (pMaximumX - pMinimumX);
			MATRIX[13] = -(pMaximumY + pMinimumY) / (pMaximumY - pMinimumY);
			MATRIX[14] = -(pMaximumZ + pMinimumZ) / (pMaximumZ - pMinimumZ);

			return *this;

		}

		// pAspectRation = width / height
		matrix_4 matrix_4::make_perspective(float pMaximumZ, float pMinimumZ, float pSizeOfView, float pAspectRatio) {
			float  factor = 1 / (tan( MathUtilities::to_rad(pSizeOfView * 0.5f)));
			float zDiffFactor = 1 / (pMaximumZ - pMinimumZ);
			MATRIX[0] = factor * pAspectRatio;
			MATRIX[5] = factor;
			MATRIX[10] = -pMaximumZ * zDiffFactor;
			MATRIX[11] = -1;
			MATRIX[14] = -pMaximumZ * pMinimumZ * zDiffFactor;
			MATRIX[15] = 0;

			return *this;

		}

		matrix_4 matrix_4::make_look_at(Vector3 pCurrentLook, Vector3 pNewLook) {
			Vector3 forward(pCurrentLook - pNewLook);
			Vector3 right;
			Vector3 up;
			Vector3 factor(0.0f, 1.0f, 0.0f);
			forward.Normalize();
			factor.Normalize();
			right = (factor * forward);
			up = forward * right;
			MATRIX[0] = right.x;
			MATRIX[1] = up.x;
			MATRIX[2] = forward.x;
			MATRIX[3] = pCurrentLook.x;
			MATRIX[4] = right.y;
			MATRIX[5] = up.y;
			MATRIX[6] = forward.y;
			MATRIX[7] = pCurrentLook.y;
			MATRIX[8] = right.z;
			MATRIX[9] = up.z;
			MATRIX[10] = forward.z;
			MATRIX[11] = pCurrentLook.z;


			return *this;
		}

	}
}
