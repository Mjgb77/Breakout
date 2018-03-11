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
	MAT = std::vector<std::vector <float> >(4, std::vector <float>(4, 0.0f));

	//SET ONES ON MAIN DIAGONAL
	for (int i = 0; i < MATRIX_SIZE; i++)
		MAT[i][i] = 1.0f;
}
