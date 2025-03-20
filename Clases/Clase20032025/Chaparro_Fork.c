/***********************************************************************
 Fecha 20 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Creación de procesos con FORK
   Materia: Sistemas Operativos
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[]){
    int x;
    for(x=0; x<1; x++){
        fork();
        printf("The proces ID (PID): %d \n", getpid());
    }
    return 0;
}