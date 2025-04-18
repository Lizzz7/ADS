#include <stdio.h>
#include <stdlib.h> 

int main() {
    int num;
    int min, max;
    int primero = 1;

    printf("Ingrese una lista de números:\n");

    while (1) {
        scanf("%d", &num);
        if (num == -1){
   	break;
	}
 
        if (primero) {
            min = max = num;
            primero = 0;
        } else {
            if (num < min) min = num;
            if (num > max) max = num;
        }
    }

    printf("La diferencia absoluta es = %d\n", abs(max - min));
    return 0;
}
