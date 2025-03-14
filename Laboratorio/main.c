/***********************************************************************
 Fecha 14 03 2025
   Autor: Jeronimo Chaparro Tenorio
   Tema: Programacion modular, Memoria Dinamica
   Materia: Sistemas Operativos
   PROGRAMA PRINCIPAL MULTIPLICACION DE MATRICES Y VECTORES DINAMICOS
   PONTIFICIA UNIVERSIDAD JAVERIANA
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrices.h"
#include "vector.h"
#include <stdbool.h>

int main() {
    int n, opcion;
    bool aprovado=false;
    //Vector
    vectorDinamico editor;
    printf("=========================================\n");
    printf("||                                     ||\n");
    printf("||       BIENVENIDO AL PROCESO         ||\n");
    printf("||   DE GESTION DE MATRICES CUADRADAS  ||\n");
    printf("||        Y VECTORES DINAMICOS         ||\n");
    printf("||                                     ||\n");
    printf("||         Desarrollado por:           ||\n");
    printf("||     Jeronimo Chaparro Tenorio       ||\n");
    printf("||                                     ||\n");
    printf("=========================================\n");
 
    //Se solicita el tamaño que van a tener las matrices cuadradas
    do{
        printf("Ingrese el tamano de la matriz (debe ser menor o igual a 5): \n");
        scanf("%d", &n);
        if(n<=5){
            aprovado=true;
        }else{
            printf("El tamano ingresado es mayor que 5, por favor ingresar un tamano valido\n");
        }
    }while(!aprovado);
    system("cls");
    
    //Banderas para saber si estan inicializadas las matrices y se multiplicaron
     bool iniM = false;
     bool multiM = false;

    //Bandera para saber si se inicializo el vector y para saber si tiene datos
    bool iniV= false;
    bool datV= false;
    // Arreglo de caracteres para ingresar palabras al vector
     char palabra[50];
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
        printf("||     4. Inicializar Vector                                                    ||\n");
        printf("||     5. Agregar palabra al final del vector                                   ||\n");
        printf("||     6. Cambiar la palabra de un espacio especifico del vector                ||\n");
        printf("||     7. Mostrar el vector                                                     ||\n");
        printf("||     8. Salir                                                                 ||\n");
        printf("||                                                                              ||\n");
        printf("|| Recordatorio: Para ejecutar la opcion 2 se debe primero ejecutar la opcion 1 ||\n");
        printf("|| y para ejecutar la opcion 3 se deben ejecutar primero las opciones 1 y 2.    ||\n");
        printf("||                                                                              ||\n");
        printf("|| Recordatorio 2: Para ejecutar la opcion 5 y 6 se debe primero ejecutar la    ||\n");
        printf("|| opcion 4.                                                                    ||\n");
        printf("=================================================================================\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                //Inicialización de matrices
                iniMatriz(mA, mB, mC, n);
                printf("Matrices inicializadas correctamente.\n");
                //Se actualiza la bandera iniM
                iniM = true;
                break;
            case 2:
                system("cls");
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
                system("cls");
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
                system("cls");
                vectorInicio(&editor);
                iniV = true;
                printf("Vector inicializado correctamente.\n");
                break;
            case 5:
                system("cls");
                if(!iniV){
                    printf("Primero se deben inicializar el vector con la opcion 4\n");
                    break;
                }
                printf("Ingrese la palabra que desea ingresar al vector:\n");
                scanf("%49s", &palabra);
                addVector(&editor, palabra);
                printf("El vector queda de la siguiente forma:\n");
                for (int i = 0; i < totalVector(&editor); i++){
                printf("%s", (char *) getVector(&editor, i));
                printf(" ");
                }
                datV=true;
                //Esperar a que el usuario decida continuar
                printf("\nPresione Enter para continuar...\n");
                while (getchar() != '\n'); // Limpiar el búfer
                getchar(); // Esperar la tecla
                //Borramos palabra
                break;
            case 6:
                system("cls");
                if(!iniV){
                    printf("Primero se deben inicializar el vector con la opcion 4\n");
                    break;
                }
                if(!datV){
                    printf("Primero se deben ingresar datos al vector con la opcion 5\n");
                    break;
                }
                int indice;
                printf("Ingrese la palabra que desea ingresar al vector:\n");
                scanf("%49s", &palabra);
                printf("Ingrese el espacio (numero) en el desea ingresar la palabra:\n");
                printf("Recuerde que el vector tiene %d espacios contando el espacio 0\n", totalVector(&editor));
                scanf("%d", &indice);
                setVector(&editor, indice, palabra);
                printf("El vector queda de la siguiente forma:\n");
                for (int i = 0; i < totalVector(&editor); i++){
                printf("%s", (char *) getVector(&editor, i));
                printf(" ");
                }
                datV=true;
                //Esperar a que el usuario decida continuar
                printf("\nPresione Enter para continuar...\n");
                while (getchar() != '\n'); // Limpiar el búfer
                getchar(); // Esperar la tecla
                
                break;
            case 7:
                system("cls");
                if(!iniV){
                    printf("Primero se deben inicializar el vector con la opcion 4\n");
                    break;
                }
                if(!datV){
                    printf("Primero se deben ingresar datos al vector con la opcion 5\n");
                    break;
                }
                printf("El vector esta de la siguiente forma:\n");
                for (int i = 0; i < totalVector(&editor); i++){
                printf("%s", (char *) getVector(&editor, i));
                printf(" ");
                }
                printf("\n");
                //Esperar a que el usuario decida continuar
                printf("\nPresione Enter para continuar...\n");
                while (getchar() != '\n'); // Limpiar el búfer
                getchar(); // Esperar la tecla
                
                break;
            case 8:
                system("cls");
                printf("Saliendo...\n");
                break;
            default:
                system("cls");
                printf("Opcion no valida, intente de nuevo.\n");
        }
    } while (opcion != 8);

    // Liberar memoria
    eliminarMemoria(mA, mB, mC, n);
    freeVector(&editor);

    return 0;
}
