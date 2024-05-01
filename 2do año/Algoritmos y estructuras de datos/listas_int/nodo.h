#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;

NodoPtr crearNodo(int dato, NodoPtr siguiente);
void mostrarNodo(NodoPtr nodo);
void liberarNodo(NodoPtr nodo);

int getDato(NodoPtr nodo);

NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, int dato);

void setSiguiente(NodoPtr nodo, NodoPtr siguiente);



#endif // NODO_H_INCLUDED
