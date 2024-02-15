#include <stdio.h>
#include <stdlib.h>

#include "canales.h"
#define TAM 50

int main()
{

    printf("Parcial programacion 11/09/23 TEMA 2 - Santiago Dal Degan - 45421137\n");

    CanalPtr canales[TAM]; //creo una array de canales con un tamaño definido
    cargarVacios(canales, TAM); //cargo todos las posiciones como vacias

    cargarArchivo(canales); //leo el archivo y lo guardo en canales
    mostrarCanales(canales, TAM);
    eliminarMenor(canales, TAM, 5); //elimino todos los canales con un rating menor a 5

    guardarArchivo(canales, TAM); //guardo los canales restantes en un nuevo archivo

    return 0;
}
