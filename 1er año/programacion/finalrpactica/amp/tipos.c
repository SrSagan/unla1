#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include <math.h>

struct Configuracion
{
    int r1;
    int r2;
    float amp;
};

int valComerciales[] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82}; //tam = 12
Conf inversor(float amp)
{
    //amp = R2/R1
    Conf config = malloc(sizeof(struct Configuracion));
    float amplificacion=0, min=100000;
    float r1, r2;
    
    for(int mulr1 = 100;mulr1<=10000;mulr1=mulr1*10)
    {
        for(int mulr2 = 100;mulr2<=10000;mulr2=mulr2*10)
        {
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<12;j++)
                {
                    if(valComerciales[i] >= valComerciales[j]) //i = r2, j=r1 r2>r1
                    {
                        r1 = (float)(valComerciales[j]*mulr1);
                        r2 = (float)(valComerciales[i]*mulr2);

                        amplificacion = r2/r1;
                        if(fabsf(amplificacion-amp) < min)
                        {
                            //printf("True, min: %.2f, amplificacion: %.2f, diferencia: %.2f, r1: %f, r2: %f \n", min, amplificacion, fabsf(amplificacion-amp), r1, r2);
                            min = fabsf(amplificacion-amp);
                            config->amp = amplificacion;
                            config->r1 = (int)r1;
                            config->r2 = (int)r2;
                            if(min == 0) return config;
                        }
                    }
                }
            }
        }
    }

    return config;
}

Conf noInversor(int amp)
{
    //amp = R2/R1+1
    Conf config = malloc(sizeof(struct Configuracion));
    float amplificacion=0, min=100000;
    float r1, r2;
    
    for(int mulr1 = 100;mulr1<=10000;mulr1=mulr1*10)
    {
        for(int mulr2 = 100;mulr2<=10000;mulr2=mulr2*10)
        {
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<12;j++)
                {
                    if(valComerciales[i] >= valComerciales[j]) //i = r2, j=r1 r2>r1
                    {
                        r1 = (float)(valComerciales[j]*mulr1);
                        r2 = (float)(valComerciales[i]*mulr2);

                        amplificacion = r2/r1+1;
                        if(fabsf(amplificacion-amp) < min)
                        {
                            //printf("True, min: %.2f, amplificacion: %.2f, diferencia: %.2f, r1: %f, r2: %f \n", min, amplificacion, fabsf(amplificacion-amp), r1, r2);
                            min = fabsf(amplificacion-amp);
                            config->amp = amplificacion;
                            config->r1 = (int)r1;
                            config->r2 = (int)r2;
                            if(min == 0) return config;
                        }
                    }
                }
            }
        }
    }

    return config;
}


int getR1(Conf c)
{
    return c->r1;
}

int getR2(Conf c)
{
    return c->r2;
}


float getAmp(Conf c)
{
    return c->amp;
}