#pragma once
#include <iostream>

class Matrix
{
	std::size_t column = 0;
	std::size_t row = 0;
	int** matrix = nullptr;

	void Clear();
	void inputMatrix(std::istream& in);
	void outputMatrix(std::ostream& out);
public:
	Matrix();
	Matrix(std::size_t r, std::size_t c);
	Matrix(const Matrix& m);
	~Matrix();

	int* operator[](const int c);
	Matrix& operator=(const Matrix& m);
	int& operator()(int i, int j);
	int& getElement(int i, int j);

	friend std::istream& operator>>(std::istream& in, Matrix& temp);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& temp);

	Matrix* multiplicationByConst(int number, Matrix& a);
	Matrix* multiplicationByMatrix(Matrix& a, Matrix& b);
	Matrix* matrixPower(int power, Matrix& a);
	Matrix* addMatrix(Matrix& b);

	int** getMatrix();
	int getColumn();
	int getRow();
};

