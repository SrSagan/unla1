#ifndef ESTADIO_H_INCLUDED
#define ESTADIO_H_INCLUDED
#include "lista.h"
#include "nodo.h"
#include "jugador.h"


struct EstadioE;

typedef struct EstadioE * EstadioPtr;

EstadioPtr crearEstadio(int cap, char nom[20]);



void mostrarEstadio(EstadioPtr e);
void mostrarListaJugadores(ListaPtr l);

ListaPtr getJugadores(EstadioPtr e);

void removerJugador(EstadioPtr e, char j);

#endif // ESTADIO_H_INCLUDED
