#pragma once

#ifndef MATRIX4_HPP_
#define MATRIX4_HPP_

#include <vector>

class Matrix4
{
public:
	Matrix4();
	~Matrix4();
	std::vector <std::vector <float> > Get();
	std::vector <std::vector <float> > GetTransposed();
	Matrix4 operator+ (Matrix4& rhs);
	Matrix4 operator- (Matrix4& rhs);
	Matrix4 operator* (Matrix4& rhs);
	Matrix4 operator/ (Matrix4& rhs);
	float CalculateDeterminant();
	Matrix4 GetInverse();
	float GetAngle();

	void SetIdentity();

private:
	std::vector <std::vector <float> > MATRIX;
	
};

#endif /* MATRIX4_HPP_ */
