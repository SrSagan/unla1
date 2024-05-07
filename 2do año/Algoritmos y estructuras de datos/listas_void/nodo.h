#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;

NodoPtr crearNodo(void *dato, NodoPtr siguiente);
void mostrarNodo(NodoPtr nodo);
void liberarNodo(NodoPtr nodo);

void *getDato(NodoPtr nodo);

NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, void *dato);

void setSiguiente(NodoPtr nodo, NodoPtr siguiente);



#endif // NODO_H_INCLUDED
