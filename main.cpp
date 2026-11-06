#include "matrix.hpp"

int main() {
    std::cout << "Enter input filename: ";
    std::string filename = "";
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file.good()) {
        std::cout << "Failed to open file " << filename << std::endl;
        return 1;
    }
    int size = 0;
    std::string line;
    std::getline(file, line);
    size = std::stoi(line); // assumed to be good
    Matrix matrix1 = Matrix(size);
    Matrix matrix2 = Matrix(size);
    int row = 0;
    int col = 0;
    bool second = false;
    while (std::getline(file, line)) {
        std::stringstream sline(line);
        std::string token;
        while (std::getline(sline, token, ' ')) {
            int num = std::stoi(token);
            if (!second) {
                matrix1.setValue(row, col, num);
            } else {
                matrix2.setValue(row, col, num);
            }
            col++;
        }
        row++;
        col = 0;
        if (row == size) {
            row = 0;
            second = true;
        }
    }
    std::cout << "Matrix A:\n" << matrix1.format() << std::endl;
    std::cout << "Matrix B:\n" << matrix2.format() << std::endl;
    std::cout << "A + B:\n" << (matrix1 + matrix2).format() << std::endl;
    std::cout << "A * B:\n" << (matrix1 * matrix2).format() << std::endl;
    std::cout << "Diagonal sums for Matrix A:\n";
    std::cout << "Main diagonal sum: " << matrix1.sumDiagonals(false) << std::endl;
    std::cout << "Secondary diagonal sum: " << matrix1.sumDiagonals(true) << "\n\n";
    std::cout << "What is the first row you want to swap? ";
    std::string input;
    std::cin >> input;
    int row1 = std::stoi(input);
    std::cout << "What is the second row you want to swap? ";
    std::cin >> input;
    int row2 = std::stoi(input);
    std::cout << "\nProblem 5 - Rows " << row1 << " and " << row2 << " swapped:\n" << matrix1.swapRows(row1, row2).format() << std::endl;
    std::cout << "What is the first column you want to swap? ";
    std::cin >> input;
    int col1 = std::stoi(input);
    std::cout << "What is the second column you want to swap? ";
    std::cin >> input;
    int col2 = std::stoi(input);
    std::cout << "\nProblem 6 - Columns " << col1 << " and " << col2 << " swapped:\n" << matrix1.swapColumns(col1, col2).format() << std::endl;
    std::cout << "What is the row you want to set at? ";
    std::cin >> input;
    int newrow = std::stoi(input);
    std::cout << "What is the column you want to set at? ";
    std::cin >> input;
    int newcol = std::stoi(input);
    std::cout << "What is the value you want to set? ";
    std::cin >> input;
    int newvalue = std::stoi(input);
    matrix1.setValue(newrow, newcol, newvalue);
    std::cout << "\nProblem 7 - Updated matrix:\n" << matrix1.format() << std::endl;
    return 0;
}