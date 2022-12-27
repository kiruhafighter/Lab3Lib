#include <iostream>
#include "Matrix.h"
#include "FileReader.h"
#include "PointMatrix.h"
using namespace std;

int menu()
{
    cout << "1 - matrix power" << endl;
    cout << "2 - multiplication by matrix" << endl;
    cout << "3 - multiplication by const" << endl;
    cout << "4 - add matrix" << endl;
    cout << "5 - load matrix from file" << endl;
    cout << "6 - save matrix as a file" << endl;
    cout << "7 - lab3 pseudo-variable" << endl;
    cout << "0 - exit\n" << endl;
    int choise;
    cin >> choise;
    return choise;
}

int main()
{
    Matrix* osn = new Matrix();
    Matrix* a = new Matrix(2, 3);
    Matrix* b = new Matrix(3, 2);
    Matrix* a1 = new Matrix();
    Matrix* b1 = new Matrix();
    Matrix* result = new Matrix();
    Matrix* result1 = new Matrix();
    PointMatrix* lab3 = new PointMatrix(osn);
    Matrix matr(3, 3);

    int i, j;
    int power = 0;
    int number = 0;

    while (true)
    {
        switch (menu())
        {
        case 0:
            delete lab3;
            delete a;
            delete b;
            delete a1;
            delete b1;
            delete result;
            delete result1;
            exit(1);
        case 1:
            system("cls");
            cout << endl;
            cout << "Enter the power >0 && <5:" << endl;
            cin >> power;
            cout << "Enter the matrix:" << endl;
            cin >> *osn;
            result = osn->matrixPower(power, *osn);
            cout << "\nResult:" << endl;
            cout << *result;
            break;
        case 2:
            system("cls");
            cout << endl;
            cout << "Enter the matrix A:" << endl;
            cin >> *a;
            cout << "Enter the matrix B:" << endl;
            cin >> *b;
            result = a->multiplicationByMatrix(*a, *b);
            cout << "\nResult:" << endl;
            cout << *result;
            break;
        case 3:
            system("cls");
            cout << endl;
            cout << "Enter the const number:" << endl;
            cin >> number;
            cout << "Enter the matrix:" << endl;
            cin >> *osn;
            result = osn->multiplicationByConst(number, *osn);
            cout << "\nResult:" << endl;
            cout << *result;
            break;
        case 4:
            system("cls");
            cout << endl;
            cout << "Enter the matrix A:" << endl;
            cin >> *a1;
            cout << "Enter the matrix B:" << endl;
            cin >> *b1;
            result = a1->addMatrix(*b1);
            cout << "\nResult:" << endl;
            cout << *result;
            break;
        case 5:
            system("cls");
            cout << endl;
            loadMatrixFromFile(*result1, "matrix.txt");
            cout << *result1;
            break;
        case 6:
            system("cls");
            cout << endl;
            saveMatrixAsFile(*result, "matrix.txt");
            cout << *result;
            break;
        case 7:
            system("cls");
            cout << endl;
            cout << matr;
            cout << endl;
            cout << "Enter i:" << endl;
            cin >> i;
            cout << "Enter j:" << endl;
            cin >> j;
            cout << "Enter number:" << endl;
            cin >> number;
            cout << "\nElement before:" << matr.getElement(i, j) << endl;
            matr(i, j) = number;
            cout << "Element after:" << matr.getElement(i, j) << endl;
            cout << endl;
            cout << matr;
        default:
            break;
        }
    }
}