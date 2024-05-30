#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "pila.h"

int main()
{

    ///COLAS - PILAS
    ///COLA: 2 --- 3 ---- 8 ---- 11 (INSERTAR FINAL)
    /// <- 2 COLA: 3----8----11 (ELIMINAR EL PRIMERO)
    ///NO PODEMOS RECORRER LA COLA FOR - WHILE
    ColaPtr cola = crearCola();

    int n1,n2,n3,n4;
    n1=2;
    n2=3;
    n3=8;
    n4=11;

    encolar(cola, &n1);
    encolar(cola, &n2);
    encolar(cola, &n3);
    encolar(cola, &n4);

    ColaPtr nuevaCola = duplicarCola(cola);

    int *numero = (int*) desencolar(cola);
    printf("Numero: %d\n", *numero);

    numero = (int*) desencolar(cola);
    printf("Numero: %d\n", *numero);

    numero = (int*) desencolar(nuevaCola);
    printf("Numero: %d\n", *numero);

    numero = (int*) desencolar(nuevaCola);
    printf("Numero: %d\n", *numero);


    ///PILAS--
    ///PILA: 2---3---4----5----6-----3----1 (INSERTAR FINAL)
    ///<- 1... PILA  2---3---4----5----6-----3(ELIMINAR FINAL)

    PilaPtr pila = crearPila();
    n1=2;
    n2=3;
    n3=4;
    n4=5;
    int n5=6;
    int n6=3;
    int n7=1;

    apilar(pila, &n1);
    apilar(pila, &n2);
    apilar(pila, &n3);
    apilar(pila, &n4);
    apilar(pila, &n5);
    apilar(pila, &n6);
    apilar(pila, &n7);

    PilaPtr nuevaPila = duplicarPila(pila);
    printf("\n\n PILAS:\n\n");

    numero = (int*) desapilar(pila);
    printf("Numero: %d\n", *numero);

    numero = (int*) desapilar(pila);
    printf("Numero: %d\n", *numero);

    numero = (int*) desapilar(nuevaPila);
    printf("Numero: %d\n", *numero);

    numero = (int*) desapilar(nuevaPila);
    printf("Numero: %d\n", *numero);


    liberarCola(cola);
    liberarPila(pila);
    return 0;
}
