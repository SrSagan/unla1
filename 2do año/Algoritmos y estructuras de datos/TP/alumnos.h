#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

#include "lista.h"
#include "materias.h"

struct Alumno;
typedef struct Alumno * AlumnoPtr;

AlumnoPtr crearAlumno(int dni, char n[20]);

int getDni(AlumnoPtr a);
void setDni(AlumnoPtr a, int dni);

char * getNombreAlumno(AlumnoPtr a);
void setNombreAlumno(AlumnoPtr a, char n[20]);

float getPromedioAlumno(AlumnoPtr a);
void setPromedioAlumno(AlumnoPtr a, float p);

ListaPtr getMateriasAprobadas(AlumnoPtr a);
void setMateriasAprobadas(AlumnoPtr a, ListaPtr ma);

void agregarMateriaAprobada(AlumnoPtr a, MateriaPtr m);

void calcularPromedio(AlumnoPtr a);

#endif // ALUMNOS_H_INCLUDED
