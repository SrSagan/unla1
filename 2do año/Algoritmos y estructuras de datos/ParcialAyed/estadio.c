#include <stdio.h>
#include <stdlib.h>
#include "estadio.h"
#include <string.h>
#include "lista.h"
#include "jugador.h"



struct EstadioE{

    int capacidad;
    char nombre[20];
    ListaPtr jugadores;

};


EstadioPtr crearEstadio(int cap, char nom[20]){
    EstadioPtr estadio = malloc(sizeof(struct EstadioE));

    estadio->capacidad = cap;
    strcpy(estadio->nombre,nom);
    estadio->jugadores = crearLista();


    return estadio;
}

void mostrarEstadio(EstadioPtr e){

    printf("---------ESTADIO---------\n");
    printf("NOMBRE: %s -- CAP: %d\n", e->nombre, e->capacidad);
    printf("\n");

    mostrarLista(e->jugadores, mostrarJugador);

    printf("\n\n");
};

ListaPtr getJugadores(EstadioPtr e)
{
    return e->jugadores;
}

void removerJugador(EstadioPtr e, char j)
{
    //primero buscamos el jugador
    int pos = buscarPos(e->jugadores, j, compararNombre);
    eliminarPos(e->jugadores, pos);
}