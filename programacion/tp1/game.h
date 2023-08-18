#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

struct Player{

    char alias[20];
    int dni;
    int puntos;

};

typedef struct Player * Player;

void startGame(int cantidad);
Player startPlayer(int pos);

#endif