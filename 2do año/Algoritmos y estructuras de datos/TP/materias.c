#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materias.h"

/*
    Materias aprobadas:
    - Promedio
    - Nombre
*/
struct Materia
{
    char nombre[20];
    float promedio;
};

MateriaPtr crearMateria(float promedio, char n[20])
{
    MateriaPtr m = (MateriaPtr) malloc(sizeof(struct Materia));
    m->promedio = promedio;
    strcpy(m->nombre, n);

    return m;
}

char * getNombreMateria(MateriaPtr m)
{
    return m->nombre;
}

void setNombreMateria(MateriaPtr m, char n[20])
{
    strcpy(m->nombre, n);
}

float getPromedioMateria(MateriaPtr m)
{
    return m->promedio;
}

void setPromedioMateria(MateriaPtr m, float p)
{
    m->promedio = p;
}