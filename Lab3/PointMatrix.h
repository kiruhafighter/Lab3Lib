#pragma once
#include "Matrix.h"
class PointMatrix
{
	Matrix* ptr;
public:
	PointMatrix(Matrix* matr);
	~PointMatrix();

	Matrix* operator->();
	friend std::ostream& operator<<(std::ostream& os, const PointMatrix& matr);
	friend std::istream& operator>>(std::istream& is, PointMatrix& matr);
};