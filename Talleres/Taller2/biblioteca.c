/***********************************************************************
 Fecha 4 04 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: funciones fork() y pipe()
   Materia: Sistemas Operativos
   Taller2: Archivo biblioteca.c
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include "biblioteca.h"

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
