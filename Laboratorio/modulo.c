/***************************************************************
 Fecha 14 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   MODULO.C DE MULTIPLICACION DE MATRICES Y VECTORES DINAMICOS
   PONTIFICIA UNIVERSIDAD JAVERIANA
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h"
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

//FUNCION PARA CAMBIAR EL TAMAÑO DEL VECTOR
static void resizeVector(vectorDinamico *V, int capacidad) {
    printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

    void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
    if (elementos) {
        V->elementos = elementos;
        V->capacidad = capacidad;
    }
}
//FUNCION PARA INICIALIZAR EL VECTOR
void vectorInicio(vectorDinamico *V) {
    V->capacidad = CAPACIDAD_INICIAL;
    V->totalElementos = 0;
    V->elementos = malloc(sizeof(void *) * V->capacidad);
}
//FUNCION PARA RETORNAR EL TOTAL DE ELEMENTOS DEL VECTOR
int totalVector(vectorDinamico *V) {
    return V->totalElementos;
}
//FUNCION PARA AGREGAR DATOS AL VECTOR
void addVector(vectorDinamico *V, void *elemento) {
    if (V->capacidad == V->totalElementos)
        resizeVector(V, V->capacidad * 2);
    V->elementos[V->totalElementos++] = strdup((char *)elemento);
}
//FUNCION PARA LIBERAR EL ESPACIO DEL VECTOR
void freeVector(vectorDinamico *V) {
    for (int i = 0; i < V->totalElementos; i++) {
        free(V->elementos[i]); // Liberar cada palabra
    }
    free(V->elementos); // Luego liberar el arreglo de punteros
}

//FUNCION PARA DEVOLVER EL VECTOR
void *getVector(vectorDinamico *V, int indice) {
    if (indice >= 0 && indice < V->totalElementos)
        return V->elementos[indice];
    return NULL;
}
//FUNCION PARA CAMBIA EL VALOR DE UN ESPACIO ESPECIFICO DEL VECTOR
void setVector(vectorDinamico *V, int indice, void *elemento) {
    if (indice >= 0 && indice < V->totalElementos)
        V->elementos[indice] = elemento;
}
//FUNCION PARA BORRAR EL VECTOR
void borrarVector(vectorDinamico *V, int indice) {
    if (indice < 0 || indice >= V->totalElementos)
        return;

    V->elementos[indice] = NULL;

    for (int i = indice; i < V->totalElementos - 1; i++) {
        V->elementos[i] = V->elementos[i + 1];
        V->elementos[i + 1] = NULL;
    }
    V->totalElementos--;
    if (V->totalElementos > 0 && V->totalElementos == V->capacidad / 4)
        resizeVector(V, V->capacidad / 2);
}



