#include "Matrix4.hpp"
#include <iostream>
#define MATRIX_SIZE 4

Matrix4::Matrix4()
{
	SetIdentity();
}

Matrix4::~Matrix4() {
}

void Matrix4::SetIdentity()
{
	//RESET VALUES (0)
	MATRIX = std::vector<float>(16, 0.0f);
	//SET ONES ON MAIN DIAGONAL
	for (int i = 0; i < MATRIX_SIZE; i++)
		MATRIX[i * 4 + i] = 1.0f;
}


std::vector <float> Matrix4::Get()
{
	return MATRIX;
}

Matrix4 Matrix4::GetInverse() const
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

	Matrix4 mat;
	for (int i = 0; i < 16; i++) mat.MATRIX[i] = inv[i] * det;
	return mat;
}

Vector3 Matrix4::GetAngle()
{
	float roll, yaw, pitch;
	float angle;
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

float Matrix4::GetValue(int row, int column) const
{
	return MATRIX[column * 4 + row];
}


Matrix4 Matrix4::GetTransposed()
{
	Matrix4 transposed;
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			transposed.MATRIX[i * 4 + j] = MATRIX[j * 4 + i];
		}
	}
	return transposed;
}

Matrix4 Matrix4::operator+(const Matrix4& rhs) const
{
	Matrix4 mat = *this;
	for (int i = 0; i < MATRIX_SIZE*MATRIX_SIZE; i++) mat.MATRIX[i] += rhs.MATRIX[i];
	return mat;
}

Matrix4 Matrix4::operator-(const Matrix4& rhs) const
{
	Matrix4 mat = *this;
	for (int i = 0; i < MATRIX_SIZE*MATRIX_SIZE; i++) mat.MATRIX[i] -= rhs.MATRIX[i];
	return mat;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
	Matrix4 mat = *this;
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; i < MATRIX_SIZE; i++) {
			for (int k = 0; k < MATRIX_SIZE; k++) {
				mat.MATRIX[i + 4 * k] *= rhs.GetValue(k, j);
			}
		}
	}
	return *this;
}

Matrix4 Matrix4::operator/(const Matrix4& rhs) const
{
	Matrix4 mat = *this;
	mat = mat * rhs.GetInverse();
	return mat;
}


void Matrix4::Rotate(float angle, Vector3 axis)
{
	axis.Normalize();
	float c = cos(angle);
	float s = sin(angle);
	float t = 1 - c;

	Matrix4 Rotation;
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

void Matrix4::RotateX(float angle)
{
	Matrix4 MRotate;
	MRotate.MATRIX[5] = cos(-angle);
	MRotate.MATRIX[6] = sin(-angle);
	MRotate.MATRIX[9] = -sin(-angle);
	MRotate.MATRIX[10] = cos(-angle);
	*this = (*this)*MRotate;
}

void Matrix4::RotateY(float angle)
{
	Matrix4 MRotate;
	MRotate.MATRIX[0] = cos(-angle);
	MRotate.MATRIX[8] = sin(-angle);
	MRotate.MATRIX[2] = -sin(-angle);
	MRotate.MATRIX[10] = cos(-angle);
	*this = (*this)*MRotate;
}

void Matrix4::RotateZ(float angle)
{
	Matrix4 MRotate;
	MRotate.MATRIX[0] = cos(-angle);
	MRotate.MATRIX[1] = sin(-angle);
	MRotate.MATRIX[4] = -sin(-angle);
	MRotate.MATRIX[5] = cos(-angle);
	*this = (*this)*MRotate;
}

void Matrix4::Translate(Vector3 translationVector)
{
	Matrix4 MTranslation = Matrix4();
	MTranslation.MATRIX[12] = translationVector.x;
	MTranslation.MATRIX[13] = translationVector.y;
	MTranslation.MATRIX[14] = translationVector.z;
	(*this) = MTranslation * (*this);
}

Vector3 Matrix4::Transform(Vector3 point)
{
	Matrix4 MPoint = Matrix4();
	MPoint.MATRIX[12] = point.x;
	MPoint.MATRIX[13] = point.y;
	MPoint.MATRIX[14] = point.z;
	MPoint = MPoint * (*this);

	return Vector3(MPoint.MATRIX[12], MPoint.MATRIX[13], MPoint.MATRIX[14]);
}


Vector4 Matrix4::Transform(Vector4 point)
{
	Matrix4 MPoint = Matrix4();
	MPoint.MATRIX[12] = point.x;
	MPoint.MATRIX[13] = point.y;
	MPoint.MATRIX[14] = point.z;
	MPoint.MATRIX[15] = point.z;
	return Vector4(MPoint.MATRIX[12], MPoint.MATRIX[13], MPoint.MATRIX[14], MPoint.MATRIX[15]);
}


std::ostream & operator<<(std::ostream & stream, const Matrix4 & matrix)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
		stream << matrix.MATRIX[i] << " " << matrix.MATRIX[i + 4] << " " << matrix.MATRIX[i + 8] << " " << matrix.MATRIX[i + 12] << '\n';
	return stream;
}