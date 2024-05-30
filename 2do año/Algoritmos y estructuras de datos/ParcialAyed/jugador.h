#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

struct JugadorE;

typedef struct JugadorE * JugadorPtr;

JugadorPtr crearJugador(int num, char ape[20]);

void mostrarJugador(JugadorPtr j);
int getNumero(JugadorPtr j);
int compararNombre(JugadorPtr j1, char j2);


#endif // JUGADOR_H_INCLUDED
