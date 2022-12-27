#include <iostream>
#include "Matrix.h"

int& Matrix::operator()(int i, int j)
{
	if (i < 0 && i > row)
		return i;
	if (j < 0 && j > column)
		return i;
	return matrix[i][j];
}
void Matrix::Clear()
{
	for (std::size_t i = 0; i < column; ++i)
	{
		delete matrix[i];
	}
	delete[] matrix;
}
void Matrix::inputMatrix(std::istream& in)
{
	std::cout << "Input matrix element " << std::endl;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			std::cout << "Matrix[" << i << "][" << j << "] = ";
			in >> matrix[i][j];
		}
	}
}
void Matrix::outputMatrix(std::ostream& out)
{
	if (matrix == nullptr)
		return;
	for (size_t i = 0; i < column; ++i) {
		for (size_t j = 0; j < row; ++j) {
			out << matrix[i][j] << " ";
		}
		out << "\n";
	}
}

Matrix& Matrix::operator=(const Matrix& m)
{
	column = m.column;
	row = m.row;
	matrix = m.matrix;
	return *this;
}
int* Matrix::operator[](const int c)
{
	return matrix[c];
}

std::ostream& operator<<(std::ostream& out, const Matrix& temp)
{
	for (size_t i = 0; i < temp.column; ++i) {
		for (size_t j = 0; j < temp.row; ++j) {
			out << temp.matrix[i][j] << " ";
		}
		out << "\n";
	}
	return out;
}
std::istream& operator>>(std::istream& in, Matrix& temp)
{
	std::cout << "Input matrix element " << std::endl;
	for (int i = 0; i < temp.column; i++)
	{
		for (int j = 0; j < temp.row; j++)
		{
			std::cout << "Matrix[" << i << "][" << j << "] = ";
			in >> temp.matrix[i][j];
		}
	}
	return in;
}
int& Matrix::getElement(int i, int j)
{
	int x = 0;
	if (i < 0 && i > row)
		return i;
	if (j < 0 && j > column)
		return i;
	return matrix[i][j];
}

Matrix::Matrix() : column(3), row(3)
{
	matrix = new int* [3];
	for (std::size_t i = 0; i < 3; i++)
	{
		matrix[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix(std::size_t r, std::size_t c) : column(c), row(r), matrix(new int* [column])
{
	for (std::size_t i = 0; i < column; ++i)
	{
		matrix[i] = new int[row];
	}
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& m)
{
	column = m.column;
	row = m.row;

	matrix = new int* [column];

	for (std::size_t i = 0; i < column; ++i)
	{
		matrix[i] = new int[row];
	}

	for (std::size_t i = 0; i < column; ++i)
	{
		for (std::size_t j = 0; j < row; ++j)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}
Matrix::~Matrix()
{
	Clear();
}

int Matrix::getColumn()
{
	return column;
}
int Matrix::getRow()
{
	return row;
}
int** Matrix::getMatrix()
{
	return matrix;
}

Matrix* Matrix::multiplicationByConst(int number, Matrix& a)
{
	auto result = new Matrix(a);
	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++)
			result->matrix[i][j] *= number;
	return result;
}
Matrix* Matrix::multiplicationByMatrix(Matrix& a, Matrix& b)
{
	if (a.column != b.row)
		return nullptr;
	auto result = new Matrix();
	for (int i = 0; i < a.column; i++)
		for (int j = 0; j < a.column; j++)
			for (int inner = 0; inner < a.row; inner++)
			{
				result->matrix[i][j] += a.matrix[i][inner] * b.matrix[inner][j];
			}
	return result;
}
Matrix* Matrix::matrixPower(int power, Matrix& a)
{
	auto result = new Matrix();
	if (power <= 0 || power > 5)
		return &a;
	if (power == 1)
		return &a;
	if (power == 2)
	{
		result = multiplicationByMatrix(a, a);
		return result;
	}
	if (power >= 3)
	{
		result = multiplicationByMatrix(a, a);
		for (int k = 2; k < power; k++)
		{
			result = multiplicationByMatrix(*result, a);
		}
	}
	return result;
}
Matrix* Matrix::addMatrix(Matrix& b)
{
	auto result = new Matrix();
	if (row != b.row || column != b.column)
		return result;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			result->matrix[i][j] = matrix[i][j] + b.matrix[i][j];
		}
	}
	return result;
}