/*//Ejercicio 2: Mostrar todos los números divisibles por 2, por 6 y por 7 que no sean divisibles por 4 y sean menores a 10000.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Los numeros divisibles por 2,6,7 y no divisibles por 4 son:\n");
    for(int i=0;i<10000;i++)
    {
        if(i %2 == 0 && i %6 == 0 && i %7 == 0 && i %4 != 0) printf("%d\n",i);
    }

    return 0;
}

//Ejercicio 4: Pedir que se ingrese un numero por teclado. Calcular el factorial del numero. POSITIVOS
//factorial: 5 = 5*4*3*2*1 = 120

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, resultado=1; //su resultado fuera 0 al multiplicarlo siempre daria 0
    printf("Ingrese un numero para calcular su factorial\n");
    scanf("%d", &numero);

    for(int i=1;i<numero+1;i++)
    {
        resultado=resultado*i;
    }

    printf("El factorial de %d es %d", numero, resultado);

    return 0;
}
*/
//Ejercicio 9: Crear un programa que pida números positivos al usuario, y vaya calculando la suma de todos ellos
//(terminará cuando se teclea un número negativo o cero o cuando la suma supere los 1500).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma=0, numero=1;

    while(suma < 1500 && numero > 0)
    {
        printf("Ingrese un numero positivo entero\n");
        scanf("%d", &numero);
        suma+=numero;
    }

    return 0;
}
