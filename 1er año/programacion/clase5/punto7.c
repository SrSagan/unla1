// punto 7
//3 strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[3][20];

    for(int i=0;i<3;i++)
    {
        printf("Escriba el string %d\n", i+1);
        scanf("%s", &str[i]);
    }

    printf("El resultado de concatenar las dos primeras letras de las cadenas es: ");
    for(int i=0;i<3;i++)
    {
        printf("%c", str[i][0]); //no hago un loop porque son unicamente 2 caracteres
        printf("%c", str[i][1]);
    }
    printf("\n");

    int igualdad = strcmp(str[0], str[1]);

    if(!igualdad) printf("El primer y segundo string son iguales: \"%s\"\n", str[0]);
    else printf("El primer y segundo string no son iguales\n");

    return 0;
}