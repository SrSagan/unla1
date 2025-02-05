#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo{

    void *dato;
    struct Nodo * siguiente;

};


NodoPtr crearNodo(datoPtr dato, NodoPtr siguiente){


    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

void liberarNodo(NodoPtr nodo)
{
    free(nodo);
};

datoPtr getDato(NodoPtr nodo)
{
    return nodo->dato;
}

NodoPtr getSiguiente(NodoPtr nodo)
{
    return nodo->siguiente;
}

void setDato(NodoPtr nodo, datoPtr dato)
{
    nodo->dato = dato;
}

void setSiguiente(NodoPtr nodo, NodoPtr siguiente)
{
    nodo->siguiente=siguiente;
}
