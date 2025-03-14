
/***************************************************************
 Fecha 14 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   VECTOR.H DE MULTIPLICACION DE MATRICES Y VECTORES DINAMICOS
   PONTIFICIA UNIVERSIDAD JAVERIANA
***************************************************************/
#ifndef __VECTOR_H
#define __VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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