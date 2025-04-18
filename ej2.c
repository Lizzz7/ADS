
#include <stdio.h>
#include <stdbool.h>

bool Capicua(int x){
    if(x < 0){
        printf("El numero ingresado no es un numero positivo. \n");
        return false;
    }

    int numero = x;
    int invertido = 0;

    while (x > 0){
        int d = x % 10;
        invertido = invertido * 10 + d;
        x = x / 10;
    }
    
    if (numero == invertido){
        printf("%d si es capicua. \n", numero) << endl;
        return true;
    } else{
        printf("%d no es capicua. \n", numero) << endl;
        return false;
    }
}
int main() {
    int n;
    printf("Ingresar  un numero: \n"); 
    scanf("%d", &n);
    Capicua(n);
    return 0;
}


