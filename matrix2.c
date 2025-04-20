//Floating points and Matrices
/*1. While the numeric types in Python are relatively simple: int, float or complex, in
C the situation is more complicated. There is no complex type, we have several
different integer types, which allow us to store different ranges, can be signed or
unsigned, in addition to at least two types of floating point numbers (float, double).
Choose a suitable variable type to store the following information depending on the
situation and try to explain your reasoning:*/
/*
• The age of a person in a form for a database with millions of records. 
I use unsigned char. Because It uses only 1 byte, It's useful for saving space.
• The age of a person in days for a program in which we want to add or subtract
an arbitrary number of days.
I use unsigned int. Because it allows for positive numbers needed for common operations.
• A student’s grade.
I use float. Because It allows you to store decimal and integer numbers.
• The average amount of rainfall in the month of February.
I use float. Because it allows you to store decimal numbers sufficient to specify the data needed for this variable.
• The angle of rotation of a robot surgeon to be broadcast over the internet. 
I use float. Because I use float when I need a lot of precision.
• The size of your backyard.
I use float or double. Because depending on the specificity of the data we want, and the exact measurement is needed.
• The number of stars in the universe.
I use unsigned long long. Because I use it when I need a large capacity to store large numbers.
• The balance of your bank account. 
I use double. Because float is not enough.
• The position of a particle in a high-resolution game.
I use float. Because the coordinates in the game must be exact.
*/


#include <stdio.h>

#define MAX 10

void ingresar(int M[][MAX], int f, int c);
void mostrar(int M[][MAX], int f, int c);
int esSimetrica(int M[][MAX], int n);
void transpuesta(int M[][MAX], int R[][MAX], int f, int c);
int determinante3x3(int M[3][3]);
void producto(int A[][MAX], int B[][MAX], int R[][MAX], int f1, int c1, int c2);

int main() {
    int op;
    do {
        printf("\n------------ MENU ------------------\n");
        printf("1. Verificar si la matriz es simétrica\n");
        printf("2. Calcular transpuesta\n");
        printf("3. Determinante de matriz 3x3\n");
        printf("4. Producto de dos matrices\n");
        printf("0. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &op);

        if (op == 1) {
            int M[MAX][MAX], n;
            printf("Orden de la matriz cuadrada (n): ");
            scanf("%d", &n);
            printf("Ingrese matriz %dx%d:\n", n, n);
            ingresar(M, n, n);
            mostrar(M, n, n);
            if (esSimetrica(M, n))
                printf("La matriz es simétrica.\n");
            else
                printf("La matriz NO es simétrica.\n");
        }
        else if (op == 2) {
            int M[MAX][MAX], R[MAX][MAX], f, c;
            printf("Filas: ");
            scanf("%d", &f);
            printf("Columnas: ");
            scanf("%d", &c);
            printf("Ingrese matriz %dx%d:\n", f, c);
            ingresar(M, f, c);
            transpuesta(M, R, f, c);
            printf("Matriz original:\n");
            mostrar(M, f, c);
            printf("Matriz transpuesta:\n");
            mostrar(R, c, f);
        }
        else if (op == 3) {
            int M[3][3];
            printf("Ingrese matriz 3x3:\n");
            ingresar(M, 3, 3);
            mostrar(M, 3, 3);
            int det = determinante3x3(M);
            printf("Determinante = %d\n", det);
        }
        else if (op == 4) {
            int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
            int f1, c1, f2, c2;
            printf("Filas y columnas de A: ");
            scanf("%d %d", &f1, &c1);
            printf("Filas y columnas de B: ");
            scanf("%d %d", &f2, &c2);

            if (c1 != f2) {
                printf("No se puede multiplicar: columnas de A ≠ filas de B\n");
            } else {
                printf("Ingrese matriz A:\n");
                ingresar(A, f1, c1);
                printf("Ingrese matriz B:\n");
                ingresar(B, f2, c2);
                producto(A, B, R, f1, c1, c2);
                printf("Matriz resultado:\n");
                mostrar(R, f1, c2);
            }
        }

    } while (op != 0);

    return 0;
}

void ingresar(int M[][MAX], int f, int c) {
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &M[i][j]);
}

void mostrar(int M[][MAX], int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
}

int esSimetrica(int M[][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (M[i][j] != M[j][i])
                return 0;
    return 1;
}

void transpuesta(int M[][MAX], int R[][MAX], int f, int c) {
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            R[j][i] = M[i][j];
}

int determinante3x3(int M[3][3]) {
    int a = M[0][0], b = M[0][1], c = M[0][2];
    int d = M[1][0], e = M[1][1], f = M[1][2];
    int g = M[2][0], h = M[2][1], i = M[2][2];
    return a * (e * i - f * h)
         - b * (d * i - f * g)
         + c * (d * h - e * g);
}

void producto(int A[][MAX], int B[][MAX], int R[][MAX], int f1, int c1, int c2) {
    for (int i = 0; i < f1; i++)
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

