#include <stdio.h>
#include <stdbool.h>

bool CumpleProp(int x){
    if(x < 1000 || x > 9999){
        printf("El numero ingresado no es un numero de 4 dígitos. \n");
        return false;
    }

    int a = x / 100;
    int b = x % 100;
    int s = a + b ;

    if (s*s == x){
        printf("%d si cumple con la propiedad. (%d + %d)^2 = %d\n" , x, x);
        return true;
    } else{
        printf("%d no cumple con la propiedad. (%d + %d)^2 = %d\n" , x , s*s);
        return false;
    }
}

int main() {
    int n;
    printf( "Ingresar  un numero de cuatro digitos: \n "); 
    scanf("%d", &n);
    CumpleProp(n);
    return 0;
}
