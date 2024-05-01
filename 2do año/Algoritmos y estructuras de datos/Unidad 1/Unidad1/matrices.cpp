#include <iostream>
#include <time.h>
#include <math.h>
#include "matrices.h"

/* Mapa matriz:
   ^y
   | @ @ @ @
   | @ @ @ @
   | @ @ @ @
   | @ @ @ @
   |------->x
*/

int **crearMatriz(int tx, int ty)
{
    int ** m = (int **) malloc(tx * sizeof(int*));

    for ( int i = 0; i< tx; i++){

        m[i] = (int*) malloc(ty * sizeof(int));

    }

    return m;
}

void cargarMatriz(int **m, int tx, int ty)
{
    std::cout << "Escriba su matriz\n";

    for(int x=0; x<tx; x++)
    {
        std::cout << "Escriba la proxima columna\n";
        for(int y=0; y<ty; y++)
        {
            std::cin >> m[x][y];
        }
    }
}

void cargarMatrizAleatorio(int **m, int tx, int ty)
{
    for(int x=0; x<tx; x++)
    {
        for(int y=0; y<ty; y++)
        {
            m[x][y] = rand()%100;
        }
    }
}

void mostrarMatriz(int **m, int tx, int ty)
{
    for(int x=0; x<tx; x++)
    {
        for(int y=0; y<ty; y++)
        {
            std::cout << m[y][x] << " ";
        }
        std::cout << "\n";
    }
}

void buscarMinimo(int **m, int tx, int ty, int *v) //retorna vector
{
    int min = m[0][0];
    v[0] = 0;
    v[1] = 0;

    for(int x=0; x<tx; x++)
    {
        for(int y=0; y<ty; y++)
        {
            if(m[x][y] < min)
            {
                min = m[x][y];
                v[0] = x;
                v[1] = y;
            }
        }
    }
}

void buscarMaximo(int **m, int tx, int ty, int *v) //retorna vector
{
    int max = m[0][0];
    v[0] = 0;
    v[1] = 0;

    for(int x=0; x<tx; x++)
    {
        for(int y=0; y<ty; y++)
        {
            if(m[x][y] > max)
            {
                max = m[x][y];
                v[0] = x;
                v[1] = y;
            }
        }
    }
}

void promedioFilas(int **m, int tx, int ty, int *v) //retorna vector
{
    for(int y=0; y<ty; y++)
    {
        v[y] = 0;
        for(int x=0; x<tx; x++)
        {
            v[y] += m[x][y];
        }
        v[y] = v[y]/tx;
    }
}

void promedioColumnas(int **m, int tx, int ty, int *v) //retorna vector
{
    for(int x=0; x<tx; x++)
    {
        v[x] = 0;
        for(int y=0; y<ty; y++)
        {
            v[x] += m[x][y];
        }
        v[x] = v[x]/ty;
    }
}

int promedioGeneral(int **m, int tx, int ty)
{
    int prom =0;
    for(int x=0; x<tx; x++)
    {
        for(int y=0; y<ty; y++)
        {
           prom += m[x][y];
        }
    }
    prom = prom/(tx*ty);

    return prom;
}

void sumaColumnas(int **m, int tx, int ty, int *v) //retorna vector
{
    for(int x=0; x<tx; x++)
    {
        v[x] = 0;
        for(int y=0; y<ty; y++)
        {
            v[x] += m[x][y];
        }
    }
}

void sumaFilas(int **m, int tx, int ty, int *v) //retorna vector
{
    for(int y=0; y<ty; y++)
    {
        v[y] = 0;
        for(int x=0; x<tx; x++)
        {
            v[y] += m[x][y];
        }
    }
}

int sumaMatrices(int **m1, int tx1, int ty1, int **m2, int tx2, int ty2, int **ms) //retorna matriz ms= matriz salida
{
    if(tx1 != tx2 || ty1 != ty2) return -1;

    for(int x=0; x<tx1; x++)
    {
        for(int y=0; y<ty1; y++)
        {
            ms[x][y] = m1[x][y] + m2[x][y];
        }
    }
    return 1;
}

int productoMatrices(int **m1, int tx1, int ty1, int **m2, int tx2, int ty2, int **ms) //retorna matriz ms= matriz salida
{
    if(tx1 != tx2 || ty1 != ty2) return -1;

    for(int x=0; x<tx1; x++)
    {
        for(int y=0; y<ty1; y++)
        {
            ms[x][y] = m1[x][y] * m2[x][y];
        }
    }
    return 1;
}
