// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <map>

class Matrix {
protected:
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols);

    virtual void setElement(int row, int col, int value);
    virtual int getElement(int row, int col) const;

    void print() const;
    void transpose();
    void swapRows(int row1, int row2);
    int getRows() const;
    int getCols() const;
};

class MatrixNxN : public Matrix {
public:
    MatrixNxN(int size);
};

class MatrixMxN : public Matrix {
public:
    MatrixMxN(int rows, int cols);
};

#endif // MATRIX_H
