#include "matrix.h"
#include <fstream>

using namespace std;

Matrix::Matrix(const char *file) {
    load(file);
}

Matrix::Matrix() : row(0), column(0), arr(nullptr) {
}

void Matrix::load(const char *file) {
    ifstream in(file);
    in >> row >> column;
    arr = new int*[row];
    for (int i = 0;i < row;i++) {
        arr[i] = new int[column];
        for (int j = 0;j < column;j++) {
            in >> arr[i][j];
        }
    }
}

Matrix::~Matrix() {
    if (arr) {
        for (int i = 0;i < row;i++) {
            delete [] arr[i];
        }
        delete [] arr;
    }
}

void Matrix::display() const {
    printf("Matrix %d x %d\n", row, column);
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void Matrix::save(const char *file) const {
    ofstream out(file);
    out << row << " " << column << endl;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            out << arr[i][j] << " ";
        }
        out << endl;
    }
}

Matrix Matrix::multiply(const Matrix &another) const {
    if (column != another.row)
        throw "invalid matrix multiply";

    Matrix result;
    result.row = row;
    result.column = another.column;
    result.arr = new int*[row];
    for (int i = 0;i < row;i++) {
        result.arr[i] = new int[another.column];
        for (int j = 0;j < another.column;j++) {
            result.arr[i][j] = 0;
            for (int k = 0;k < column;k++) {
                result.arr[i][j] += arr[i][k] * another.arr[k][j];
            }
        }
    }
    return result;
}
