#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

#define TAM 200

#include "estudiante.h" ///Nuevo  26-6

struct Docente{

    char titular[20];
    char ayudante1[20];
    char ayudante2[20];
    char ayudante3[20];

};

struct Materia{

    char nombreMateria[20];
    int codigo;
    char turno;
    struct Docente docente;

    ///Muchos estudiantes!!!!
    struct Estudiante listaEstudiantes[TAM];


};

void mostrarMateria(struct Materia m);

struct Materia cargarMateriaTeclado();


void agregarEstudiante(struct Estudiante e[], int t);



#endif // MATERIA_H_INCLUDED
