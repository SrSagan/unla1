#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "guarani.h"

/*
Realizar un programa que simule las principales funciones del sistema Guarani. 
El sistema debe tener una lista de materias, las materias una lista de inscriptos, y cada inscripto debe tener una lista de materias aprobadas con su promedio. 

Cada materia tiene un cupo, en caso de que se anoten más estudiantes que el cupo se debe generar una cola, 
para generar la cola se evaluará como prioridad primero la cantidad de materias aprobadas y luego el promedio del estudiante. 
*/

//notas:
/*
Estructuras:
    - Materias inscripcion, dentro tieene:
        - Inscriptos (o estudiantes), dentro tiene:
            - Materias aprobadas

    Materias inscripcion:
    - Inscriptos
    - cupos
    - cola de estudiantes

    Inscriptos:
    - Materias aprobadas
    - Promedio

    Materias aprobadas:
    - Promedio
    - Nombre
    
Librerias:
    - Listas
    - Colas
    - guarani //guarani contiene las materias a inscribirse //se llamaran cursada
    - alumnos
    - materias
*/

int main()
{
    ListaPtr guarani = crearLista(); //creamos una lista de cursadas

    CursadaPtr c1 = crearCursada(1, "Programacion", 100);
    CursadaPtr c2 = crearCursada(2, "Matematica", 30);
    CursadaPtr c3 = crearCursada(3, "Algoritmos", 50);

    insertarUltimo(guarani, c1);
    insertarUltimo(guarani, c2);
    insertarUltimo(guarani, c3); //las 3 cursadas se insertan en el sistema guarani

    AlumnoPtr a1 = crearAlumno(45421137, "Santiago");
    AlumnoPtr a2 = crearAlumno(12258996, "Martin");
    AlumnoPtr a3 = crearAlumno(44444444, "Tomas");


    return 0;
}
