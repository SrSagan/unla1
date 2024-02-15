#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"
#include "estudiante.h"


int main()
{
    printf("--------------------\n");

    MateriaPtr m1 = cargarMateriaTeclado();

    cargarEstudiantesDesdeArchivo(m1);

    mostrarMateria(m1);

    agregarEstudiante(m1->listaEstudiantes, TAM);

    mostrarMateria(m1);

    modificarEstudiante(m1->listaEstudiantes, TAM, 333);
    eliminarEstudiante(m1->listaEstudiantes, TAM, 222);

    guardarDatos(m1);



    return 0;
}