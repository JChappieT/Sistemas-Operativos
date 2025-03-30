
/***********************************************************************
 Fecha 27 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: segundo laboratorio
   Materia: Sistemas Operativos
   LABORATORIO PARADIGMA PRODUCTOR CONSUMIDOR Archivo Consumidor
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>     // Para open()
#include <sys/types.h> // Para tipos de datos como pid_t
#include <sys/stat.h>  // Para constantes como S_IFIFO
#include <unistd.h>

#define FIFO_FILE "/tmp/fifo_twoway"
/***********************************
 * CLIENTE
 ***********************************/

int main() {
   int fd;
   int end_process;
   int stringlen;
   int read_bytes;
   char readbuf[80]; //Areglo de 80 caracteres max
   char end_str[5];  //Arreglo de 5 caracteres max
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
   fd = open(FIFO_FILE, O_CREAT|O_RDWR);
   strcpy(end_str, "end");
   
   while (1) {
      printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);
      stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0';
      end_process = strcmp(readbuf, end_str);
      
      //printf("end_process is %d\n", end_process);
      if (end_process != 0) {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         readbuf[read_bytes] = '\0';
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      } else {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         close(fd);
         break;
      }
   }
   return 0;
}

