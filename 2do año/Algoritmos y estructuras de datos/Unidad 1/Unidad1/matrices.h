#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

/*Realizar una librería para poder manipular matrices de enteros.
En esta librería se tiene que tener como mínimo, mostrar la matriz,
cargar la matriz manualmente y aleatoriamente, buscar máximo y mínimo y sus posiciones,
calcular el promedio por filas y columnas, calcular las sumas,  por filas y columnas,
calcular el promedio general, realizar la suma de matrices y
el producto de matrices (con las validaciones necesarias sobre las dimensiones de las mismas).
*/

//tx = tam x
//ty = tam y

int **crearMatriz(int tx, int ty);

void cargarMatriz(int **m, int tx, int ty);

void cargarMatrizAleatorio(int **m, int tx, int ty);

void mostrarMatriz(int **m, int tx, int ty);

void buscarMinimo(int **m, int tx, int ty, int *v); //retorna vector

void buscarMaximo(int **m, int tx, int ty, int *v); //retorna vector

void promedioFilas(int **m, int tx, int ty, int *v); //retorna vector

void promedioColumnas(int **m, int tx, int ty, int *v); //retorna vector

int promedioGeneral(int **m, int tx, int ty); 

void sumaColumnas(int **m, int tx, int ty, int *v); //retorna vector

void sumaFilas(int **m, int tx, int ty, int *v); //retorna vector

int sumaMatrices(int **m1, int tx1, int ty1, int **m2, int tx2, int ty2, int **ms); //retorna matriz ms= matriz salida

int productoMatrices(int **m1, int tx1, int ty1, int **m2, int tx2, int ty2, int **ms); //retorna matriz ms= matriz salida


#endif // MATRICES_H_INCLUDED
