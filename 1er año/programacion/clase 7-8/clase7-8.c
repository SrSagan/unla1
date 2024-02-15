#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main()
{
    int numero = 5; //variable

    int *puntero = &numero; //se crea un puntero que guarde la posicion de la variable

    *puntero = 11; //se le asigna un valor a la posicion

    printf("%d", numero); //ahora el numero sera 11 ya que fue asignado mediante un puntero

    return 0;
}


struct Persona{
    int dni;
    char nombre[50];
};

int main()
{   
    struct Persona p1;

    p1.dni=5122233;
    strcpy(p1.nombre, "Santi");

    printf("%s ---- %d\n", p1.nombre ,p1.dni);


    struct Persona * puntero;

    puntero = &p1;

    //(*puntero).dni = 12312;
    puntero->dni = 123123;

    printf("%s ---- %d", p1.nombre ,p1.dni);

    free(puntero); // limpia la memoria en la que se guardaba p1
    

    return 0;
}*/

int main()
{
    FILE * archivo = fopen("test.txt", "a");

    fprintf(archivo, "Soy re capo\n B)");

    fclose(archivo);

    return 0;
}