#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"
#include "estudiante.h"


int main()
{
    printf("--------------------\n");

    struct Materia m1 = cargarMateriaTeclado();

    agregarEstudiante(m1.listaEstudiantes, TAM );

    agregarEstudiante(m1.listaEstudiantes, TAM );

    mostrarMateria(m1);



    return 0;
}


