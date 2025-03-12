/**********************************************************
 Fecha 20 02 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
    PROGRAMA PRINCIPAL MULTIPLICACION DE MATRICES
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h"
#include <stdbool.h>

int main() {
    int n, opcion;
    bool aprovado=false;
    printf("=========================================\n");
    printf("||                                     ||\n");
    printf("||       BIENVENIDO AL PROCESO         ||\n");
    printf("||   DE GESTION DE MATRICES CUADRADAS  ||\n");
    printf("||                                     ||\n");
    printf("||         Desarrollado por:           ||\n");
    printf("||     Jeronimo Chaparro Tenorio       ||\n");
    printf("||                                     ||\n");
    printf("=========================================\n");
 
    //Se solicita el tamaño que van a tener las matrices cuadradas
    do{
        printf("Ingrese el tamano de la matriz (debe ser menor o igual a 5): ");
        scanf("%d", &n);
        if(n<=5){
            aprovado=true;
        }else{
            printf("El tamano ingresado es mayor que 5, por favor ingresar un tamano valido\n");
        }
    }while(!aprovado);
    
    //Banderas para saber si estan inicializadas las matrices y se multiplicaron
     bool iniM = false;
     bool multiM = false;

    //Creacion de variables para medir el tiempo de ejecucion
    clock_t inicio;
    double tiempo_usado;
    /*CREACIÓN DE LAS MATRICES*/
    int **mA = (int **)malloc(n * sizeof(int *));
    int **mB = (int **)malloc(n * sizeof(int *));
    int **mC = (int **)calloc(n, sizeof(int *));

    do {
        printf("=================================================================================\n");
        printf("||     Menu de opciones(Escriba el numero de la opcion que desea ejecutar):     ||\n");
        printf("||     1. Inicializar matrices                                                  ||\n");
        printf("||     2. Multiplicar matrices                                                  ||\n");
        printf("||     3. Mostrar matrices                                                      ||\n");
        printf("||     4. Salir                                                                 ||\n");
        printf("||                                                                              ||\n");
        printf("|| Recordatorio: para ejecutar la opcion 2 se debe primero ejecutar la opcion 1 ||\n");
        printf("|| y para ejecutar la opcion 3 se deben ejecutar primero las opciones 1 y 2     ||\n");
        printf("=================================================================================\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                //Inicialización de matrices
                iniMatriz(mA, mB, mC, n);
                printf("Matrices inicializadas correctamente.\n");
                //Se actualiza la bandera iniM
                iniM = true;
                //Esperar a que el usuario decida continuar
                printf("Presione Enter para continuar...\n");
                while (getchar() != '\n'); // Limpiar el búfer
                getchar(); // Esperar la tecla
                break;
            case 2:
                if(!iniM){
                    printf("Primero se deben inicializar las matrices con la opcion 1\n");
                    break;
                }
                //Tomo el tiempo de inicio de la función
                inicio = clock();
                // Multiplicamos las matrices A x B = C
                multiMatrices(mA, mB, mC, n);
                //Tomo cuanto se tarda la función en ejecutarse
                inicio = clock() - inicio;
                //Le asignamos el tiempo que toma ejecutar multiMatrices a tiempo_usado y lo imprimimos
                tiempo_usado = ((double)(inicio)) / CLOCKS_PER_SEC;
                printf("Tiempo de ejecucion de la funcion multiplicar matrices: %.5f segundos\n", tiempo_usado);
                multiM = true;
                //Esperar a que el usuario decida continuar
                printf("Presione Enter para continuar...\n");
                while (getchar() != '\n'); // Limpiar el búfer
                getchar(); // Esperar la tecla
                break;
            case 3:
                if(!iniM){
                    printf("Primero se deben inicializar las matrices con la opcion 1\n");
                    break;
                }
                if(!multiM){
                    printf("Primero se deben multiplicar las matrices con la opcion 2\n");
                    break;
                }
                printf("\nMatriz A\n");
                mostrMatrices(mA, n);
                printf("\nMatriz B\n");
                mostrMatrices(mB, n);
                printf("\nMatriz C\n");
                mostrMatrices(mC, n);
                //Esperar a que el usuario decida continuar
                printf("Presione Enter para continuar...\n");
                while (getchar() != '\n'); // Limpiar el búfer
                getchar(); // Esperar la tecla
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida, intente de nuevo.\n");
        }
    } while (opcion != 4);

    // Liberar memoria
    eliminarMemoria(mA, mB, mC, n);

    return 0;
}
