#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "guarani.h"
#include "alumnos.h"
#include "lista.h"
#include "materias.h"
#include "cola.h"//?

struct Cursada
{
    int legajo;
    char nombre[20];
    ListaPtr inscriptos;
    int cupos;
    ColaPtr espera;
};


CursadaPtr crearCursada(int legajo, char nombre[20], int cupos)
{
    CursadaPtr c = (CursadaPtr) malloc(sizeof(struct Cursada));

    c->legajo = legajo;
    strcpy(c->nombre, nombre);
    c->cupos = cupos;
    c->inscriptos = crearLista();
    c->espera = crearCola();

    return c;
}

int getLegajo(CursadaPtr c)
{
    return c->legajo;
}

void setLegajo(CursadaPtr c, int l)
{
    c->legajo = l;
}

char * getNombreCursada(CursadaPtr c)
{
    return c->nombre;
}

void setNombreCursada(CursadaPtr c, char n[20])
{
    strcpy(c->nombre, n);
}

ListaPtr getInscriptos(CursadaPtr c)
{
    return c->inscriptos;
}

void setInscriptos(CursadaPtr c, ListaPtr i)
{
    c->inscriptos = i;
}

int inscribir(CursadaPtr c, AlumnoPtr a)
{
    if(c->cupos > 0)
    {
        //si aun quedan cupos disponibles
        insertarUltimo(c->inscriptos, a);
        c->cupos--;
        return 1; //se logro inscribirse
    }
    else
    {
        ponerEnCola(c, a);
        return 0; //se puso en la cola
        
    }
}

void mostrarCursada(CursadaPtr c)
{
    printf("%d- %s --------------------------------------\n", c->legajo, c->nombre);
    printf("    Cupos restantes: %d\n", c->cupos);
    printf("    Cantidad de inscriptos: %d\n", obtenerTamanio(c->inscriptos));
    printf("    Cantidad de personas en espera: %d\n\n", tamCola(c->espera));
}

void mostrarInscriptos(CursadaPtr c)
{
    printf("Incriptos a %s:\n", c->nombre);
    mostrarListaGenerica(c->inscriptos, &mostrarAlumno);
}

void ponerEnCola(CursadaPtr c, AlumnoPtr a)
{
    encolar(c->espera, a);
    ordernarCola(c->espera);
}

void mostrarEspera(CursadaPtr c)
{
    printf("En espera a %s:\n", c->nombre);
    mostrarColaGenerica(c->espera, &mostrarAlumno);
}