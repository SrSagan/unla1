#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int data;
    struct Nodo * next;
};

typedef struct Nodo * NodoPtr;

NodoPtr crearNodo(int data, NodoPtr next)
{
    NodoPtr a = (NodoPtr) malloc(sizeof(struct Nodo));

    a->data = data;
    a->next = next;

    return a;
}

void liberarNodo(NodoPtr nodo){

    free(nodo);

}