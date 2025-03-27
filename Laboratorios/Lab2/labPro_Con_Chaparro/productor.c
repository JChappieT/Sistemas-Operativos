/***********************************************************************
 Fecha 27 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: segundo laboratorio
   Materia: Sistemas Operativos
   LABORATORIO PARADIGMA PRODUCTOR CONSUMIDOR Archivo Productor
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

#define FIFO_FILE "/tmp/fifo_twoway"

int main() {
   int fd;
   char readbuf[80]; //Areglo de 80 caracteres max
   char end[10];     //Areglo de 10 caracteres max
   int to_end;
   int read_bytes;
   
   /*Crea el FIFO_FILE si este no existe */
   mkfifo(FIFO_FILE, S_IFIFO|0640);
   strcpy(end, "end");
   //abre el archivo FIFO_FILE
   fd = open(FIFO_FILE, O_RDWR);
   while(1) {
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      to_end = strcmp(readbuf, end);
      
      if (to_end == 0) {
         close(fd);
         break;
      }
      reverse_string(readbuf);
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
      write(fd, readbuf, strlen(readbuf));
      /*
      sleep - This is to make sure other process reads this, otherwise this
      process would retrieve the message
      */
      sleep(2);
   }
   return 0;
}

