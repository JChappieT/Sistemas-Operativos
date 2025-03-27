 /***********************************************************************
 Fecha 27 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: ejercicion Threads
   Materia: Sistemas Operativos
   Archivo ejercicio2.c
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void *funcion(void *arg){
    printf("FUNCION HILO: INICIO\n");
    sleep(2); //ESPERA 2 SEGUNDOS (dormir)
    printf("FUNCION HILO: FIN\n");
    return NULL;
}

int main(int argc, char **argv[]){
    pthread_t hilo; //se identifica el hilo
    //Se crea el hilo, se envia la función
    int hiloCreacion = pthread_create(&hilo, NULL, &funcion, NULL);
    //Se verifica que el hilo se creo exitosamente
    if(hiloCreacion){
        printf("fallo de creacion de hilo :: %d\n", hiloCreacion);
    }else{
        printf("Hilo creado con id :: %d\n", hiloCreacion);
    }
    printf("Espera salida del hilo.....\n");
    hiloCreacion = pthread_join(hilo, NULL);//Se espera a que el proceso del hilo finalice
    //Se verifica sale exitosamente
    if(hiloCreacion){
        printf("fallo de creacion de hilo :: %d\n", hiloCreacion);
    }
    printf("Final del programa principal.\n");
    return 0;

}