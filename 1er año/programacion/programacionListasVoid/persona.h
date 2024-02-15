#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "lista.h"

struct PersonaEstructura{

    char nombre[20];
    float peso;

};


typedef struct PersonaEstructura * Persona;

Persona crearPersona(char  n[20], float p);

void mostrarPersona(Persona p);

void mostrarListaPersona (Lista lista);

#endif // PERSONA_H_INCLUDED
