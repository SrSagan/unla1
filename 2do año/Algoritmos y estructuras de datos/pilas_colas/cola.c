#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "nodo.h"

struct Cola
{
    NodoPtr primero;
    NodoPtr ultimo;
}; ///SOLO puntero al primero

NodoPtr getUltimoCola(ColaPtr Cola)
{
    return Cola->ultimo;
}

NodoPtr getPrimeroCola(ColaPtr Cola)
{
    return Cola->primero;
}

void setUltimoCola(ColaPtr Cola, NodoPtr nuevoUltimo)
{
    Cola->ultimo = nuevoUltimo;
}

void setPrimeroCola(ColaPtr Cola, NodoPtr nuevoPrimero)
{
    Cola->primero = nuevoPrimero;
}


ColaPtr crearCola()
{
    ColaPtr cola = malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
}

void encolar(ColaPtr Cola, DatoPtr dato) ///ENCOLAR - ENQUEUE
{
    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    NodoPtr actual = Cola->primero;

    if(actual == NULL)
    {
        Cola->primero = nuevoNodo;
        Cola->ultimo = nuevoNodo;
    }
    else
    {
        actual = Cola->ultimo;

        setSiguiente(actual, nuevoNodo);
    }

    Cola->ultimo = nuevoNodo;
}


DatoPtr desencolar(ColaPtr Cola) ///DESENCOLAR - DEQUEUE
{
    NodoPtr primero = Cola->primero;

    Cola->primero = getSiguiente(Cola->primero);

    DatoPtr dato = getDato(primero);
    liberarNodo(primero);

    return dato;

}
ColaPtr duplicarCola(ColaPtr Cola)//tarea
{
    ColaPtr colaAux = crearCola();
    ColaPtr duplicada = crearCola();
    DatoPtr dato;

    while (Cola->primero != NULL)
    {//eliminamos uno a uno y los vamos copiando a 2 nuevas colas
        dato = desencolar(Cola);
        encolar(colaAux,dato);
        encolar(duplicada,dato);
    }

    Cola->ultimo = NULL;

    while (colaAux->primero != NULL) //transformamos la cola auxiliar en la nuva cola real
    {
        dato = desencolar(colaAux);
        encolar(Cola,dato);
    }

    return duplicada;
}

void liberarCola(ColaPtr Cola)
{

    while (Cola->primero != NULL){

        desencolar(Cola);
    };
}
