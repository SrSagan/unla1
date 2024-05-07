#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista{

    NodoPtr primero;

};

ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};

void insertarPrimero(ListaPtr lista, void *dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};

void insertarUltimo(ListaPtr lista, void *dato)
{
    NodoPtr a = lista->primero;

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
    }

    NodoPtr nD = crearNodo(dato, NULL);
    setSiguiente(a, nD);
}

void insertarPosicion(ListaPtr lista, void *dato, int posicion)
{
    NodoPtr a = lista->primero;

    if(posicion == 0) insertarPrimero(lista, dato); //si es el primero

    else
    {
        int counter = 0;
        do
        {
            a = getSiguiente(a);
            counter++;

        } while (counter != posicion-1); //busco el anterior a la posicion

        NodoPtr nodoSiguiente = getSiguiente(a);  //tomo el siguente a la posicion

        NodoPtr nodoNuevo = crearNodo(dato, nodoSiguiente); //creo mi nuevo nodo y lo apunto al siguiente
        setSiguiente(a, nodoNuevo); //el nodo anterior lo apunto al nuevo nodo
    }

}


void *obtenerPrimero(ListaPtr lista)
{
    NodoPtr a = lista->primero;
    return getDato(a);
}

void *obtenerUltimo(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
    }

    return getDato(a);
}

int obtenerPosicicon(ListaPtr lista, int posicion)
{
    NodoPtr a = lista->primero;
    if(posicion >= obtenerTamanio(lista))
    {
        return -1;
    }
    int counter=0;
    do
    {
        a = getSiguiente(a);
        counter++;

    }while(counter != posicion);

    return getDato(a);
}

void *eliminarPrimero(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    lista->primero = getSiguiente(a);
    int dato = getDato(a);
    free(a);

    return dato;
}

void *eliminarUltimo(ListaPtr lista)
{
    NodoPtr a = lista->primero; //actual
    NodoPtr f; //final

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
        if(getSiguiente(a) != NULL) f=a;
    }
    setSiguiente(f, NULL); //hago el anterior el nuevo final

    int dato = getDato(a);
    free(a);

    return dato;
}
void *eliminarposicicon(ListaPtr lista, int posicion)
{
    NodoPtr a = lista->primero;

    int counter = 0;

    do
    {
        a = getSiguiente(a);
        counter++;

    } while (counter != posicion-1); //busco el anterior a la posicion

    NodoPtr nodoSiguiente = getSiguiente(a);  //tomo el siguente a la posicion es decir el que queremos eliminar

    setSiguiente(a, getSiguiente(nodoSiguiente)); //al anterior lo apunto al siguente del que queremos eliminar

    int dato = getDato(nodoSiguiente); //tomo el dato del eliminado
    free (nodoSiguiente);

    return dato;
}

int obtenerTamanio(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    int counter = 1;

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
        counter++;
    }
    printf("%d\n", a);

    return counter;
}

ListaPtr duplicarLista(ListaPtr lista)
{
    //la nueva lista no puede utilizar los mismo nodos si no seria inutil
    ListaPtr nL = crearLista();
    NodoPtr a = lista->primero;

    NodoPtr copia = crearNodo(getDato(a), NULL);
    nL->primero = copia;

    a = getSiguiente(a);

    while(a != NULL)
    {
       insertarUltimo(nL, getDato(a));
       a = getSiguiente(a);
    }

    return nL;
}

int buscarElemento(ListaPtr lista, void *datoBuscado)
{
    NodoPtr a = lista->primero;
    int counter=0;
    do
    {
        a = getSiguiente(a);
        counter++;

    }while(getDato(a) != datoBuscado || getSiguiente(a) != NULL);

    if(a == NULL)
    {
        return -1; //no fue encontrado
    }

    return counter;
}


void mostrarLista(ListaPtr lista){

    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodo(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");

};

void liberarLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        actual = getSiguiente(actual);
        free(actual);
    };
}
