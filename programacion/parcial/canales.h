#ifndef CANALES_H_INCLUDED
#define CANALES_H_INCLUDED

struct Canal
{
    int vacio;
    //llenar con lo necesario
    char nombre[50];
    float rating;
    char area[50];
};

typedef struct Canal * CanalPtr;

//carga todo el array vacio
void cargarVacios(CanalPtr e[], int tam);

void mostrarCanales(CanalPtr e[], int tam);

//carga el archivo
void cargarArchivo(CanalPtr e[]);
CanalPtr cargarEstructura(char line[]);

//elimina todos los canales con un rating menor a r
void eliminarMenor(CanalPtr e[], int tam, int r);

//guarda los restantes en el archivo
void guardarArchivo(CanalPtr e[], int tam);

#endif // CANALES_H_INCLUDED
