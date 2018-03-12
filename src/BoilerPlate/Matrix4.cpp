#include "Matrix4.hpp"
#include <iostream>
#define MATRIX_SIZE 4

Matrix4::Matrix4()
{
	SetIdentity();
}

Matrix4::~Matrix4()
{

}

void Matrix4::SetIdentity()
{
	//RESET VALUES (0)
	MATRIX = std::vector<float>(16, 0.0f);
	//SET ONES ON MAIN DIAGONAL
	for (int i = 0; i < MATRIX_SIZE; i++)
		MATRIX[i * 4 + i] = 1.0f;
}

std::vector <float> Matrix4::Get() {
	return MATRIX;
}

std::vector <float> Matrix4::GetTransposed() {
	std::vector <float> transposedElements;
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			transposedElements[i * 4 + j] = MATRIX[j * 4 + i];
		}
	}
	return transposedElements;
}

Matrix4 Matrix4::operator+(Matrix4& rhs) {
	for (int i = 0; i < MATRIX_SIZE*MATRIX_SIZE; i++) MATRIX[i] += rhs.MATRIX[i];
	return *this;
}
Matrix4 Matrix4::operator-(Matrix4& rhs) {
	for (int i = 0; i < MATRIX_SIZE*MATRIX_SIZE; i++) MATRIX[i] -= rhs.MATRIX[i];
	return *this;
}
Matrix4 Matrix4::operator*(Matrix4& rhs) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; i < MATRIX_SIZE; i++) {
			for (int k = 0; k < MATRIX_SIZE; k++) {
				MATRIX[i][k] *= rhs.Get()[k][j];
			}
		}
	}
	return *this;
}
Matrix4 Matrix4::operator/(Matrix4& rhs) {
	*this = *this * rhs.GetInverse();
	return *this;
}
Matrix4 Matrix4::operator=(std::vector<float> elements)
{
	MATRIX = elements;
}

float Matrix4::CalculateDeterminant() {
	float determinant;
	int i;
	for (i = 0; i < MATRIX_SIZE; i++)
		determinant = determinant + (MATRIX[0][i] * (MATRIX[1][(i + 1) % 3] * MATRIX[2][(i + 2) % 3] - MATRIX[1][(i + 2) % 3] * MATRIX[2][(i + 1) % 3]));
	return determinant;
}
Matrix4 Matrix4::GetInverse() {
	Matrix4 inverse;
	int i, j;
	for (i = 0; i < MATRIX_SIZE; i++) {
		for (j = 0; j < 3; j++)
			inverse.Get()[i][j] = ((MATRIX[(j + 1) % 3][(i + 1) % 3] * MATRIX[(j + 2) % 3][(i + 2) % 3]) - (MATRIX[(j + 1) % 3][(i + 2) % 3] * MATRIX[(j + 2) % 3][(i + 1) % 3])) / this->CalculateDeterminant();
	}
	return inverse;
}
float Matrix4::GetAngle() {
	float roll, yaw, pitch;
	float angle;
	if (MATRIX[0][0] == 1.0f)
	{
		roll = 0.0f;
		yaw = atan2f(MATRIX[0][2], MATRIX[2][3]);
		pitch = 0.0f;

	}
	else if (MATRIX[0] == -1.0f)
	{
		roll = 0.0f;
		yaw = atan2f(MATRIX[8], MATRIX[10]);
		pitch = 0.0f;

	}
	else
	{
		roll = atan2(-MATRIX[9], MATRIX[5]);
		yaw = atan2(-MATRIX[3], MATRIX[0]);
		pitch = asin(MATRIX[1]);

	}
}
float Matrix4::GetValue(int row, int column)
{
	return MATRIX[column * 4 + row];
}
void Matrix4::Rotate(float angle, Vector3) {
}
void Matrix4::Translate(Vector3 translationVector) {
	for (int i = 0; i < MATRIX_SIZE; i++) {

		MATRIX[i][0] * translationVector.x;

		MATRIX[i][1] * translationVector.y;

		MATRIX[i][2] * translationVector.z;

		MATRIX[i][3] * 1;

	}
}

Vector3 Matrix4::transform(Vector3 point)
{
	Matrix4 MPoint = Matrix4();
	MPoint.MATRIX[12] = point.x;
	MPoint.MATRIX[13] = point.y;
	MPoint.MATRIX[14] = point.z;
	return Vector3(MPoint.MATRIX[12], MPoint.MATRIX[13], MPoint.MATRIX[14]);
}


Vector4 Matrix4::transform(Vector4 point)
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
	for (int i = 0; i < MATRIX_SIZE; i++) {
		std::cout << matrix.MATRIX[i] << " " << matrix.MATRIX[i + 4] << " " << matrix.MATRIX[i + 8] << " " << matrix.MATRIX[i + 12] << '\n';
	}