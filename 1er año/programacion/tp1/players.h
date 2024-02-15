#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

//SANTIAGO DAL DEGAN

//lectura y escritura de jugadores en archivos
//agregar player, ordenarlo en la lista, guardarlo en archivo

//-----------------------structs-----------------------//
struct Player;

typedef struct Player * PlayerStr;

PlayerStr startPlayer(int pos);
PlayerStr startEmpty();
void iniciarJugadores(PlayerStr e[], int tam);

//-----------------------structs-----------------------//

//-----------------------SET-----------------------//

PlayerStr setAlias(PlayerStr e, char alias[]);
PlayerStr setDni(PlayerStr e, int dni);
PlayerStr setPuntos(PlayerStr e, int puntos);
PlayerStr setRespuestas(PlayerStr e, int respuestas);

//-----------------------SET-----------------------//

//-----------------------GET-----------------------//

char * getAlias(PlayerStr e);
int getDni(PlayerStr e);
int getPuntos(PlayerStr e);
int getRespuestas(PlayerStr e);

//-----------------------GET-----------------------//

//-----------------------FILES-----------------------//
int getSize();

void guardarPuntuacion(PlayerStr e[], int tamJ);
void cargarPuntuacion(PlayerStr e[]);
PlayerStr cargarJugador(char line[]);

void mostrarHighScores();

//-----------------------FILES-----------------------//

#endif // PLAYERS_H_INCLUDED
