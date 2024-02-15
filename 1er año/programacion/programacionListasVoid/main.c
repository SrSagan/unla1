#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


void mostrarLista (Lista lista) {
    for ( int i = 0; i < obtenerTamanio(lista); ++i) {

        int n = *( (int*) obtenerDato(lista, i) );
		printf("%d ", n);

    }
    printf("\n");
}



int main() {

     //Crea la lista
    printf("------- Creamos Lista de Enteros--------\n");

    //Inicia la lista
    Lista listaInt = crearLista(sizeof(int));


    int n = 5, m = 11, o = 21, r = -11; ///11 5  21 -11
    insertarInicio(listaInt, &n);
    insertarInicio(listaInt, &m);
    insertarFinal(listaInt, &r);
    insertar(listaInt, &o,2);


    mostrarLista(listaInt);


    //Crea la lista
    printf("------- Creamos Lista de Personas--------\n");



    return 0;
}
