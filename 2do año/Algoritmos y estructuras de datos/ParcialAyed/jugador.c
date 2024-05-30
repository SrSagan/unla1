#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"




struct JugadorE{

    int numero;
    char apellido[20];

};

JugadorPtr crearJugador(int num, char ape[20]){
    JugadorPtr jugador = malloc(sizeof(struct JugadorE));

    jugador->numero = num;
    strcpy(jugador->apellido,ape);

    return jugador;
}

void mostrarJugador(JugadorPtr j){

    printf("-----JUGADOR----\n");
    printf("APELLIDO: %s - NUM: %d \n\n", j->apellido, j->numero);

};

int getNumero(JugadorPtr j)
{
    return j->numero;
}

int compararNombre(JugadorPtr j1, char j2)
{
    if(strcmp(j1->apellido, j2) == 0) return 1;
    else return 0;
    //retorno un 1 si son iguales
}