#include <stdio.h>
#include "matrix.h"

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d", &r1, &c1);
    Matrix A = matrix_new(r1, c1);
    matrix_read(&A);

    scanf("%d %d", &r2, &c2);
    Matrix B = matrix_new(r2, c2);
    matrix_read(&B);

    if (r1 == r2 && c1 == c2) {
        Matrix sum = matrix_add(A, B);
        printf("Sum:\n");
        matrix_print(sum);
    } else {
        printf("Matrices cannot be added (size mismatch).\n");
    }

    if (c1 == r2) {
        Matrix product = matrix_multiply(A, B);
        printf("Product:\n");
        matrix_print(product);
    } else {
        printf("Matrices cannot be multiplied (incompatible sizes).\n");
    }

    return 0;
}

