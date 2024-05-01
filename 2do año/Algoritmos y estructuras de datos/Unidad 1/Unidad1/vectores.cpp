#include <iostream>
#include <time.h>
#include <math.h>
#include "vectores.h"

void cargarVector(int *v, int tam)
{
    std::cout << "Escriba los valores de su vector presionando Enter entre cada uno\n";

    for(int i=0; i<tam; i++)
    {
        std::cin >> v[i];
    }
}

void cargarVectorAleatorio(int *v, int tam)
{

    for(int i=0; i<tam; i++)
    {
        v[i] = rand()%100;
        //v[i] = rand(); //el %100 lo hace mas sencillo de leer
    }

}

void mostrarVector(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(i%10 == 0 && i != 0) std::cout << "\n";
        std::cout << v[i] << " - ";
    }
}

void mostrarVectorInvertido(int *v, int tam)
{
    for(int i=tam-1; i>=0; i--)
    {
        std::cout << v[i] << " - ";
        if(i%10 == 0) std::cout << "\n";
    }
}

int cantidadPares(int *v, int tam)
{
    int cantidad=0;
    for(int i=0; i<tam; i++)
    {
        if(v[i]%2 == 0) cantidad++;
    }

    return cantidad;
}

int calcularModulo(int *v, int tam)
{
    int a=0;
    for(int i=0; i<tam; i++)
    {
        a += v[i]*v[i];
    }
    a = sqrt(a);

    return a;
}

int buscarMinimo(int *v, int tam)
{
    int min = v[0];
    int pos = 0;
    for(int i=1; i<tam; i++)
    {
        if(min > v[i])
        {
            min = v[i];
            pos = i;
        }
    }

    return pos;
}

int buscarMaximo(int *v, int tam)
{
    int max = v[0];
    int pos = 0;
    for(int i=1; i<tam; i++)
    {
        if(max < v[i])
        {
            max = v[i];
            pos = i;
        }
    }

    return pos;
}

void ordenarArrayBurbuja(int *v, int tam)
{
    int aux=0;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void ordenarArraySeleccion(int *v, int tam)
{
    int aux;
    int min;
    for (int i=0; i<tam; i++)
    {
        min = i;
        for (int j=i+1;j<tam;j++)
        {
            if (v[min] > v[j])
            {
                min = j;
            }
        }
        aux = v[min];
        v[min] = v[i];
        v[i] = aux;
    }
}

void ordenarArrayInsercion(int *v, int tam)
{
    int aux;
    for(int i=1;i<tam;i++)
    {
        aux = v[i];

        int izq = i-1;

        while((v[izq] > aux) && (izq >= 0))
        {
            v[izq+1] = v[izq];
            izq--;
        }
        v[izq+1] = aux;
    }
}

int sumarVectores(int *v1, int t1, int *v2, int t2, int *r)
{
    if(t1 != t2) return -1; //checkeo si se pueden sumar

    for(int i=0; i<t1; i++) //t1 = t2
    {
        r[i] = v1[i] + v2[i];
    }

    return 1;

}

int multiplicacionEscalar(int *v1, int t1, int *v2, int t2)
{
    if(t1 != t2) return -1; //checkeo si se pueden multiplicar

    int out=0;
    for(int i=0; i<t1; i++) //t1 = t2
    {
        out += v1[i]*v2[i];
    }

    return out;
}

int busquedaSecuencial(int *v, int tam, int num)
{
    for(int i=0; i<tam; i++)
    {
        if(v[i] == num) return i;
    }
    return -1;
}

int busquedaBinaria(int *v, int tam, int num)
{
    int sup =0, inf=0, centro=0;

    sup = tam-1;
    while(inf <= sup)
    {
        centro = (sup+inf)/2; // [@] @ @ @ ->@<- @ @ @ (@) segunda vuelta: [@] ->@<- @ (@) | @ @ @ @ @

        if(v[centro] == num) return centro;
        else
        {
            if(num > v[centro]) inf = centro +1;// @ @ @ @ ->@<- [@] @ @ (@) //requiere que este ordenado!!
            else sup = centro-1; // [@] @ @ (@) ->@<- @ @ @ @
        }
    }

    return -1;
}
