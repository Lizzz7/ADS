#include <stdio.h>

int existe(int arr[], int size, int val) {
    for (int i = 0; i < size; i++)
        if (arr[i] == val)
            return 1;
    return 0;
}

int interseccion(int a[], int na, int b[], int nb, int res[]) {
    int k = 0;
    for (int i = 0; i < na; i++) {
        if (existe(b, nb, a[i]) && !existe(res, k, a[i])) {
            res[k++] = a[i];
        }
    }
    return k;
}

int union_sets(int a[], int na, int b[], int nb, int res[]) {
    int k = 0;

    for (int i = 0; i < na; i++) {
        if (!existe(res, k, a[i]))
            res[k++] = a[i];
    }

    for (int i = 0; i < nb; i++) {
        if (!existe(res, k, b[i]))
            res[k++] = b[i];
    }

    return k;
}

int diferencia(int a[], int na, int b[], int nb, int res[]) {
    int k = 0;
    for (int i = 0; i < na; i++) {
        if (!existe(b, nb, a[i]) && !existe(res, k, a[i])) {
            res[k++] = a[i];
        }
    }
    return k;
}

void leerConjunto(int arr[], int *n) {
    int x;
    *n = 0;
    while (scanf("%d", &x) == 1) {
        arr[(*n)++] = x;
        if (getchar() == '\n') break;
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int a[100], b[100];
    int na, nb;

    printf("Ingrese conjunto 1: ");
    leerConjunto(a, &na);

    printf("Ingrese conjunto 2: ");
    leerConjunto(b, &nb);

    int res[200];
    int n;

    n = interseccion(a, na, b, nb, res);
    printf("La intersección es: ");
    imprimir(res, n);

    n = union_sets(a, na, b, nb, res);
    printf("La unión es: ");
    imprimir(res, n);

    n = diferencia(a, na, b, nb, res);
    printf("La diferencia es: ");
    imprimir(res, n);

    return 0;
}

