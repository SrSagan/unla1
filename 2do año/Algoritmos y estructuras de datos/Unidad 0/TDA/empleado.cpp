#include <iostream>
#include <cstring>
#include "persona.h"
#include "empleado.h"

struct EmpleadoEst{
    Persona p;
    int legajo;
    float sueldo;
    int id_empresa;
};

Empleado crearEmpleado(Persona p, int legajo, float sueldo, int id_empresa)
{
    Empleado e = new struct EmpleadoEst;

    e->p = p;
    e->id_empresa = id_empresa;
    e->legajo = legajo;
    e->sueldo = sueldo;

    return e;
}

void mostrarEmpleado(Empleado e)
{
    std::cout << "||--------EMPLEADO--------||\n";
    std::cout << "||Legajo: " << e->legajo << "\n";
    std::cout << "||Sueldo: " << e->sueldo << "\n";
    std::cout << "||Empresa ID: " << e->id_empresa << "\n";

    mostrarPersona(e->p);
    std::cout << "||--------EMPLEADO--------||\n";
}


void destruirEmpleado(Empleado e)
{
    delete e;
}

//---------------PERSONA---------------//

Persona getPersona(Empleado e)
{
    return e->p;
}
void setPersona(Empleado e, Persona p)
{
    e->p = p;
}

//---------------LEGAJO---------------//

int getLegajo(Empleado e)
{
    return e->legajo;
}
void setLegajo(Empleado e, int legajo)
{
    e->legajo = legajo;
}

//---------------SUELDO---------------//

float getSueldo(Empleado e)
{
    return e->sueldo;
}
void setSueldo(Empleado e, float sueldo)
{
    e->sueldo = sueldo;
}

//---------------EMPRESA---------------//

int getEmpresa(Empleado e)
{
    return e->id_empresa;
}
void setEmpresa(Empleado e, int id_empresa)
{
    e->id_empresa = id_empresa;
}
