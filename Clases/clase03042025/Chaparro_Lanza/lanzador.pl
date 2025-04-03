#!/usr/bin/perl

#**************************************************************
#                       Pontificia Universidad Javeriana
#     
#     Materia: Sistemas Operativos
#     Fichero:
#         Descripcion:
#****************************************************************/

$Path = `pwd`;
chomp($Path);

@Nombre_Ejecutable = ("");

@Size_Matriz = (800 );

@Num_Hilos = (1);

$Repeticiones = 1;

foreach $Nombre_Ejecutable (@Nombre_Ejecutable) {
    foreach $size (@Size_Matriz) {
        foreach $hilo (@Num_Hilos) {

            $file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";

            for ($i = 0; $i < $Repeticiones; $i++) {

                #system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");

                printf("$Path/$Nombre_Ejecutable $size $hilo \n");
            }

            #close($file);

            $p = $p + 1;
        }
    }
}