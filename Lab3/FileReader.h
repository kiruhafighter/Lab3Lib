#pragma once
#include <iostream>
#include "Matrix.h"

void saveMatrixAsFile(Matrix& temp, std::string filename);
void loadMatrixFromFile(Matrix& temp, std::string filename);