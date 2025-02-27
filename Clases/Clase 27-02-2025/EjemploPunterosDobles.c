
#include <stdio.h>
#include <stdlib.h> //de aqui viene la funcion printf

#define size 10
int main(int argc, char *argv[]){

    int var= 480;
    int *varptr = &var;
    int **dobleptr = &varptr;
    printf("Valor de la variable \t\t= %d\n",var);
    printf("Valor del puntero \t\t= %d\n", *varptr);
    printf("Valor del puntero doble \t= %d\n",**dobleptr);


    printf("Direccion de la variable \t= %p\n",&var);

    printf("Direccion del puntero \t\t= %p\n",&varptr);
    printf("Valor del puntero \t\t= %p\n",varptr);

    printf("Direccion del puntero doble \t= %p\n",*dobleptr);
    printf("Valor del puntero doble \t= %p\n",dobleptr);
    
    return 0;

}