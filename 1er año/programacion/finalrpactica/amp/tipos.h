#ifndef INCLUDE_TIPOS_H
#define INCLUDE_TIPOS_H

struct Configuracion;

typedef struct Configuracion * Conf;

Conf inversor(float amp); //r2/r1

Conf noInversor(int amp); //r2/r1+1

int getR1(Conf c);

int getR2(Conf c);

float getAmp(Conf c);


#endif