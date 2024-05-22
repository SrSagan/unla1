#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "nodo.h"

struct Cola
{
    NodoPtr primero;
} ///SOLO puntero al primero

NodoPtr getUltimo(ColaPtr Cola)
/*{
    return Cola->ultimo;
}*/

NodoPtr getPrimero(ColaPtr Cola)
{
    return Cola->ultimo;
}

void setUltimo(ColaPtr Cola, NodoPtr nuevoUltimo)
{
    Cola->primero = nuevoUltimo;
}
void setPrimero(ColaPtr Cola, NodoPtr nuevoPrimero);


ColaPtr crearCola();
void insertarUltimo(ColaPtr Cola, DatoPtr dato); ///ENCOLAR - ENQUEUE
DatoPtr eliminarPrimero(ColaPtr Cola); ///DESENCOLAR - DEQUEUE
ColaPtr duplicarCola(ColaPtr Cola);//tarea
void liberarCola(ColaPtr Cola);
