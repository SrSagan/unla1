#ifndef GUARANI_H_INCLUDED
#define GUARANI_H_INCLUDED

#include "lista.h"
#include "alumnos.h"

struct Cursada;

typedef struct Cursada * CursadaPtr;

/*
struct Cursada
{
    int legajo;
    char nombre[20];
    ListaPtr inscriptos;
    int cupos;
};
*/

CursadaPtr crearCursada(int legajo, char nombre[20], int cupos);

int getLegajo(CursadaPtr c);
void setLegajo(CursadaPtr c, int l);

char * getNombreCursada(CursadaPtr c);
void setNombreCursada(CursadaPtr c, char n[20]);

ListaPtr getInscriptos(CursadaPtr c);
void setInscriptos(CursadaPtr c, ListaPtr i);

int inscribir(CursadaPtr c, AlumnoPtr a);

#endif // GUARANI_H_INCLUDED