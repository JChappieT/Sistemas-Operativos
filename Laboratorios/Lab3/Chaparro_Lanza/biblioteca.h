#ifndef __BIBLIOTECA_H
#define __BIBLIOTECA_H
/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Jeronimo Chaparro Tenorio
        Fecha: Abril 2024
        Materia: Sistemas Operativos
        Tema: Taller de Evaluación de Rendimiento
        Fichero: fuente de multiplicación de matrices NxN por hilos.
        Objetivo: Evaluar el tiempo de ejecución del
                      algoritmo clásico de multiplicación de matrices.
                          Se implementa con la Biblioteca POSIX Pthreads
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Define el tamaño del buffer de memoria para las matrices
#define DATA_SIZE (1024*1024*64*3)

// Declaración del mutex para sincronización
pthread_mutex_t MM_mutex;

// Reservas estáticas de memoria para las matrices
static double MEM_CHUNK[DATA_SIZE];
double *mA, *mB, *mC;

// Estructura que contiene los parámetros para cada hilo
struct parametros{
        int nH;  // Número de hilos
        int idH; // ID del hilo actual
        int N;   // Dimensión de la matriz
};

// Variables para medir el tiempo
struct timeval start, stop;

/**
 * Nombre: llenar_matriz.
 * descripcion: Rellena las matrices mA y mB con valores predefinidos.
 * Argumentos SZ que es el tamaño de la matriz .
 */
void llenar_matriz(int SZ);

/**
 * Nombre: print_matrix
 * Descripcion: Imprime una matriz en la consola si el tamaño es pequeño.
 * Argumentos: sz que es el tamaño de la matriz y matriz que es un puntero a la matriz a imprimir.
*/
void print_matrix(int sz, double *matriz);

/*
 * Nombre: inicial_tiempo.
 * Descripcion: Inicia la medición del tiempo.
*/
void inicial_tiempo();

/*
 * Nombre: final_tiempo.
 * Descripcion: Finaliza la medición del tiempo e imprime el resultado.
*/
void final_tiempo();

/*
 * Nombre: mult_thread.
 * Descripcion: Multiplicación de matrices por hilos utilizando metodo clasico.
 * Argumentos: variables Puntero a la estructura de parámetros.
*/
void *mult_thread(void *variables);

#endif

