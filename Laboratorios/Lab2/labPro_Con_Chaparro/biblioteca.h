
/***********************************************************************
 Fecha 27 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: segundo laboratorio
   Materia: Sistemas Operativos
   LABORATORIO PARADIGMA PRODUCTOR CONSUMIDOR Archivo biblioteca.h
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#ifndef __BIBLIOTECA_H
#define __BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>     // Para open()
#include <sys/types.h> // Para tipos de datos como pid_t
#include <sys/stat.h>  // Para constantes como S_IFIFO
#include <unistd.h>
//Función para invertir un vector de caracteres
void reverse_string(char *);

#endif