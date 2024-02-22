#include <iostream>
#include <vector>
#include <random>
#include <map>

class Matrix {
protected:
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols) : data(rows, std::vector<int>(cols, 0)) {}

    virtual void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    virtual int getElement(int row, int col) const {
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

class MatrixNxN : public Matrix {
public:
    MatrixNxN(int size) : Matrix(size, size) {}
};

class MatrixMxN : public Matrix {
public:
    MatrixMxN(int rows, int cols) : Matrix(rows, cols) {}
};

int main() {
    std::map<std::string, Matrix*> matrices;

    while (true) {
        std::string command;
        std::cout << "Enter command (init/print/set/get/transpose/swap/exit): ";
        std::cin >> command;

        if (command == "init") {
            std::string name;
            int rows, cols;
            std::cout << "Enter name of the matrix, number of rows, and number of columns: ";
            std::cin >> name >> rows >> cols;
            if (rows == cols)
                matrices[name] = new MatrixNxN(rows);
            else
                matrices[name] = new MatrixMxN(rows, cols);
            std::cout << "Matrix initialized with name '" << name << "'." << std::endl;
        } else if (command == "print") {
            std::string name;
            std::cout << "Enter name of the matrix: ";
            std::cin >> name;
            if (matrices.find(name) != matrices.end()) {
                matrices[name]->print();
            } else {
                std::cout << "Matrix not found." << std::endl;
            }
        } else if (command == "set") {
            std::string name;
            int row, col, value;
            std::cout << "Enter name of the matrix, row, column, and value: ";
            std::cin >> name >> row >> col >> value;
            if (matrices.find(name) != matrices.end()) {
                if (row >= 0 && row < matrices[name]->getRows() && col >= 0 && col < matrices[name]->getCols()) {
                    matrices[name]->setElement(row, col, value);
                    std::cout << "Element set successfully." << std::endl;
                } else {
                    std::cout << "Invalid row or column index." << std::endl;
                }
            } else {
                std::cout << "Matrix not found." << std::endl;
            }
        } else if (command == "get") {
            std::string name;
            int row, col;
            std::cout << "Enter name of the matrix, row, and column: ";
            std::cin >> name >> row >> col;
            if (matrices.find(name) != matrices.end()) {
                if (row >= 0 && row < matrices[name]->getRows() && col >= 0 && col < matrices[name]->getCols()) {
                    std::cout << "Value at (" << row << ", " << col << "): " << matrices[name]->getElement(row, col) << std::endl;
                } else {
                    std::cout << "Invalid row or column index." << std::endl;
                }
            } else {
                std::cout << "Matrix not found." << std::endl;
            }
        } else if (command == "transpose") {
            std::string name;
            std::cout << "Enter name of the matrix: ";
            std::cin >> name;
            if (matrices.find(name) != matrices.end()) {
                matrices[name]->transpose();
                std::cout << "Matrix transposed." << std::endl;
            } else {
                std::cout << "Matrix not found." << std::endl;
            }
        } else if (command == "swap") {
            std::string name;
            int row1, row2;
            std::cout << "Enter name of the matrix and rows to swap: ";
            std::cin >> name >> row1 >> row2;
            if (matrices.find(name) != matrices.end()) {
                if (row1 >= 0 && row1 < matrices[name]->getRows() && row2 >= 0 && row2 < matrices[name]->getRows()) {
                    matrices[name]->swapRows(row1, row2);
                    std::cout << "Rows swapped." << std::endl;
                } else {
                    std::cout << "Invalid row index." << std::endl;
                }
            } else {
                std::cout << "Matrix not found." << std::endl;
            }
        } else if (command == "exit") {
            std::cout << "Exiting program." << std::endl;
            // Release memory allocated for matrices
            for (auto& pair : matrices) {
                delete pair.second;
            }
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
