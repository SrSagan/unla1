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
};


CursadaPtr crearCursada(int legajo, char nombre[20], int cupos)
{
    CursadaPtr c = (CursadaPtr) malloc(sizeof(struct Cursada));

    c->legajo = legajo;
    strcpy(c->nombre, nombre);
    c->cupos = cupos;

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

void inscribir(CursadaPtr c, AlumnoPtr a);