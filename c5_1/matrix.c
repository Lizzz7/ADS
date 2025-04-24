#include <stdio.h>
#include "matrix.h"

Matrix matrix_new(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    return m;
}

void matrix_read(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            scanf("%lf", &m->data[i][j]);
        }
    }
}

void matrix_print(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%6.2lf ", m.data[i][j]);
        }
        printf("\n");
    }
}

Matrix matrix_add(Matrix a, Matrix b) {
    Matrix r = matrix_new(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            r.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return r;
}

Matrix matrix_multiply(Matrix a, Matrix b) {
    Matrix r = matrix_new(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            r.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                r.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return r;
}

