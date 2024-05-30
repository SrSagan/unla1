#include <stdio.h>
#include <stdlib.h>
#include "estadio.h"
#include "jugador.h"
#include "lista.h"

///Ni bien inicia el examen tienen 1,5hs para entregarlo en .rar o .zip por campus
///EL MAIN NO SE PUEDE MODIFICAR

/// Construir todo el programa bajo TDA
/// Muchas cosas las pueden reutilizar, lo que falte deberan desarrollarlo
/// (solo lo que falte, no agreguen cosas de m�s)

/// 1- El estadio debe tener una lista de jugadores. Insertar los 5 jugadores creados
/// Deberan insertarlos al final de la lista, y solo se permiten insertar jugadores con id impares
//  es decir la lista deberia quedar con 3 jugadores, los otros dos no se deberian poder insertar

/// 2- Mostrar el estadio con los jugadores
/// --- Hasta ac� requisito de aprobacion -----

/// 3- Buscar al jugador "Fernandao" y quitarlo de la lista. volver a mostrar.


int main()
{
    printf("--- PARCIAL: DNI - xxxxxxxxx ESTUDIANTE: nnnAAA -----\n\n");

    //Creo el estadio
    EstadioPtr estadio = crearEstadio(3000,"Vivaracha");

    //Creo jugadores
    JugadorPtr j1 = crearJugador(1,"Messi");
    JugadorPtr j2 = crearJugador(2, "Riquelme");
    JugadorPtr j3 = crearJugador(3, "Di Maria");
    JugadorPtr j4 = crearJugador (4, "Zarate");
    JugadorPtr j5 = crearJugador (5, "Fernandhao");

    ///1 - Insertar los 5 jugadores (al final de la lista)

    insertarUltimo(getJugadores(estadio), j1); //Agregar los parametros que crea necesarios
    insertarUltimo(getJugadores(estadio), j2);
    insertarUltimo(getJugadores(estadio), j3);
    insertarUltimo(getJugadores(estadio), j4);
    insertarUltimo(getJugadores(estadio), j5);

    ///2- Mostrar el estadio. Con los 3 jugadores
    mostrarEstadio(estadio);

    ///3- Remover el jugador
    removerJugador(estadio, "Fernandhao");
    mostrarEstadio(estadio);


    return 0;
}
