#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "nodo.h"
#include "jugador.h"

struct Lista{

    NodoPtr primero;
};


ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};


void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;

};




DatoPtr obtenerPrimero(ListaPtr lista){
    return lista->primero;
}

int obtenerTamanio(ListaPtr lista){

    int tam = 0 ;
    NodoPtr actual = lista->primero;
    while (actual != NULL){

            tam = tam + 1;
            actual = getSiguiente(actual);

    }

    return tam;
};

///AGREGAR SOLO LAS NECESARIAS PARA EL EXAMEN


void insertarUltimo(ListaPtr lista, DatoPtr dato)
{
    //primero checkeamos que su id sea par
    int numero = getNumero((JugadorPtr)dato);
    
    if(numero%2 == 0) return;

    NodoPtr actual = lista->primero;
    NodoPtr nuevo = crearNodo(dato, NULL);

    if(lista->primero == NULL)
    {
        lista->primero = nuevo;
        return;
    }

    while(getSiguiente(actual) != NULL)
    {
        actual = getSiguiente(actual);
    }

    setSiguiente(actual, nuevo);

}

void mostrarLista(ListaPtr lista, void (*mostrar)(DatoPtr))
{
    NodoPtr actual = lista->primero;

    while(actual != NULL)
    {
        mostrar((JugadorPtr)getDato(actual));
        actual = getSiguiente(actual);
    }
}

int buscarPos(ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr))
{
    NodoPtr actual = lista->primero;
    if(comparar(getDato(actual), dato)) return 0; //retorna la pos 0
    int pos = 0;
    do
    {
        actual = getSiguiente(actual);
        pos++;

    }while(!comparar(getDato(actual), dato) && actual != NULL);

    return pos;

}

DatoPtr eliminarPos(ListaPtr lista, int pos)
{
    NodoPtr actual = lista->primero;
    int posactual = -1;

    while(posactual != pos)
    {
        actual = getSiguiente(actual);
        posactual++;
    }

    //en actual me paro en el anterior a ser eliminado
    NodoPtr siguiente = getSiguiente(actual); //nodo a eliminar
    setSiguiente(actual, getSiguiente(siguiente)); //nos salteamos el nodo en la lista

    DatoPtr dato = getDato(siguiente); //scamos el dato
    liberarNodo(siguiente);

    return dato;
    
}