#include <stdio.h>
#include <stdbool.h>

void ingresar(int[][10], int, int);
void mostrar(int[][10], int, int);
void copiar(int[][10], int[][10], int, int);
void invertir(int[][10], int, int);
bool comparar(int[][10], int[][10], int, int);
void permutarFilas(int[][10], int, int, int); // fila1 y fila2

void ingresar(int M[][10], int f, int c)
{
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &M[i][j]);
}

void mostrar(int M[][10], int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
}

void copiar(int A[][10], int B[][10], int f, int c)
{
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            B[i][j] = A[i][j];
}

void invertir(int M[][10], int f, int c)
{
    for (int i = 0; i < f / 2; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int temp = M[i][j];
            M[i][j] = M[f - 1 - i][j];
            M[f - 1 - i][j] = temp;
        }
    }
}

bool comparar(int A[][10], int B[][10], int f, int c)
{
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            if (A[i][j] != B[i][j])
                return false;
    return true;
}

void permutarFilas(int M[][10], int f, int fila1, int fila2)
{
    for (int j = 0; j < 10; j++)
    {
        int temp = M[fila1][j];
        M[fila1][j] = M[fila2][j];
        M[fila2][j] = temp;
    }
}


int main()
{
    int A[10][10], B[10][10];
    int f, c;

    printf("Cantidad de filas? ");
    scanf("%d", &f);
    printf("Cantidad de columnas? ");
    scanf("%d", &c);

    printf("Ingresando datos a la matriz A:\n");
    ingresar(A, f, c);

    printf("Matriz A original:\n");
    mostrar(A, f, c);

    printf("Copiando A en B...\n");
    copiar(A, B, f, c);
    printf("Matriz B copiada:\n");
    mostrar(B, f, c);

    printf("Invirtiendo A...\n");
    invertir(A, f, c);
    printf("Matriz A invertida:\n");
    mostrar(A, f, c);

    printf("Comparando A con B...\n");
    if (comparar(A, B, f, c))
        printf("Las matrices son iguales\n");
    else
        printf("Las matrices son diferentes\n");

    printf("Permutando la fila 0 con la fila 1 en B...\n");
    if (f >= 2)
    {
        permutarFilas(B, f, 0, 1);
        mostrar(B, f, c);
    }
    else
    {
        printf("No hay suficientes filas para permutar.\n");
    }

    return 0;
}

