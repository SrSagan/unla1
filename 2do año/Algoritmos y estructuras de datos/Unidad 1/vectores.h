#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

/*2- Generar una librería de funciones para vectores de enteros. 
La misma tiene que permitir, cargar un vector de forma manual, 
cargarlo de forma aleatoria, mostrarlo, mostrarlo en forma invertida, contar la cantidad de pares, 
calcular su módulo (Pitagoras), buscar maximo, buscar mínimo ( y sus posiciones), 
ordenar el array (por burbujeo, selección e inserción), sumar dos vectores, 
realizar la multiplicación escalar de dos vectores, realizar una búsqueda secuencial del vector, 
realizar una búsqueda binaria sobre el vector. ¿Qué ocurre si les pedimos esto mismo para float o doubles?. */


int * cargarVector(int tam);

int * cargarVectorAleatorio(int tam);

void mostrarVector(int *v, int tam);

void mostrarVectorInvertido(int *v, int tam);

int cantidadPares(int *v, int tam);

int calcularModulo(int *v, int tam);

int buscarMinimo(int *v, int tam);

int buscarMaximo(int *v, int tam);

void ordenarArrayBurbuja(int *v, int tam);

void ordenarArraySeleccion(int *v, int tam); //???
 
void ordenarArrayInsercion(int *v, int tam); //??

int * sumarVectores(int *v1, int t1, int *v2, int t2);

int multiplicacionEscalar(int *v1, int t1, int *v2, int t2); //??

int busquedaSecuencial(int *v, int tam, int num);

int busquedaBinaria(int *v, int tam, int num); //??

#endif