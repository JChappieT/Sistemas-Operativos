
/**********************************************************
 Fecha 27 02 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Apuntadores
   Materia: Sistemas Operativos
   Ejercico Evaluativo
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************/
#include <stdio.h>
#include <stdlib.h> //de aqui viene la funcion printf

#define size 10
int main(int argc, char *argv[]){

  if (argc < 6) {
    printf("Error: Se requieren al menos 5 argumentos.\n");
    printf("Uso: %s arg1 arg2 arg3 arg4 arg5\n", argv[0]);
    return 1; // Salir con código de error
  }
  
  int a,b,c;
  
  
  double d, e;
 
  a=atoi(argv[1]); 
  b=atoi(argv[2]);
  c=atoi(argv[3]);
  d=atof(argv[4]);
  e=atof(argv[5]); 

  

  
  int perimetroC= 2*a +2*b;
  int areaC= a*b;
  double areaCirc= 3.1416*c*c;
  double perimCirc= 2*3.1416*c;
  double promedioNDoubles= (d+e)/2;

  printf("El primer y segundo numero ingresado la base y la altura de un rectangulo en cm \n Numeros: %d y %d \n", a, b);
  printf("El perimetro del rectangulo es: %d cm\n", perimetroC);
  printf("El area del rectangulo es: %d cm\n", areaC);

  printf("\nEl tercer numero ingresado es el radio de un circulo en cm \n Radio: %d \n", c);
  printf("El area del circulo es: %f cm\n", areaCirc);
  printf("El perimetro del circulo es: %f cm\n", perimCirc);
  
  printf("\nCon los Ultimos dos numeros double ingresados se calculara un promedio en cm\n Numeros: %f y %f \n", d, e);
  printf("El promedio entre los dos numero es: %f cm\n", promedioNDoubles);

  return 0;

}