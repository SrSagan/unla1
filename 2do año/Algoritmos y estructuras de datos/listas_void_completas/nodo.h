#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;

typedef void * datoPtr;

NodoPtr crearNodo(datoPtr dato, NodoPtr siguiente);
void liberarNodo(NodoPtr nodo);

datoPtr getDato(NodoPtr nodo);

NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, datoPtr dato);

void setSiguiente(NodoPtr nodo, NodoPtr siguiente);



#endif // NODO_H_INCLUDED
