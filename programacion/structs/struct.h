#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct Estructura
{
    int vacio;
    //llenar con lo necesario
};

typedef struct Estructura * EstructuraPtr;

//carga todo el array vacio
void cargarVacios(EstructuraPtr e[], int tam);

int checkVacio(EstructuraPtr e[], int tam);
//retorna la una posicion vacia de la array
//si no hay posicion vacia retorna -1

int buscarChar(EstructuraPtr e[], int tam, char word[]);
//retorna -1 si no encontro nada o la posicion si lo encotro

void ordernarChar(EstructuraPtr e[], int tam);

void ordenarNumero(EstructuraPtr e[], int tam);

void guardarArchivo(EstructuraPtr e[], int tam);
void cargarArchivo(EstructuraPtr e[]);
EstructuraPtr cargarEstructura(char line[]);

int eliminarEstructura(EstructuraPtr e[], int tam, int id);
//si la es borrada exitosamente retorna 1, si hay error retorna -1

void mostrarEstructuras(EstructuraPtr e[], int tam);

#endif