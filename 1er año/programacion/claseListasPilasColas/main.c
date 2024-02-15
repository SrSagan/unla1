#include <stdio.h>
#include <stdlib.h>
#include "listasEnC.h"

int main()
{
    printf("------------------ CLASE 11- 10-----------------\n");

    //int obtenerTamanio(ListaEnc lista, int* tam);
    int resultado;
    int recuperado;


    ListaEnc lista1 = crearLista();

    insertarInicio(lista1, 8);
    insertarInicio(lista1, -11);
    insertarFin(lista1, 22);
    insertar(lista1, 101, 1);


    imprimir(lista1);

    obtenerTamanio(lista1, &resultado);
    printf("TAM: %d\n", resultado );

    remover(lista1, &recuperado, 2 );


    imprimir(lista1);

    obtenerTamanio(lista1, &resultado);
    printf("TAM: %d\n", resultado );
    printf("ELIMINADO: %d\n", recuperado );


    obtenerElemento(lista1, &recuperado, 1);
    printf("Obtengo el: %d", recuperado );


    return 0;
}
