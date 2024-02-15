#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiante.h"
#include "materia.h"

void mostrarMateria(struct Materia m){

    printf("\n------MATERIA-----\n");
    printf("NOMBRE: %s\n", m.nombreMateria );
    printf("CODIGO: %d\n", m.codigo );
    printf("TURNO: %c\n\n", m.turno );
    printf("Docentes: \n");
    printf("Titular: %s\n", m.docente.titular);
    printf("Ayudante 1: %s\n", m.docente.ayudante1);
    printf("Ayudante 2: %s\n", m.docente.ayudante2);
    printf("Ayudante 3: %s\n", m.docente.ayudante3);

    ///Mostrar Estudiantes
    mostrarEstudiantes(m.listaEstudiantes,TAM);


};

struct Materia cargarMateriaTeclado(){

    struct Materia aux;

    printf("\nNombre materia:\n");
    //fflush(stdin);
    gets(aux.nombreMateria);

    printf("\nCodigo materia:\n");
    scanf("%d", &aux.codigo );

    printf("\nTurno materia:\n");
    //fflush(stdin);
    scanf("%c", &aux.turno );

    printf("\nDocente titular:\n");
    gets(aux.docente.titular);
    
    printf("\nDocente ayudande 1:\n");
    gets(aux.docente.ayudante1);

    printf("\nDocente ayudante 2:\n");
    gets(aux.docente.ayudante2);

    printf("\nDocente ayudante 3:\n");
    gets(aux.docente.ayudante3);

    cargarEstudiantesNulos(aux.listaEstudiantes, TAM);


    return aux;

};

void agregarEstudiante(struct Estudiante e[], int t){

   int posVacia = -1;

   struct Estudiante eAgregar = cargarEstudianteTeclado();

   //Busco pos
   posVacia = buscarEstudiante(e, TAM, -1);

   if (posVacia != -1){
        e[posVacia]  = eAgregar;
   }
   else{

    printf("\nNo hay cupo!!!\n");
   }



}


