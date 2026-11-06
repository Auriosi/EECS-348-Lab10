#include "matrix.hpp"

Matrix::Matrix(const int& size) {
    this->size = size;
    this->data = new int[this->size*this->size]{};
}

Matrix::Matrix(const Matrix* other) {
    this->size = other->getSize();
    this->data = new int[this->size*this->size]{};
    for (int i = 0; i < this->getSize(); i++) {
        for (int n = 0; n < this->getSize(); n++) {
            this->setValue(i, n, other->getValue(i, n));
        }
    }
}

Matrix::~Matrix() {
    delete[] this->data;
}

int Matrix::getSize() const {
    return this->size;
}

int Matrix::getValue(const int& row, const int& col) const {
    return this->data[row * this->size + col];
}

bool Matrix::setValue(const int& row, const int& col, const int& value) {
    if (row >= 0 && row < this->size) {
        if (col >= 0 && col < this->size) {
            this->data[row * this->size + col] = value;
        } else {
            std::cout << "Invalid column index!\n";
            return false;
        }
    } else {
        std::cout << "Invalid row index!\n";
        return false;
    }
    int digits = 1;
    if (value != 0) {
        digits = std::floor(std::log10(std::abs(value))) + 1;
    }
    if (digits > this->max_digits) {
        this->max_digits = digits;
    }
    return true;
}

std::string Matrix::format() const {
    std::ostringstream output;
    for (int row = 0; row < this->size; row++) {
        for (int col = 0; col < this->size; col++) {
            output << std::setfill('0') << std::setw(3) << this->getValue(row, col) << " ";
        }
        output << "\n";
    }
    return output.str();
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix output = Matrix(this->size);
    for (int i = 0; i < this->size * this->size; i++) {
        int col = i % this->size;
        int row = (i - col) / this->size;
        output.setValue(row, col, this->data[i] + other.getValue(row, col));
    }
    return output;
}
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix output = Matrix(this->size);
    for (int i = 0; i < this->size * this->size; i++) {
        int col = i % this->size;
        int row = (i - col) / this->size;
        int sum = 0;
        for (int n = 0; n < this->size; n++) {
            sum += this->getValue(row, n) * other.getValue(n, col);
        }
        output.setValue(row, col, sum);
    }
    return output;
}
int Matrix::sumDiagonals(bool secondary) const {
    int sum = 0;
    for (int i = 0; i < this->size; i++) {
        if (!secondary) {
            sum += this->getValue(i, i);
        } else {
            sum += this->getValue(i, this->size - i - 1);
        }
    }
    return sum;
}
Matrix Matrix::swapRows(const int& row1, const int& row2) const {
    Matrix output = Matrix(this);
    for (int i = 0; i < this->size; i++) {
        output.setValue(row1, i, this->getValue(row2, i));
        output.setValue(row2, i, this->getValue(row1, i));
    }
    return output;
}
Matrix Matrix::swapColumns(const int& col1, const int& col2) const {
    Matrix output = Matrix(this);
    for (int i = 0; i < this->size; i++) {
        output.setValue(i, col1, this->getValue(i, col2));
        output.setValue(i, col2, this->getValue(i, col1));
    }
    return output;
}