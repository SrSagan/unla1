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
    a->promedio = calcularPromedio(a);
}

float calcularPromedio(AlumnoPtr a)
{
    return calcularPromedioListaGenerica(a->materiasAprobadas, getPromedioMateriaDatoPtr);
}

void mostrarAlumno(datoPtr b)
{
    AlumnoPtr a = (AlumnoPtr)b;
    printf("%s - %d\n", a->nombre, a->dni);
    printf("    Promedio: %.2f\n", a->promedio);
    printf("    Cantidad de materias aprobadas: %d\n\n", obtenerTamanio(a->materiasAprobadas));
}

int compararPromedio(datoPtr a1, datoPtr a2)
{
    AlumnoPtr al1, al2;
    al1 = (AlumnoPtr)a1;
    al2 = (AlumnoPtr)a2;

    if(obtenerTamanio(al1->materiasAprobadas) != obtenerTamanio(al2->materiasAprobadas)) // si la cantidad de materias aprobadas no es igual
    return obtenerTamanio(al1->materiasAprobadas) < obtenerTamanio(al2->materiasAprobadas);
    //si lo es
    else return al1->promedio < al2->promedio;
}