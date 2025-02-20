/**********************************************************
 Fecha 20 02 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
    PROGRAMA PRINCIPAL MULTIPLICACION DE MATRICES
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <tamaño de la matriz>\n", argv[0]);
        return 1;
    }
    //Tomar el argumento para el tamaño de las matrices brindado por el usuario
    int n = atoi(argv[1]);
    /*CREACION DE LAS MATRICES*/
    int **mA = (int **)malloc(n * sizeof(int *));
    int **mB = (int **)malloc(n * sizeof(int *));
    int **mC = (int **)calloc(n, sizeof(int *));

    iniMatriz(mA, mB, mC, n);
    
    // Multiplicamos las matrices A x B = C
    multiMatrices(mA, mB, mC, n);
    
    // Se imprimen las matrices
    printf("\nMatriz A\n");
    mostrMatrices(mA, n);
    
    printf("\nMatriz B\n");
    mostrMatrices(mB, n);
    
    printf("\nMatriz C\n");
    mostrMatrices(mC, n);

    // Liberar memoria
    eliminarMemoria(mA, mB, mC, n);

    return 0;
}
