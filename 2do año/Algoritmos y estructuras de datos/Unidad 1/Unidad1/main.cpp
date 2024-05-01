#include <iostream>
#include "vectores.h"
#include <time.h>
#include "matrices.h"
#define TAM 10
#define TX 5
#define TY 5

using namespace std;

int main()
{
    cout << "Santiago Dal Degan - 45421137 - TN-Jueves\n\n";
    srand(time(NULL));
    int v[TAM];
    cargarVectorAleatorio(v, TAM);
    mostrarVector(v, TAM);
    cout << "\n";
    mostrarVectorInvertido(v, TAM);

    cout << "Cantidad de pares: " << cantidadPares(v, TAM) << "\n";

    cout << "Modulo: " << calcularModulo(v, TAM) << "\n";

    cout << "Minimo: " << v[buscarMinimo(v, TAM)] << "\n";
    cout << "Maximo: " << v[buscarMaximo(v, TAM)] << "\n";

    ordenarArrayBurbuja(v, TAM);
    cout << "\nOrdenado:\n";

    mostrarVector(v, TAM);
    cout << "\nDesornedado:\n";

    cargarVectorAleatorio(v, TAM);

    mostrarVector(v, TAM);

    cout << "\nOrdenado:\n";

    ordenarArrayInsercion(v, TAM);

    mostrarVector(v, TAM);
    cout << "\nDesornedado:\n";

    cargarVectorAleatorio(v, TAM);

    mostrarVector(v, TAM);
    cout << "\nV Ordenado:\n";

    ordenarArraySeleccion(v, TAM);

    mostrarVector(v, TAM);
    cout << "\n\nF:\n\n";

    int f[TAM];
    int r[TAM];
    cargarVectorAleatorio(f, TAM);

    mostrarVector(f, TAM);
    cout << "\n\nV + F =\n\n";


    if(sumarVectores(v, TAM, f, TAM, r))
    {
        mostrarVector(r, TAM);
        cout << "\n\n";
    }
    else cout << "Error al sumar vectores\n";

    cout << "Multiplicacion escalar entre V y F= " << multiplicacionEscalar(v, TAM, f, TAM) << "\n";

    if(busquedaSecuencial(v, TAM, 5) != -1)
    {
        cout << "El numero 5 se encuentra en v[" << busquedaSecuencial(v, TAM, 5) << "]\n";
    }
    else cout << "El numero 5 no se encuentra en V\n";

    if(busquedaBinaria(v, TAM, 27) != -1)
    {
        cout << "El numero 27 se encuentra en v[" << busquedaBinaria(v, TAM, 27) << "]\n";
    }
    else cout << "El numero 27 no se encuentra en V\n";

    //---------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------MATRICES-----------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------------------
    cout << "\n\n--------------------------------------------------------------------------------------------------------\n\n";

    int ** m = crearMatriz(TX, TY);

    cargarMatrizAleatorio(m, TX, TY);
    cout << "m:\n";
    mostrarMatriz(m, TX, TY);


    cout << "\n\n";
    //El vector del minimo o maximo se vera asi: [x, y] x e y correspondiendo a la posicion del minimo

    int pos[2];

    buscarMinimo(m, TX, TY, pos); //retorna vector

    cout << "El minimo es: " << m[pos[0]][pos[1]] << "\n";

    buscarMaximo(m, TX, TY, pos); //retorna vector

    cout << "El maximo es: " << m[pos[0]][pos[1]] << "\n";

    int prom[TX];

    promedioFilas(m, TX, TY, prom); //retorna vector

    cout << "\n\n";

    cout << "El promedio de las filas es: \n";
    for(int i=0;i<TX;i++)
    {
        cout << prom[i] << "\n";
    }

    promedioColumnas(m, TX, TY, prom); //retorna vector

    cout << "\n\n";

    cout << "El promedio de las columnas es: \n";
    for(int i=0;i<TX;i++)
    {
        cout << prom[i] << " ";
    }

    cout << "\n\n";

    cout << "El promedio general es: " << promedioGeneral(m, TX, TY) << "\n";

    sumaColumnas(m, TX, TY, prom); //retorna vector

    cout << "La suma de las columnas es: \n";
    for(int i=0;i<TX;i++)
    {
        cout << prom[i] << " ";
    }

    cout << "\n\n";


    sumaFilas(m, TX, TY, prom); //retorna vector

    cout << "La suma de las filas es: \n";
    for(int i=0;i<TX;i++)
    {
        cout << prom[i] << "\n";
    }

    int ** m2 = crearMatriz(TX, TY);
    cargarMatrizAleatorio(m2, TX, TY);
    int ** ms = crearMatriz(TX, TY);

    cout << "\nm2:\n";

    mostrarMatriz(m2, TX, TY);
    cout << "\n\n";

    sumaMatrices(m, TX, TY, m2, TX, TY, ms); //retorna matriz ms= matriz salida

    cout << "m + m2 = \n";
    mostrarMatriz(ms, TX, TY);
    cout << "\n\n";

    productoMatrices(m, TX, TY, m2, TX, TY, ms); //retorna matriz ms= matriz salida*/

    cout << "m * m2 = \n";
    mostrarMatriz(ms, TX, TY);

    return 0;
}
