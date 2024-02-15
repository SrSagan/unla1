#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

struct Empleado
{
    char nombre[20];
    int legajo;
    int sueldo;
};

typedef struct Empleado * Empleadostr;

