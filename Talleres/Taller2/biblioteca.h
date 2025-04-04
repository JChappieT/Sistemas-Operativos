/***********************************************************************
 Fecha 4 04 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: funciones fork() y pipe()
   Materia: Sistemas Operativos
   Taller2: Archivo biblioteca.h
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#ifndef __BIBLIOTECA_H
#define __BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//Función para leer un archivo y almacenar los números en un arreglo
void leer_archivo(const char *nombre, int *arr, int n);
//Función para calcular la suma de los elementos de un arreglo
int calcular_suma(int *arr, int n);

#endif
