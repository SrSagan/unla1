#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "persona.h"


struct EmpleadoEst;

typedef struct EmpleadoEst * Empleado;

Empleado crearEmpleado(Persona p, int legajo, float sueldo, int id_empresa);
void mostrarEmpleado(Empleado e);
void destruirEmpleado(Empleado e);

//---------------PERSONA---------------//

Persona getPersona(Empleado e);
void setPersona(Empleado e, Persona p);

//---------------LEGAJO---------------//

int getLegajo(Empleado e);
void setLegajo(Empleado e, int legajo);

//---------------SUELDO---------------//

float getSueldo(Empleado e);
void setSueldo(Empleado e, float sueldo);

//---------------EMPRESA---------------//

int getEmpresa(Empleado e);
void setEmpresa(Empleado e, int id_empresa);


#endif // EMPLEADO_H_INCLUDED
