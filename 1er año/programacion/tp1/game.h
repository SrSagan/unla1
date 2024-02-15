#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "players.h"

//SANTIAGO DAL DEGAN

struct Pregunta;

typedef struct Pregunta * PreguntaStr;

//carga
//-------------------------------------------------------------------

void cargarArchivo(PreguntaStr e[]);

PreguntaStr cargarEstructura(char line[]);

void cargarVacios(PreguntaStr e[], int tam);

//-------------------------------------------------------------------

//gameplay
//-------------------------------------------------------------------

void startGame(int cantidad);

void mainGame(PreguntaStr p[], int tamPr, PlayerStr j[], int tamJ);

PlayerStr quiz(PlayerStr e, int cantidad, PreguntaStr p[]);

PlayerStr desempate(PlayerStr j[], int empatados[], int counter);

void ordenarPuntuacion(PlayerStr e[], int tamJ);

void mostrarPuntuacion(PlayerStr e[], int tamJ);

void printSpaces(int len, int maxlen);

//-------------------------------------------------------------------

//tiempo
//-------------------------------------------------------------------

void countDown(int seconds, int print);

double startTimer();

int finishTimer(double seconds, int target);

//-------------------------------------------------------------------


#endif
