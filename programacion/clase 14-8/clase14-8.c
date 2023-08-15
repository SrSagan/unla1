#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vector;

    vector = crearVector(10);

    return 0;
}

int crearVector(int tam)
{
    int *puntero = malloc(tam * sizeof(int));

    return puntero;
}