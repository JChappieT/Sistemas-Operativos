
/**********************************************************
 Fecha 27 02 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Apuntadores
   Materia: Sistemas Operativos
   
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************/
#include <stdio.h>
#include <stdlib.h> //de aqui viene la funcion printf

#define size 10
int main(int argc, char *argv[]){

    int *vectorPunteros[3];
    int p=49, q=80, r=120;
    vectorPunteros[0]= &p;
    vectorPunteros[1]= &q;
    vectorPunteros[2]= &r;

    printf("\nForma de acceso al vector de punteros: \tValores:\n");
    for(int i=0; i<3; i++){
        printf("Para la direccion %p \t%d\n", vectorPunteros[i], *vectorPunteros[i]);
    }
    return 0;

}