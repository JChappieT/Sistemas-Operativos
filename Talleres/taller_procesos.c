/***********************************************************************
 Fecha 30 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: funciones fork() y pipe()
   Materia: Sistemas Operativos
   Taller2: Archivo taller_procesos.c
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//Función para leer un archivo y almacenar los números en un arreglo
void leer_archivo(const char *nombre, int *arr, int n) {
    FILE *file = fopen(nombre, "r");
    if (!file) {
        perror("Error abriendo archivo");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}
//Función para calcular la suma de los elementos de un arreglo
int calcular_suma(int *arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Uso: %s N1 archivo00 N2 archivo01\n", argv[0]);
        return EXIT_FAILURE;
    }
    //Se extraen de los argumentos de la línea de comandos los valores de N1, archivo00, N2 y archivo01
    int N1 = atoi(argv[1]);
    char *archivo00 = argv[2];
    int N2 = atoi(argv[3]);
    char *archivo01 = argv[4];

    //Vectores con memoria dinámica
    int *arr1 = (int *)malloc(N1 * sizeof(int));
    int *arr2 = (int *)malloc(N2 * sizeof(int));
    if (!arr1 || !arr2) {
        perror("Error al asignar memoria");
        return EXIT_FAILURE;
    }

    leer_archivo(archivo00, arr1, N1);
    leer_archivo(archivo01, arr2, N2);

    //Se crea el pipe fd[2] para la comunicación entre procesos
    //Siendo fd[0] el extremo de lectura y fd[1] el extremo de escritura
    int fd[2];
    pipe(fd);

    //Se crean tres identificadores de procesos
    pid_t pid1, pid2, pid3;
    //Se crea el primer proceso hijo pid1
    if ((pid1 = fork()) == 0) {
        //Se crea el proceso nieto pid2
        if ((pid2 = fork()) == 0) {
            //pid2 hace la suma del archivo00
            int sumaA = calcular_suma(arr1, N1);
            //pid2 escribe la suma en el pipe fd[1]
            write(fd[1], &sumaA, sizeof(int));
            exit(0);
        } else {
            //pid1 espera a que pid2 termine
            wait(NULL);
            //pid1 hace la suma del archivo01
            int sumaB = calcular_suma(arr2, N2);
            //pid1 escribe la suma en el pipe fd[1]
            write(fd[1], &sumaB, sizeof(int));
            exit(0);
        }
    } else {
        //Se crea el segundo proceso hijo pid3
        if ((pid3 = fork()) == 0) {
            wait(NULL);
            //pid3 espera a que pid1 termine
            int sumaTotal = calcular_suma(arr1, N1) + calcular_suma(arr2, N2);
            //pid3 escribe la suma en el pipe fd[1]
            write(fd[1], &sumaTotal, sizeof(int));
            exit(0);
        } else {
            //El proceso padre espera a que pid1 y pid3 terminen
            wait(NULL);
            wait(NULL);
            int sumaA, sumaB, sumaTotal;
            //El proceso padre lee las sumas del pipe fd[0]
            read(fd[0], &sumaA, sizeof(int));
            read(fd[0], &sumaB, sizeof(int));
            read(fd[0], &sumaTotal, sizeof(int));
            //Se muestran los resultados de las sumas
            printf("Suma archivo00: %d\n", sumaA);
            printf("Suma archivo01: %d\n", sumaB);
            printf("Suma total: %d\n", sumaTotal);
        }
    }
    //Se cierran los extremos del pipe fd[0] y fd[1]
    close(fd[0]);
    close(fd[1]);
    //Se liberan los punteros de memoria
    free(arr1);
    free(arr2);
    return EXIT_SUCCESS;
}
