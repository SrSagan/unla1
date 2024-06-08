#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "nodo.h"
#include "lista.h"
#include "alumnos.h"

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

void encolar(ColaPtr Cola, datoPtr dato) ///ENCOLAR - ENQUEUE
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


datoPtr desencolar(ColaPtr Cola) ///DESENCOLAR - DEQUEUE
{
    NodoPtr primero = Cola->primero;

    Cola->primero = getSiguiente(Cola->primero);

    datoPtr dato = getDato(primero);
    liberarNodo(primero);

    return dato;

}
ColaPtr duplicarCola(ColaPtr Cola)//tarea
{
    ColaPtr colaAux = crearCola();
    ColaPtr duplicada = crearCola();
    datoPtr dato;

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

int tamCola(ColaPtr cola)
{
    ColaPtr colaAux = crearCola();
    datoPtr dato;
    int tam =0;
    while (cola->primero != NULL)
    {//eliminamos uno a uno y los vamos copiando a 2 nuevas colas
        dato = desencolar(cola);
        encolar(colaAux,dato);
        tam++;
    }

    cola->ultimo = NULL;

    while (colaAux->primero != NULL) //transformamos la cola auxiliar en la nuva cola real
    {
        dato = desencolar(colaAux);
        encolar(cola,dato);
    }
    return tam;
}

void ordernarCola(ColaPtr cola)
{
    ListaPtr lista = crearLista();

    while (cola->primero != NULL)
    {
        insertarPrimero(lista, desencolar(cola));
    }

    ordenarListaBurbuja(lista, compararPromedio);

    encolarLista(lista, cola);

    //liberarLista(lista);
}

void mostrarColaGenerica(ColaPtr cola, void (*mostrar)(datoPtr))
{
    ColaPtr colaAux = crearCola();
    datoPtr dato;

    while (cola->primero != NULL)
    {//eliminamos uno a uno y los vamos copiando a 2 nuevas colas
        dato = desencolar(cola);
        mostrar(dato);
    }

    cola->ultimo = NULL;

    while (colaAux->primero != NULL) //transformamos la cola auxiliar en la nuva cola real
    {
        dato = desencolar(colaAux);
        encolar(cola,dato);
    }

}