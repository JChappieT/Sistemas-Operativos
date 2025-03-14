#ifndef __MATRICES_H
#define __MATRICES_H
/***************************************************************
 Fecha 14 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   MATRICES.H DE MULTIPLICACION DE MATRICES Y VECTORES DINAMICOS
   PONTIFICIA UNIVERSIDAD JAVERIANA
***************************************************************/

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



#endif
