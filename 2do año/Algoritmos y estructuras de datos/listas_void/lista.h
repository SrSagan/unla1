#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;

typedef struct Lista * ListaPtr;

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, datoPtr dato);
void insertarUltimo(ListaPtr lista, datoPtr dato); //tarea
void insertarPosicion(ListaPtr lista, datoPtr dato, int posicion); //tarea


datoPtr obtenerPrimero(ListaPtr lista);
datoPtr obtenerUltimo(ListaPtr lista); //tarea
datoPtr obtenerPosicicon(ListaPtr lista, int posicion); //tarea

datoPtr eliminarPrimero(ListaPtr lista);
datoPtr eliminarUltimo(ListaPtr lista); //tarea
datoPtr eliminarposicicon(ListaPtr lista, int posicion); //tarea

int obtenerTamanio(ListaPtr lista); //tarea

//void ordenarLista(ListaPtr lista);//tarea
//ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElementoInt(ListaPtr lista, datoPtr datoBuscado);//tarea

//void insertarEnOrden(ListaPtr lista, void dato);//tarea, si la lista est� ordenada cada vez que
//se inserta se inserta en la posici�n que corresponda

void mostrarListaInt(ListaPtr lista);

void liberarLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
