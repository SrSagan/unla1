#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

void startGame(int cantidad)
{
    Player players[cantidad];

    for(int i=0; i<cantidad; i++)
    {
        players[i] = startPlayer(i);
    }

}

Player startPlayer(int pos)
{
    Player e = (Player) malloc(sizeof(struct Player));

    printf("Jugador %d ingrese su alias\n", pos+1);
    scanf("%s", &e->alias);
    printf("Ingrese su DNI\n");
    scanf("%d", &e->dni);

    return e;
}