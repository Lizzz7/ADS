#ifndef MATRIX_H
#define MATRIX_H

#define MAX 10

typedef struct {
    int rows, cols;
    double data[MAX][MAX];
} Matrix;

Matrix matrix_new(int rows, int cols);
void matrix_read(Matrix* m);
void matrix_print(Matrix m);
Matrix matrix_add(Matrix a, Matrix b);
Matrix matrix_multiply(Matrix a, Matrix b);

#endif

