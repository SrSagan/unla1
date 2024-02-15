#include <stdio.h>
#include <stdlib.h>

//Ejercicio 4: Pedir que se ingrese un numero por teclado. Calcular el factorial del numero. POSITIVOS
//factorial: 5 = 5*4*3*2*1 = 120

int ejercicio4()
{
    int numero, resultado=1;
    printf("Ingrese un numero para calcular su factorial\n");
    scanf("%d", &numero);

    for(int i=1;i<numero+1;i++)
    {
        resultado=resultado*i;
    }

    printf("El factorial de %d es %d", numero, resultado);

    return 0;
}
