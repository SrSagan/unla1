#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "nodo.h"


struct Pila; ///SOLO puntero al ultimo

typedef struct Pila * PilaPtr;


NodoPtr getUltimoPila(PilaPtr pila);
void setUltimoPila(PilaPtr pila, NodoPtr nuevoUltimo);


PilaPtr crearPila();
void apilar(PilaPtr pila, DatoPtr dato); ///APILAR - PUSH
DatoPtr desapilar(PilaPtr pila); ///DESAPILAR - POP
PilaPtr duplicarPila(PilaPtr pila);//tarea
void liberarPila(PilaPtr pila);




#endif // LISTA_H_INCLUDED
