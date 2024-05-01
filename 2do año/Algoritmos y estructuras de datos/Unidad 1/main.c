#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * crearVector(int t);
void cargarVector(int *v, int t);
void mostrarVector(int *v, int t);
void liberarVector(int *v);

///Tarea - vector!!!
/*
- carga por teclado
- carga desde un txt
- hacer las 2 busquedas
- hacer los 3 m�todos de ordenamiento
*/

int** crearMatriz(int r, int c);
void cargarMatriz(int **m, int r, int c);
void mostrarMatriz(int **m, int r, int c);
void liberarMatriz(int **m, int r);

///Tarea - Matriz
/*
- Buscar en una matriz
- Suma y promedio por filas y columnas
- Recuperar desde un txt!!!! >---<
*/

/*Rehacer los ejercicios 2 y 3 de la unidad 0 (librerías de arrays y matrices), 
pero en esta oportunidad utilizando memoria dinámica. 
En el main probar todas las funciones. */

/*2- Generar una librería de funciones para vectores de enteros. 
La misma tiene que permitir, cargar un vector de forma manual, 
cargarlo de forma aleatoria, mostrarlo, mostrarlo en forma invertida, contar la cantidad de pares, 
calcular su módulo (Pitagoras), buscar maximo, buscar mínimo ( y sus posiciones), 
ordenar el array (por burbujeo, selección e inserción), sumar dos vectores, 
realizar la multiplicación escalar de dos vectores, realizar una búsqueda secuencial del vector, 
realizar una búsqueda binaria sobre el vector. ¿Qué ocurre si les pedimos esto mismo para float o doubles?. 

3- Realizar una librería para poder manipular matrices de enteros. 
En esta librería se tiene que tener como mínimo, mostrar la matriz, cargar la matriz manualmente y aleatoriamente, 
buscar máximo y mínimo y sus posiciones, calcular el promedio por filas y columnas, calcular las sumas,
por filas y columnas, calcular el promedio general, 
realizar la suma de matrices y el producto de matrices (con las validaciones necesarias sobre las dimensiones de las mismas). */

int main()
{
    srand(time(0));
    printf("-------- Arreglos dinamicos -------\n");


    int ** matriz  = crearMatriz(4,8);

    cargarMatriz(matriz, 4,8);

    mostrarMatriz(matriz, 4,8);

    liberarMatriz(matriz,4);

    matriz  = crearMatriz(11,3);

    cargarMatriz(matriz, 11,3);

    mostrarMatriz(matriz, 11,3);

    liberarMatriz(matriz,11);

    return 0;
}


int * crearVector(int t){

    int * pVector =(int *) malloc(t * sizeof(int));

    return pVector;

};

void cargarVector(int *v, int t){

    for ( int i = 0 ;i<t; i++){

        v[i] = rand()%10;


    }

}

void mostrarVector(int *v, int t){

    printf("\n");
    for ( int i = 0 ;i<t; i++){

        printf(" %d ", v[i]);


    }

}

void liberarVector(int *v){

    free(v);

};


int** crearMatriz(int r, int c){


    int ** m = (int **) malloc(r * sizeof(int*));

    for ( int i = 0; i< r; i++){

        m[i] = (int*) malloc(c * sizeof(int));

    }

    return m;

};



void cargarMatriz(int **m, int r, int c){

    for ( int i = 0 ; i< r; i++){


        for ( int j = 0; j<c; j++){

            m[i][j] = rand()%10;

        }


    }



};
void mostrarMatriz(int **m, int r, int c){

    printf("\n\n");
    for ( int i = 0 ; i< r; i++){


        for ( int j = 0; j<c; j++){

           printf(" %d ", m[i][j]);

        }
         printf("\n");

    }


};
void liberarMatriz(int **m, int r){


    for ( int i = 0; i<r; i++){

        free(m[i]);

    }

    free(m);


};
