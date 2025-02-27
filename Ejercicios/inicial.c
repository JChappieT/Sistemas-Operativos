/**********************************************************
 Fecha 20 02 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para inicializar las matrices, asignacion de memoria
void iniMatriz(int **a, int **b, int **c, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)calloc(n, sizeof(int));
        
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 51;
            b[i][j] = rand() % 51;
        }
    }
}

// Función para mostrar las matrices
void mostrMatrices(int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Función para multiplicar matrices algoritmo clasico
void multiMatrices(int **a, int **b, int **c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int suma = 0;
            for (int k = 0; k < n; k++) {
                suma += a[i][k] * b[k][j];
            }
            c[i][j] = suma;
        }
    }
}
/*Funcion para liberar memoria*/

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
    for (int i = 0; i < n; i++) {
        free(mA[i]);
        free(mB[i]);
        free(mC[i]);
    }
    free(mA);
    free(mB);
    free(mC);

    return 0;
}
