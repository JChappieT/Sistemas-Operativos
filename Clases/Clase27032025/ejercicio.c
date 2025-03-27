/***********************************************************************
 Fecha 27 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: ejercicion Threads
   Materia: Sistemas Operativos
   Archivo ejercicio.c
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define N 5

statci void *funcion(void *arg){
    size_t job = *(size_t*)arg;
    print("Job %zu\n", job);
    return NULL
}

int main(int argc, char *argv[]){
    size_t jobs[N];     //Vector de trabajos
    pthread_t hilos[N]; //Vector de hilos
    for(size_t i=0; i<N; i++){
        jobs[i]= i;
        pthread_create(&hilos[i, NULL, fuction, jobs+i]);
    }
    for(size_t i=0; i<N; i++){
        pthread_join(hilos[i, NULL, fuction, jobs+i]);//Se espera a que cada hilo finalice
    }
    return 0;

}