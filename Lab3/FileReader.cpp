#include <iostream>
#include "FileReader.h"
#include "Matrix.h"
#include <fstream>
#include <string>
#include <stdlib.h>

void saveMatrixAsFile(Matrix& temp, std::string filename)
{
	std::ofstream in(filename);

	if (!in.is_open())
	{
		std::cout << "Can't open the file...";
		return;
	}
	int col = temp.getColumn(), row = temp.getRow();
	auto x = temp.getMatrix();

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			in << x[i][j] << "\t";
		}
		in << std::endl;
	}
	in.close();
}

void loadMatrixFromFile(Matrix& temp, std::string filename)
{
	std::ifstream out(filename);
	if (!out.is_open())
	{
		std::cout << "Can't open the file...";
		return;
	}

	int col = temp.getColumn(), row = temp.getRow();
	auto x = temp.getMatrix();

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			out >> x[i][j];
		}
	}
	out.close();
}