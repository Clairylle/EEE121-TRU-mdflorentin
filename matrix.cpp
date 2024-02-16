#include <iostream>
#include <vector>
#include <random>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols) : data(rows, std::vector<int>(cols, 0)) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);

        for (auto& row : data) {
            for (int& element : row) {
                element = dis(gen);
            }
        }
    }

    void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    int getElement(int row, int col) const {
        return data[row][col];
    }

    void print() const {
        for (const auto& row : data) {
            for (int element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }

    void transpose() {
        std::vector<std::vector<int>> transposed(data[0].size(), std::vector<int>(data.size(), 0));
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                transposed[j][i] = data[i][j];
            }
        }
        data = transposed;
    }

    void swapRows(int row1, int row2) {
        std::swap(data[row1], data[row2]);
    }

    int getRows() const {
        return data.size();
    }

    int getCols() const {
        return data[0].size();
    }
};

int main() {
    Matrix matrix(0, 0);

    while (true) {
        std::string command;
        std::cout << "Enter command (init/print/set/get/transpose/swap/exit): ";
        std::cin >> command;

        if (command == "init") {
            int size;
            std::cout << "Enter size of the square matrix: ";
            std::cin >> size;
            matrix = Matrix(size, size);
            std::cout << size << "x" << size << " matrix initialized." << std::endl;
        } else if (command == "print") {
            matrix.print();
        } else if (command == "set") {
            int row, col, value;
            std::cout << "Enter row, column, and value: ";
            std::cin >> row >> col >> value;
            if (row >= 0 && row < matrix.getRows() && col >= 0 && col < matrix.getCols()) {
                matrix.setElement(row, col, value);
                std::cout << "Element set successfully." << std::endl;
            } else {
                std::cout << "Invalid row or column index." << std::endl;
            }
        } else if (command == "get") {
            int row, col;
            std::cout << "Enter row and column: ";
            std::cin >> row >> col;
            if (row >= 0 && row < matrix.getRows() && col >= 0 && col < matrix.getCols()) {
                std::cout << "Value at (" << row << ", " << col << "): " << matrix.getElement(row, col) << std::endl;
            } else {
                std::cout << "Invalid row or column index." << std::endl;
            }
        } else if (command == "transpose") {
            matrix.transpose();
            std::cout << "Matrix transposed." << std::endl;
        } else if (command == "swap") {
            int row1, row2;
            std::cout << "Enter rows to swap: ";
            std::cin >> row1 >> row2;
            if (row1 >= 0 && row1 < matrix.getRows() && row2 >= 0 && row2 < matrix.getRows()) {
                matrix.swapRows(row1, row2);
                std::cout << "Rows swapped." << std::endl;
            } else {
                std::cout << "Invalid row index." << std::endl;
            }
        } else if (command == "exit") {
            std::cout << "Exiting program." << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
