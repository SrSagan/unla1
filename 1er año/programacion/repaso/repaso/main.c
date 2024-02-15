#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "empleados.h"

int main()
{
    EmpleadoPtr Empleados[100];
    cargarVacios(Empleados, 100);
    mainmenu(Empleados, 100);

    return 0;
}
