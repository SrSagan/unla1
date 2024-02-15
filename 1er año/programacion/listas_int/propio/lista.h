#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

#define POS_INVALIDA -1

struct Lista{
    NodoPtr primer;
    int size;
};

typedef struct Lista * ListaPtr;

ListaPtr crearLista()
{
    ListaPtr a = (ListaPtr) malloc(sizeof(struct Lista));
    a->primer = NULL;

    return a;
}

void insertarPrimero(ListaPtr lista, int dato)
{
    lista->primer=crearNodo(dato, lista->primer);
}

void insertarUltimo(ListaPtr lista, int dato)
{
    NodoPtr pos = lista->primer;

    if(pos == NULL)
    {
        insertarPrimero(lista, dato);
    }
    else
    {
        for(int i=0;i<lista->size;i++)
        {
            pos = pos->next;
        }

        pos->next = crearNodo(dato, NULL);
    }

}

void insertar(ListaPtr lista, int dato, int pos)
{
    //valores invalidos:
    if(pos<0 || pos>lista->size) return;

    NodoPtr nodo = lista->primer;

    for(int i=0;i<pos;i++)
    {
        nodo = nodo->next;
    }

    NodoPtr nuevo = (dato, nodo->next);
    nodo->next = nuevo;

    //NodoPtr nuevoNodo = crearNodo(dato)
}