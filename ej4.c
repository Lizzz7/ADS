#include<stdio.h>

int main(){
    int c = 0;
    int a, b;

    while (c != 5){ 
        printf("\n------------------MENU---------------\n");
        printf("1) Suma \n");    
        printf("2) Resta \n"); 
        printf("3) Multiplicacion \n");
        printf("4) División \n"); 
        printf("5) Salida \n");
        printf( "Ingresa una opción: ");
        scanf("%d", &c);

        if(c > 0 && c < 5){  
            printf("Ingrese el primer numero: ");
            scanf("%d", &a);
            printf("Ingrese el segundo numero: ");
            scanf("%d", &b);
        }

        switch(c){
            case 1:
                printf("la suma es: %d\n", a + b);break;
            case 2:
                printf("la resta es: %d\n", a - b);break;
            case 3:
                printf("la multiplicacion es: %d\n", a * b);break;
            case 4:
                if( b!= 0){
                    printf("la division es: "%.2f\n", (float)a / b);
                }else{
                    printf("no se puede dividir entre 0\n);
                }
                break;
            case 5:
                break;
            default:
                printf("Opción invalida \n");
        }
    }

    return 0;
}

