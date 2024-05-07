#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;

typedef struct Lista * ListaPtr;

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, void *dato);
void insertarUltimo(ListaPtr lista, void *dato); //tarea
void insertarPosicion(ListaPtr lista, void *dato, int posicion); //tarea


void obtenerPrimero(ListaPtr lista);
void obtenerUltimo(ListaPtr lista); //tarea
void obtenerPosicicon(ListaPtr lista, int posicion); //tarea

void eliminarPrimero(ListaPtr lista);
void eliminarUltimo(ListaPtr lista); //tarea
void eliminarposicicon(ListaPtr lista, int posicion); //tarea

int obtenerTamanio(ListaPtr lista); //tarea

//void ordenarLista(ListaPtr lista);//tarea
//ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, void *datoBuscado);//tarea

//void insertarEnOrden(ListaPtr lista, void dato);//tarea, si la lista est� ordenada cada vez que
//se inserta se inserta en la posici�n que corresponda


void mostrarLista(ListaPtr lista);

void liberarLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
