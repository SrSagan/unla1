#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void imprimirvector(int a[]);
int * burbuja(int * a);
int * seleccion(int * a);
int * insercion(int *a);
int busquedaBinaria(int a[], int val);

int main()
{
    srand(time(0));

    int *vector;
    vector = malloc(TAM * sizeof(int));

    for(int i=0;i<TAM;i++)
    {
        vector[i]= rand()%100;
    }

    int * vectorCopia;

    imprimirvector(vector); //imprimimos el vector desordenado

    vectorCopia = burbuja(vector); //ordenamos el vector y lo ponemos en un vector nuevo

    imprimirvector(vectorCopia); //imprimimos

    vectorCopia = seleccion(vector);

    imprimirvector(vectorCopia);

    printf("%d ", busquedaBinaria(vectorCopia, 5));

    return 0;
}

void imprimirvector(int a[])
{
    for(int i=0;i<TAM;i++)
    {
        printf("%d ", a[i]);
    } 
    printf("\n");
}

int * burbuja(int * a)
{
    int aux;
    for(int i=0;i<TAM-1;i++)
    {
        for(int j=i+1;j<TAM;j++)
        {
            if(a[i] > a[j])
            {
                aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }

        }
    }
    return a;
}

int * seleccion(int * a)
{
    int min, aux;
    for(int i = 0;i<TAM;i++)
    {
        min = i;
        for(int j = i+1; j<TAM;j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        aux = a[min];
        a[min] = a[i];
        a[i] = aux;
    }
    return a;
}

int * insercion(int *a)
{
    int aux;
    for(int i=1;i<TAM;i++)
    {
        aux = a[i];

        int izq = i-1;

        while((a[izq] > aux) && (izq >= 0))
        {
            a[izq+1] = a[izq];
            izq--;
        }
        a[izq+1] = aux;
    }
    return a;
}

int busquedaBinaria(int a[], int val)
{

    int izq = 0;
    int der = TAM-1;

    while(izq <= der)
    {
        int centro = (izq+der)/2;

        int valorMedio = a[centro];

        if(val == valorMedio) return centro;

        if(val < valorMedio) der = centro-1;
        else izq = centro+1;
    }

    return -1;
}