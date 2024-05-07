#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{

    ListaPtr lista = crearLista();

    mostrarLista(lista);

    insertarPrimero(lista, 23); //4
    insertarPrimero(lista, 11); //3
    insertarPrimero(lista, 21); //2
    insertarPrimero(lista, 34); //1
    insertarPrimero(lista, 4); //0

    mostrarLista(lista);

    insertarUltimo(lista, 100); //tarea //5

    insertarPosicion(lista, 150, 3); //tarea //nuevo 3

    printf("Ultimo: %d\n\n", obtenerUltimo(lista));

    printf("3- %d\n\n", obtenerPosicicon(lista, 3));

    mostrarLista(lista);

    eliminarUltimo(lista); //tarea

    eliminarposicicon(lista, 3); //tarea

    mostrarLista(lista);

    printf("Tamanio: %d\n\n", obtenerTamanio(lista)); //tarea

    ordenarLista(lista);//tarea

    printf("Lista ordenada: \n");

    mostrarLista(lista);

    ListaPtr nL = duplicarLista(lista);//tarea

    printf("Lista duplicada: \n\n");

    mostrarLista(nL);

    printf("La pos es: %d \n\n", buscarElemento(lista, 34));//tarea

    insertarEnOrden(lista, 1);

    mostrarLista(lista);


    return 0;
}
