#!/usr/bin/perl

#**************************************************************
#                       Pontificia Universidad Javeriana
#     Autor: Jeronimo Chaparro
#     Materia: Sistemas Operativos
#     Fichero: Lanzador de procesos por lotes
#         Descripcion: Automatización de ejecuciones para obtención 
#         de 30 resultados de ejecuciones de los benchmarks de 
#         distintos sabores con el proposito de hacer experimentos 
#         de caracter científico (fiabilidad y presición)
#****************************************************************/

$Path = `pwd`;
chomp($Path);



@Nombre_Ejecutable = ("mm_Clasica");

@Size_Matriz = (500, 1000, 2000);

@Num_Hilos = (1);

$Repeticiones = 1;

foreach $Nombre_Ejecutable (@Nombre_Ejecutable) {
    foreach $size (@Size_Matriz) {
        foreach $hilo (@Num_Hilos) {

            #$file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";

            for ($i = 0; $i < $Repeticiones; $i++) {

                #system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");

                printf("$Path/$Nombre_Ejecutable $size $hilo \n");
            }

            #close($file);

            $p = $p + 1;
        }
    }
}