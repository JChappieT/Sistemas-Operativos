/***************************************************************
 Fecha 14 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   VECTOR.C DE MULTIPLICACION DE MATRICES Y VECTORES DINAMICOS
   PONTIFICIA UNIVERSIDAD JAVERIANA
***************************************************************/
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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