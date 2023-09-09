#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

struct Empleado
{
    char nombre[20];
    int legajo;
    int sueldo;
};

typedef struct Empleado * EmpleadoPtr;

void cargarEmpleadoTeclado(EmpleadoPtr e[], int pos);
void mostrarEmpleados(EmpleadoPtr e[], int tam);
void cargarVacios(EmpleadoPtr Empleados[], int tam);
int checkVacio(EmpleadoPtr e[], int tam);
int eliminarEmpleado(EmpleadoPtr empleados[], int tam, int legajo);
void guardarArchivo(EmpleadoPtr empleados[], int tam);
void cargarArchivo(EmpleadoPtr empleados[]);
EmpleadoPtr cargarEmpleado(char line[]);
int buscarNombre(EmpleadoPtr e[], int tam, char nom[]);

void ordernarNombre(EmpleadoPtr e[], int tam);
void ordenarNumero(EmpleadoPtr e[], int tam);



#endif // EMPLEADOS_H_INCLUDED
