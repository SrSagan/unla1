#include <iostream>
#include <cstring>
#include "persona.h"

struct PersonaEst{
    char nombre[20];
    char apellido[20];
    int dni;
    int edad;
};

Persona crearPersona(char nombre[], char apellido[], int dni, int edad)
{
    Persona p = new struct PersonaEst;

    strcpy(p->nombre, nombre);
    strcpy(p->apellido, apellido);

    p->dni = dni;
    p->edad = edad;

    return p;
}

void mostrarPersona(Persona p)
{
    std::cout << "||--------PERSONA--------||\n";
    std::cout << "||Nombre: " << p->nombre << "\n";
    std::cout << "||Apellido: " << p->apellido << "\n";
    std::cout << "||DNI: " << p->dni << "\n";
    std::cout << "||Edad: " << p->edad << "\n";
    std::cout << "||--------PERSONA--------||\n";
}

void destruirPersona(Persona p)
{
    delete p;
}

//---------------EDAD---------------//

int getEdad(Persona p)
{
    return p->edad;
}
void setEdad(Persona p, int edad)
{
    p->edad = edad;
}

//---------------DNI---------------//

int getDni(Persona p)
{
    return p->dni;
}
void setDni(Persona p, int dni)
{
    p->dni = dni;
}

//---------------NOMBRE---------------//

char * getNombre(Persona p)
{
    return p->nombre;
}
void setNombre(Persona p, char nombre[])
{
    strcpy(p->nombre, nombre);
}

//---------------APELLIDO---------------//

char * getApellido(Persona p)
{
    return p->apellido;
}
void setApellido(Persona p, char apellido[])
{
    strcpy(p->apellido, apellido);
}
