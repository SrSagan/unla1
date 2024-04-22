#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

void imprimirConfig(Conf c);

int main()
{
    while(1)
    {

        printf("---------MENU---------\n");
        printf("1) Inversor\n");
        printf("2) No inversor\n");
        printf("3) Salir\n");
        printf("---------MENU---------\n");


        int opcion;
        scanf("%d", &opcion);
        float amp;
        Conf config;
        switch (opcion)
        {
        case 1:

            printf("Escriba la amplificacion\n");

            scanf("%f", &amp);

            config = inversor(amp);
            imprimirConfig(config);
            break;

        case 2:

            printf("Escriba la amplificacion\n");

            scanf("%f", &amp);

            config = noInversor(amp);
            imprimirConfig(config);
            break;
        
        case 3:
            return 0;
            break;

        default:
            printf("Valor invalido\n");
            break;
        }
    }

    return 0;
}

void imprimirConfig(Conf c)
{
    printf("--------------------------------------\n");
    printf("Amplificacion=%.2f\n", getAmp(c));
    printf("R1=%.1fk\n", (float)getR1(c)/1000);
    printf("R2=%.1fk\n", (float)getR2(c)/1000);
    printf("--------------------------------------\n");
}