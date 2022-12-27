#include "PointMatrix.h"

PointMatrix::PointMatrix(Matrix* matr)
{
	ptr = matr;
}
PointMatrix::~PointMatrix()
{
	if (ptr == nullptr)
	{
		return;
	}
	delete ptr;
}

Matrix* PointMatrix::operator->()
{
	return ptr;
}
std::ostream& operator<<(std::ostream& out, const PointMatrix& matr)
{
	for (size_t i = 0; i < matr.ptr->getColumn(); ++i) {
		for (size_t j = 0; j < matr.ptr->getRow(); ++j) {
			out << matr.ptr->getElement(i, j) << " ";
		}
		out << "\n";
	}
	return out;
}
std::istream& operator>>(std::istream& in, PointMatrix& matr)
{
	std::cout << "Input matrix element " << std::endl;
	for (int i = 0; i < matr.ptr->getColumn(); i++)
	{
		for (int j = 0; j < matr.ptr->getRow(); j++)
		{
			std::cout << "Matrix[" << i << "][" << j << "] = ";
			in >> matr.ptr->getElement(i, j);
		}
	}
	return in;
}