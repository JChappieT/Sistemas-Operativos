#ifndef __MODULO_H
#define __MODULO_H
/**********************************************************
 Fecha 14 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   INTERFACE DE FUNCIONES Y VECTOR DINÁMICO: BIBLIOTECA
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Función para inicializar las matrices, asignacion de memoria
void iniMatriz(int **a, int **b, int **c, int n);

// Función para mostrar las matrices
void mostrMatrices(int **a, int n);

// Función para multiplicar matrices algoritmo clasico
void multiMatrices(int **a, int **b, int **c, int n);

/*Funcion para liberar memoria*/
void eliminarMemoria(int **a, int **b, int **c, int n);

#define CAPACIDAD_INICIAL 4

typedef struct {
    int capacidad;
    int totalElementos;
    void **elementos;
} vectorDinamico;
//FUNCION PARA INICIALIZAR EL VECTOR
void vectorInicio(vectorDinamico *V);
//FUNCION PARA RETORNAR EL TOTAL DE ELEMENTOS DEL VECTOR
int totalVector(vectorDinamico *V);
//FUNCION PARA AGREGAR DATOS AL VECTOR
void addVector(vectorDinamico *V, void *elemento);
//FUNCION PARA LIBERAR EL ESPACIO DEL VECTOR
void freeVector(vectorDinamico *V);
//FUNCION PARA DEVOLVER EL VECTOR
void *getVector(vectorDinamico *V, int indice);
//FUNCION PARA CAMBIA EL VALOR DE UN ESPACIO ESPECIFICO DEL VECTOR
void setVector(vectorDinamico *V, int indice, void *elemento);
//FUNCION PARA BORRAR EL VECTOR
void borrarVector(vectorDinamico *V, int indice);

#endif
