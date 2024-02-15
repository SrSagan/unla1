#ifndef NCOMPLEJOS_H_INCLUDED
#define NCOMPLEJOS_H_INCLUDED

struct NComplejo
{
    float real;
    float imaginario;
};

typedef struct NComplejo * numc;

numc crearNComplejo();

//PRE: Tener un valor en real e imaginario y el numero complejo debe existir
//POST: retorna un float con el modulo del numero complejo 
// m = |z| = sqrt(r² + i²)
float calcularModulo(numc f);

//PRE: El numero complejo debe existir
//POST: retorna el flotante del numero real
float getReal(numc f);

//PRE: El numero complejo debe existir
//POST: retorna el flotante del numero imaginario
float getImaginario(numc f);

//PRE: El numero complejo debe existir
//POST: retorna 1 si la operacion de setear el real fue exitosa
int setReal(numc f, float val);

//PRE: El numero complejo debe existir
//POST: retorna 1 si la operacion de setear el imaginario fue exitosa
int setImaginario(numc f, float val);

//PRE: El numero complejo debe existir
//POST: Liberia la memoria que ocupaba del numero complejo
void destruirNComplejo(numc f);


#endif