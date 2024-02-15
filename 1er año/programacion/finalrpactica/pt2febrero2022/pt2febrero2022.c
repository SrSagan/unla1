#include <stdio.h>
#include <stdlib.h>
#include "ncomplejos.h"

int main()
{
    numc numero = crearNComplejo();

    float real, imaginario;

    printf("Escriba un numero real\n");
    scanf("%f", &real);
    printf("\nEscriba un numero imaginario\n");
    scanf("%f", &imaginario);

    setReal(numero, real);
    setImaginario(numero, imaginario);

    printf("El modulo del numero complejo es: %f\n", calcularModulo(numero));

    return 0;
}