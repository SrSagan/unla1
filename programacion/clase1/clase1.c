#include <stdio.h>
/*
int main(){

    char nombre[30] = "El santi";

    fflush("stdin");

    return 0;

}*/

//ejercicio 1

int main()
{
    char nombre[20];
    float peso, altura, indMasCorp;
    int edad;

    printf("Ingrese su nombre\n");
    scanf("%s", &nombre);

    printf("Escriba su peso en kg\n");
    scanf("%f", &peso);

    printf("Escriba su altura en metros\n");
    scanf("%f", &altura);

    printf("Escriba su edad\n");
    scanf("%d", &edad);

    indMasCorp = peso/(altura*altura);

    printf("%s, tu masa corporal es %f\n", nombre, indMasCorp);

    if (18 <= edad)
    {
        printf("%f", indMasCorp);
    }
    else
    {
        printf("Nada");
    }
    
    return 0;

}