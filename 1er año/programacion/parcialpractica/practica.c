#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RENGLONES 7
#define LARGO_ORACION 20


//Declaraciones de las funciones o procedimientos
//PRE: El tama�o que ingresa el usuario debe ser mayor a cero en caso que se use este tama�o
//para un vector o figura
//POST: Se devulve un entero
int elegirTamanio();

//PRE:El tama�o debe ser mayor a cero, y menor a 170, srand(time(0)) y #include <time.h> deben estarn en el main
//POST:Se sobreescribe el vector con numeros aleatorios, entre -70 y 100
void cargarVectorAleatorio(int v[], int tam);

//PRE:El tama�o debe ser mayor a cero
//POST:se muestra por pantalla el vector v
void mostrarVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve la posicion donde esta el valor minimo
int posMin(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve la posicion donde esta el valor maximo
int posMax(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve  el valor minimo
int minVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve el valor maximo
int maxVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve el promedio del vector
float promVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la suma vectorial
void sumaVectores(int v[], int w[], int resultado[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la resta vectorial
void restaVectores(int v[], int w[], int resultado[], int tam);

//PRE: Mini debe ser menor  a maxi... SI o si .. srand(time(0)) y #include <time.h> deben estarn en el main
//POST: Se devuelve un valor aleatroio entre mini y maxi
int aleatorioEntre(int mini, int maxi);

//PRE: mini debe ser menor que maxi y el tama�o mayor a cero.
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi
void cargarVectorConAleatorios(int v[], int tam, int mini,int maxi);

//PRE: mini debe ser menor que maxi y el tama�o mayor a cero. Tam debe ser mayor a maxi - mini
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi, sin repetidos
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoBurbuja(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoSeleccion(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoInsercion(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve la posicion en caso que se encontro el numero, o -1 en caso de no encontrarlo
int busquedaSecuencial(int v[], int tam, int buscar);

//PRE: El tama�o debe ser mayor a cero, el vector v debe estar ordenado.
//POST: Se devuelve la posicion en caso que se encontro el numero, o -1 en caso de no encontrarlo
int busquedaBinaria(int v[], int tam, int buscar);


//Para repasar previo al primer parcial
//PRE: el tama�o debe ser positivo
//POST: Se devuelve uno o menos uno si son iguales o no respectivamente.
int sonIguales(char nombre1[], char nombre2[], int tam);


//Realizar todos los mismos algoritmos pero para arrays de float o incluso de char
//Realizar la funcion que devuelve la moda del vector
//Realizar el procedimiento que carga un nuevo vector con la frecuenca de cada componente del vector inicial
//Realizar la fucion que devuelve el desvio standart (float) del vector.


//PRE: c debe ser un numero positivo.
//POST: Se carga la matriz m
void  cargarMatriz(int m[][RENGLONES],int c );

//PRE: c debe ser un numero positivo.
//POST: Se muestra la matriz m
void  mostrarMatriz(int m[][RENGLONES],int c );

//PRE: c debe ser un numero positivo
//POST: Se realiza la suma pr renglones de los numeros de la matriz
//Cada suma se guarda en el vector v
void  sumarPorRenglones(int m[][RENGLONES], int c, int v[]);

//PRE: c debe ser un numero positivo, mini debe ser menor que maxi.. m
//POST: Se carga la matriz m, con aleatatorios entre mini y maxi
void  cargarMatrizDeAleatorios(int m[][RENGLONES],int c, int mini, int maxi );

//PRE: c debe ser un numero positivo, mini debe ser menor que maxi.. maxi-mini debe ser mayor que c*renglones
//POST: Se carga la matriz m, con aleatatorios entre mini y maxi SIN REPETIR
void  cargarMatrizDeAleatoriosSinRepetir(int m[][RENGLONES],int c, int mini, int maxi );

//PRE: c debe ser un numero positivo
//POST: Se realiza la suma pr columnas de los numeros de la matriz
//Cada suma se guarda en el vector v
void  sumarPorColumnas(int m[][RENGLONES], int c, int v[]);

//PRE: c debe ser un numero positivo
//POST: Se realiza el promedio de cada uno de los  renglones de los numeros de la matriz
//Cada suma se guarda en el vector v
void  promedioPorRenglones(int m[][RENGLONES], int c, float v[]);

//PRE: c debe ser un numero positivo
//POST: Se realiza el promedio de cada uno de los  renglones de los numeros de la matriz
//Cada suma se guarda en el vector v
void  promedioPorColumnas(int m[][RENGLONES], int c, float v[]);

//PRE: c debe ser un numero positivo
//POST:Se suma la matriz m1 con la matriz m2, se guarda el resultado en la matriz resultado
void  sumaDeMatrices(int m1[][RENGLONES], int c, int m2[][RENGLONES], int resultado[][RENGLONES]  );

//PRE: c debe ser un numero positivo
//POST:Se suma la matriz m1 con la matriz m2, se guarda el resultado en la matriz resultado
void  restaDeMatrices(int m1[][RENGLONES], int c, int resultado[][RENGLONES] );

//PRE:RENGLONES es global debe ser mayor que cero
//POST: Se multiplica m1 con m2, y se obtiebe resultado, la matriz debe ser cuadrada
void  multiplicacionDeMatrices(int m1[RENGLONES][RENGLONES],  int m2[RENGLONES][RENGLONES], int resultado[RENGLONES][RENGLONES] );



//PRE: c debe ser mayor a cero, es la cantidad de oraciones que tenemos, las horaciones tiene LARGO_ORCACION caracteres
//busco es la oracion que estoy buscando, tiene tama�o LARGO_ORACION
//POST: se devuelve la posiccion de la oracion, o menos 1 en caso de no encontrarse.
int buscarOracion(char oraciones[][LARGO_ORACION], int c, char busco[]);

int main()
{
    srand(time(0));

    int tam=elegirTamanio();

    return 0;
}

int elegirTamanio()
{
    int tamanio=1;
    while(tamanio>0)
    {
        printf("Elija el tamaño\n");
        scanf("%d", &tamanio);
        if(tamanio < 1)
        {
            printf("El tamaño debe ser mayor a 0\n");
        }
        else return tamanio;
    }
}