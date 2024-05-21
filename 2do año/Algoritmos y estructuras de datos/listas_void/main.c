#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{

    //------------------------------INT------------------------------//

    ListaPtr lista = crearLista();

    int n1=23, n2=11, n3=21, n4=34, n5=4;

    insertarPrimero(lista, &n1); //4
    insertarPrimero(lista, &n2); //3
    insertarPrimero(lista, &n3); //2
    insertarPrimero(lista, &n4); //1
    insertarPrimero(lista, &n5); //0

    mostrarListaInt(lista);

    insertarUltimo(lista, &n5); //tarea //5

    insertarPosicion(lista, &n1, 3); //tarea //nuevo 3

    mostrarListaInt(lista);

    printf("Ultimo: %d\n\n", (*(int*) obtenerUltimo(lista)));

    printf("3- %d\n\n", (*(int*) obtenerPosicicon(lista, 3)));

    eliminarUltimo(lista); //tarea

    eliminarposicicon(lista, 3); //tarea

    mostrarListaInt(lista);

    printf("Tamanio: %d\n\n", obtenerTamanio(lista)); //tarea

    ListaPtr nL = duplicarLista(lista);//tarea

    printf("Lista duplicada: \n\n");

    mostrarListaInt(nL);

    printf("La pos es: %d \n\n", buscarElementoInt(lista, &n4));//tarea

    mostrarListaInt(lista);

    //------------------------------INT------------------------------//


    return 0;
}
