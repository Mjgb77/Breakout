#pragma once
#ifndef MATRIX4_HPP_
#define MATRIX4_HPP_
#include <vector>
#include "Vector3.hpp"
#include"Vector4.hpp"
class Matrix4
{
public:
	Matrix4();
	~Matrix4();
	std::vector <std::vector <float> > * Get();
	std::vector <std::vector <float> > GetTransposed();
	Matrix4 operator+ (Matrix4& rhs);
	Matrix4 operator- (Matrix4& rhs);
	Matrix4 operator* (Matrix4& rhs);
	Matrix4 operator/ (Matrix4& rhs);
	Matrix4 operator=(std::vector <float> elements);
	float CalculateDeterminant();
	Matrix4 GetInverse();
	Vector3 GetAngle();
	void Rotate(float angle, Vector3);
	void Translate(Vector3 translationVector);
	Vector3 transform(Vector3 point);
	Vector4 transform(Vector4 point);
	void SetIdentity();
private:
	std::vector <float> MATRIX;
};
#endif /* MATRIX4_HPP_ */