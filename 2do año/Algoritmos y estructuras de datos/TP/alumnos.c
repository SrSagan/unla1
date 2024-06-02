#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include "lista.h"
#include "materias.h"


//Inscriptos:
//   - Materias aprobadas
//    - Promedio

struct Alumno
{
    int dni;
    char nombre[20];
    float promedio;
    ListaPtr materiasAprobadas;
};

AlumnoPtr crearAlumno(int dni, char n[20])
{
    AlumnoPtr a = (AlumnoPtr) malloc(sizeof(struct Alumno));
    a->dni = dni;
    strcpy(a->nombre, n);
    a->promedio = 0;
    a->materiasAprobadas = crearLista();

    return a;
}

int getDni(AlumnoPtr a)
{
    return a->dni;
}

void setDni(AlumnoPtr a, int dni)
{
    a->dni = dni;
}

char * getNombreAlumno(AlumnoPtr a)
{
    return a->nombre;
}

void setNombreAlumno(AlumnoPtr a, char n[20])
{
    strcpy(a->nombre, n);
}

float getPromedioAlumno(AlumnoPtr a)
{
    return a->promedio;
}

void setPromedioAlumno(AlumnoPtr a, float p)
{
    a->promedio = p;
}

ListaPtr getMateriasAprobadas(AlumnoPtr a)
{
    return a->materiasAprobadas;
}

void setMateriasAprobadas(AlumnoPtr a, ListaPtr ma)
{
    a->materiasAprobadas = ma;
}

void agregarMateriaAprobada(AlumnoPtr a, MateriaPtr m)
{
    insertarUltimo(a->materiasAprobadas, m);
}

void calcularPromedio(AlumnoPtr a);