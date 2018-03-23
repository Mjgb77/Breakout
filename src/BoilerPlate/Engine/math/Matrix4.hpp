#pragma once

#ifndef MATRIX4_HPP_
#define MATRIX4_HPP_

#include <vector>
#include "Vector3.hpp"
#include"Vector4.hpp"

struct Matrix4
{
	std::vector <float> MATRIX; 

	Matrix4();
	~Matrix4();
	std::vector <float> Get();
	Matrix4 GetTransposed();

	Matrix4 operator+ (const Matrix4& rhs) const;
	Matrix4 operator- (const Matrix4& rhs) const;
	Matrix4 operator* (const Matrix4& rhs) const;
	Matrix4 operator/ (const Matrix4& rhs) const;

	Matrix4 GetInverse() const;
	Vector3 GetAngle();
	float GetValue(int row, int column) const;
	void Rotate(float angle, Vector3);
	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);

	Matrix4 make_ortho(float pMaximumX, float pMinimumX, float pMaximumY, float pMinimumY, float pMaximumZ, float pMinimumZ);
	Matrix4 make_perspective(float pMaximumZ, float pMinimumZ, float pSizeOfView);
	Matrix4 make_look_at(Vector3 pCurrentLook, Vector3 pNewLook);


	void Translate(Vector3 translationVector);
	Vector3 Transform(Vector3 point);
	Vector4 Transform(Vector4 point);
	void SetIdentity();

	friend std::ostream& operator<< (std::ostream& stream, const Matrix4 & matrix);
};


#endif /* MATRIX4_HPP_ */