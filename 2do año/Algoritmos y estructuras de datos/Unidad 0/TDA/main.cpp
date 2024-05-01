#include <iostream>
#include "persona.h"
#include "empleado.h"

using namespace std;

int main()
{
    cout << "Santiago Dal Degan - 45421137\n";
    Persona p = crearPersona("Santiago", "Dal Degan", 45421137, 20);
    Empleado e = crearEmpleado(p, 1124, 530.220, 9);

    mostrarEmpleado(e);

    char * nombre = getNombre(p);

    cout << nombre << "\n";

    setNombre(p, "Nicolas"); //al ser un puntero modificar p, modifica la persona dentro del empleado

    mostrarEmpleado(e);
    return 0;
}
