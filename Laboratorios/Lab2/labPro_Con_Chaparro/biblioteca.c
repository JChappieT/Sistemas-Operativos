/***********************************************************************
 Fecha 27 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: segundo laboratorio
   Materia: Sistemas Operativos
   LABORATORIO PARADIGMA PRODUCTOR CONSUMIDOR Archivo biblioteca.c
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include "biblioteca.h"
void reverse_string(char *str) {
    int last, limit, first;
    char temp;
    last = strlen(str) - 1;
    limit = last/2;
    first = 0;
    
    while (first < last) {
       temp = str[first];
       str[first] = str[last];
       str[last] = temp;
       first++;
       last--;
    }
    return;
 }