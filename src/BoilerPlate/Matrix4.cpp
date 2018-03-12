#include "Matrix4.hpp"

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
	MATRIX = std::vector<std::vector <float> >(4, std::vector <float>(4, 0.0f));

	//SET ONES ON MAIN DIAGONAL
	for (int i = 0; i < MATRIX_SIZE; i++)
		MATRIX[i][i] = 1.0f;
}


std::vector <std::vector <float> > Matrix4::Get() {
	return MATRIX;
}

std::vector <std::vector <float> > Matrix4::GetTransposed() {
	std::vector <std::vector <float> > transposedElements; 
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			transposedElements[i][j] = MATRIX[j][i];



		}
	}

	return transposedElements;

}

Matrix4 Matrix4::operator+(Matrix4& rhs) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			MATRIX[i][j] += rhs.Get()[i][j];

		}
	}
	return *this;
}

Matrix4 Matrix4::operator-(Matrix4& rhs) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			MATRIX[i][j] -= rhs.Get()[i][j];

		}
	}
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
			inverse.Get()[i][j]=  ((MATRIX[(j + 1) % 3][(i + 1) % 3] * MATRIX[(j + 2) % 3][(i + 2) % 3]) - (MATRIX[(j + 1) % 3][(i + 2) % 3] * MATRIX[(j + 2) % 3][(i + 1) % 3])) / this->CalculateDeterminant();

	}

	return inverse;
}



float Matrix4::GetAngle() {
	float roll, yaw, pitch;
	float angle;
	if (MATRIX[0][0] == 1.0f)
	{
		yaw = atan2f(MATRIX[0][2], MATRIX[2][3]);
		pitch = 0;
		roll = 0;
	}
	else if (MATRIX[0][0] == -1.0f)
	{
		yaw = atan2f(MATRIX[0][2], MATRIX[2][3]);
		pitch = 0;
		roll = 0;
	}
	else
	{
		yaw = atan2(-MATRIX[3][0], MATRIX[0][0]);
		pitch = asin(MATRIX[1][0]);
		roll = atan2(-MATRIX[1][2], MATRIX[1][1]);
	}

}

