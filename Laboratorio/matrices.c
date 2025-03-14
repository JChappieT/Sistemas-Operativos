/***************************************************************
 Fecha 14 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   MATRICES.C DE MULTIPLICACION DE MATRICES Y VECTORES DINAMICOS
   PONTIFICIA UNIVERSIDAD JAVERIANA
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrices.h"
#include <string.h>

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
    if(n<6){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
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
void eliminarMemoria(int **a, int **b, int **c, int n){
    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
}




