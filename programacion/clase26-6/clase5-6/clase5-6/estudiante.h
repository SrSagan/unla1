#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

struct Estudiante{

    int legajo;
    char nombre[15];
    float promedio;
    char apellido[15];

};

void mostrarEstudiante(struct Estudiante est);

struct Estudiante cargarEstudianteTeclado();
struct Estudiante cargarEstudiante(int l, float p, char n[15], char a[15]);

///Arreglo de estructuras
void cargarEstudiantes(struct Estudiante e[], int t);
void mostrarEstudiantes(struct Estudiante e[], int t);


///Ordenar los estudiantes
void ordenarEstudiantesLegajo(struct Estudiante e[], int t);
void ordenarEstudiantesApellido(struct Estudiante e[], int t);

///Buscar un estudiante
int buscarEstudiante(struct Estudiante e[], int t, int l );

///Clase nueva Anidar Struct
struct Estudiante cargarEstudianteNulo();
void cargarEstudiantesNulos(struct Estudiante e[], int t);

#endif // ESTUDIANTE_H_INCLUDED
