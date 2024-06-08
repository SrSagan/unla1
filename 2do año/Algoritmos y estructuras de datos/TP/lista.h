#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
#include "cola.h"

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

ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElementoInt(ListaPtr lista, datoPtr datoBuscado);//tarea

//void insertarEnOrden(ListaPtr lista, void dato);//tarea, si la lista est� ordenada cada vez que
//se inserta se inserta en la posici�n que corresponda

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(datoPtr));

void liberarLista(ListaPtr lista);

void ordenarListaBurbuja(ListaPtr lista, int(comparar)(datoPtr, datoPtr));//tarea
void ordenarListaSeleccion(ListaPtr lista, int(comparar)(datoPtr, datoPtr));
void ordenarListaInsercion(ListaPtr lista, int(comparar)(datoPtr, datoPtr));
int busquedaSecuencial(ListaPtr lista, datoPtr datoBuscado);
int busquedaBinaria(ListaPtr lista, datoPtr datoBuscado);

float calcularPromedioListaGenerica(ListaPtr lista, float (getNumero(datoPtr)));

void encolarLista(ListaPtr lista, ColaPtr cola);

#endif // LISTA_H_INCLUDED
