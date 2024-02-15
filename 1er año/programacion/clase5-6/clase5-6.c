#include <stdio.h>
#include <stdlib.h>
#include "autos.h"

void generarAutos(int cantidad);

int main()
{

    return 0;
}

void generarAutos(int cantidad)
{
    struct Auto autos[cantidad];
       
    for(int i=0;i<cantidad;i++)
    {
        if(i>2)
        {
            autos[i]=cargarAutoTeclado();
        }
        else
        {
            autos[i]=cargarAutoRandom();
        }
    }
}