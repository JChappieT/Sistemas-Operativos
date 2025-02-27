
#include <stdio.h>
#include <stdlib.h> //de aqui viene la funcion printf

int main(int argc, char *argv[]){

    int variable = 123;
    int *ptr = &variable;
    printf("Valor de la variable %d \n", variable); //%d es para enteros, si no lo pongo no muestra el valor
    printf("Direccion de memoria de la variable %p \n", &variable); //%p es para direccion de memoria
    printf("Direccion a la que apunta el puntero %p \n", (void*)ptr);
    printf("Valor de la variable %i \n", *ptr); //%d y %i en la funcion printf sirven para lo mismo, su funcionalidad cambia cuando se usa en scanf

    return 0;

}