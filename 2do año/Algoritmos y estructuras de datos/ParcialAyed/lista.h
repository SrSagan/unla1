#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Lista;

typedef struct Lista * ListaPtr;


/// DADAS POR LA MATERIA
ListaPtr crearLista();
void insertarPrimero(ListaPtr lista, DatoPtr dato);
DatoPtr obtenerPrimero(ListaPtr lista);
int obtenerTamanio(ListaPtr lista);

///AGREGAR SOLO LAS NECESARIAS PARA EL EXAMEN

void insertarUltimo(ListaPtr lista, DatoPtr dato);
void mostrarLista(ListaPtr lista, void (*funcion)(DatoPtr));
int buscarPos(ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr));
DatoPtr eliminarPos(ListaPtr lista, int pos);


#endif // LISTA_H_INCLUDED
