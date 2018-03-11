#pragma once

#ifndef MATRIX4_HPP_
#define MATRIX4_HPP_

#include <vector>

class Matrix4
{
public:
	Matrix4();
	~Matrix4();

	void SetIdentity();

private:
	std::vector <std::vector <float> > MAT;
};

#endif /* MATRIX4_HPP_ */
