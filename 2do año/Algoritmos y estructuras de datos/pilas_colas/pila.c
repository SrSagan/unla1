#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"
#include "pila.h"

struct Pila
{
    NodoPtr ultimo;
}; ///SOLO puntero al primero

NodoPtr getUltimoPila(PilaPtr Pila)
{
    return Pila->ultimo;
}

void setUltimoPila(PilaPtr Pila, NodoPtr nuevoUltimo)
{
    Pila->ultimo = nuevoUltimo;
}

PilaPtr crearPila()
{
    PilaPtr Pila = malloc(sizeof(struct Pila));

    Pila->ultimo = NULL;

    return Pila;
}

void apilar(PilaPtr Pila, DatoPtr dato) ///ENPilaR - ENQUEUE
{
    NodoPtr nuevoNodo = crearNodo(dato, Pila->ultimo);

    if(Pila->ultimo == NULL)
    {
        Pila->ultimo = nuevoNodo;
    }
    else
    {
        Pila->ultimo=nuevoNodo;
    }
    
}


DatoPtr desapilar(PilaPtr Pila) ///DESENPilaR - DEQUEUE
{
    NodoPtr ultimo = Pila->ultimo;
    DatoPtr dato = getDato(ultimo);

    Pila->ultimo = getSiguiente(ultimo);
    liberarNodo(ultimo);

    return dato;

}

PilaPtr duplicarPila(PilaPtr Pila)//tarea
{
    PilaPtr PilaAux = crearPila();
    PilaPtr duplicada = crearPila();
    DatoPtr dato;

    while (Pila->ultimo != NULL)
    {//eliminamos uno a uno y los vamos copiando a una pila aux que quedara INVERTIDA
        dato = desapilar(Pila);
        apilar(PilaAux,dato);

    }

    Pila->ultimo = NULL;

    while (PilaAux->ultimo != NULL) //desinvertimos
    {
        dato = desapilar(PilaAux);
        apilar(duplicada,dato);
        apilar(Pila,dato);
    }

    return duplicada;
}

void liberarPila(PilaPtr Pila)
{

    while (Pila->ultimo != NULL){

        desapilar(Pila);
    };
}
