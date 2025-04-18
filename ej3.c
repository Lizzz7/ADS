/*En Python es posible y facil, en C no, no es posible porque no se puede cambiar el valor de una variable sin usar una variable auxiliar, solo podriamos hacerlo asi */

#include <stdio.h>

int main(){
    int x = 7;
    int y = 10;
    int aux = x;// aux= 7 & x= 7 la asignacion siempre es de derecha a izquierda
    x = y;//y=10 & x=10
    y = aux;//y=7 & aux=7
    cout << aux << " " << y << " " <<x <<endl;
    return 0;
}

/*De otra manera se podria realizar con operaciones matematicas simples*/

#include <stdio.h>

int main() {
    int x = 7;
    int y = 10;

    x = x + y; // x = 17
    y = x - y; // y = 7
    x = x - y; // x = 10

    printf("x = %d, y = %d\n", x, y);

    return 0;
}


