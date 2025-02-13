/* Fecha 29 01 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, complejidad algoritmica en C
   Materia: Estructuras de Datos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para inicializar las matrices
void iniMatriz(int **a, int **b, int **c, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)malloc(n * sizeof(int));
        
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 51;
            b[i][j] = rand() % 51;
            c[i][j] = 0;
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

// Función para multiplicar matrices
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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <tamaño de la matriz>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int **mA = (int **)malloc(n * sizeof(int *));
    int **mB = (int **)malloc(n * sizeof(int *));
    int **mC = (int **)malloc(n * sizeof(int *));

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
