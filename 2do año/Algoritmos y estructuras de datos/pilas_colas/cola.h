#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

struct Cola; ///SOLO puntero al ultimo

typedef struct Cola * ColaPtr;


NodoPtr getUltimoCola(ColaPtr Cola);
NodoPtr getPrimeroCola(ColaPtr Cola);

void setUltimoCola(ColaPtr Cola, NodoPtr nuevoUltimo);
void setPrimeroCola(ColaPtr Cola, NodoPtr nuevoPrimero);


ColaPtr crearCola();
void encolar(ColaPtr Cola, DatoPtr dato); ///ENCOLAR - ENQUEUE
DatoPtr desencolar(ColaPtr Cola); ///DESENCOLAR - DEQUEUE
ColaPtr duplicarCola(ColaPtr Cola);//tarea
void liberarCola(ColaPtr Cola);


#endif // LISTA_H_INCLUDED
