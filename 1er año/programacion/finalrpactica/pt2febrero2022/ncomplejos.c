#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ncomplejos.h"

numc crearNComplejo()
{
    numc f = malloc(sizeof(struct NComplejo));

    f->imaginario=0;
    f->real=0;

    return f;
}


float calcularModulo(numc f)
{
    // m = |z| = sqrt(r² + i²)
    float rCuadrado, iCuadrado, raiz;

    rCuadrado = f->real*f->real;
    iCuadrado = f->imaginario*f->imaginario;

    raiz = sqrtf(iCuadrado + rCuadrado);

    return fabs(raiz);

}

float getReal(numc f)
{
    return f->real;
}

float getImaginario(numc f)
{
    return f->imaginario;
}

int setReal(numc f, float val)
{
    if(sizeof(val) == sizeof(float))
    {
        f->real=val;
        return 1;
    }
    else
    {
        return 0;
    }
        
}

int setImaginario(numc f, float val)
{
    if(sizeof(val) == sizeof(float))
    {
        f->imaginario=val;
        return 1;
    }
    else
    {
        return 0;
    }
        
}

void destruirNComplejo(numc f)
{
    free(f);
}