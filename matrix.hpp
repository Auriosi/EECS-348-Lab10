#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>

class Matrix {
    public:
    Matrix(const int& size);
    Matrix(const Matrix* other);
    ~Matrix();
    int getSize() const;
    int getValue(const int& row, const int& col) const;
    bool setValue(const int& row = 0, const int& col = 0, const int& value = 100);
    int* getData() const;
    std::string format() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    int sumDiagonals(bool secondary = false) const;
    Matrix swapRows(const int& row1 = 0, const int& row2 = 1) const;
    Matrix swapColumns(const int& col1 = 0, const int& col2 = 1) const;

    private:
    int size;
    int max_digits;
    int* data;
};