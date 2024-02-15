#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*int main()
{

    srand(time(NULL));

    //LOGICA:

    /*Para crear un puntero de una matriz o array con tamaños *DESCONOCIDOS* en sus ejes se utilizan los punteros de punteros
    
    para simplificar utilizaremos una matriz de 2 dimensiones de ejemplo:
    queremos crear un puntero de una array de arrays, cada uno de los valores dentro de las arrays sera un puntero
    creamos un puntero de puntero: int ** puntero;
    luego por cada valor de nuestro eje x tendremos que guardar espacio para guardar OTRO PUNTERO en el cual entraran nuestros valores de y:
    puntero = malloc(ejex * sizeof(int *));
    una vez que hice esto, por cada valor de mi ejex tengo que guardar una cantidad de espacios del tamaño de mi eje y de enteros
    for(int i=0;i<ejex;i++)
    {
        puntero[i] = malloc(ejey * sizeof(int));
    }
    */
    /*

    int vpixels=100;
    int hpixels=100;

    int pantalla[vpixels][hpixels][3]; //declaro la matriz pantalla tridimensional

    int *** ptr; //triple puntero fua reloco (puntero de un puntero de un puntero)

    ptr = malloc(vpixels * sizeof(int **)); //hago un malloc de la cantidad de pixels verticales por el tamño de un puntero de un puntero

    for(int i=0;i<vpixels;i++)
    {
        ptr[i] = malloc(hpixels * sizeof(int *)); //hago otro malloc esta vez de la cantidad de pixeles horizontales por el tamaño de un puntero

        for(int j=0;j<hpixels;j++)
        {
            ptr[i][j] = malloc(3 * sizeof(int)); //por ultimo hago un malloc por el tamaño de colores por pixel por el tamaño de un entero
        }
    }

    for(int v=0;v<vpixels;v++)
    {
        for(int h=0;h<hpixels;h++)
        {
            for(int c=0;c<3;c++)
            {
                ptr[v][h][c] = rand()%256;
            }
        }
    }



    return 0;
}*/
//■

int main()
{
    srand(time(NULL));

    int vpixels=100;
    int hpixels=100;

    int pantalla[vpixels][hpixels][3];


    for(int v=0;v<vpixels;v++)
    {
        for(int h=0;h<hpixels;h++)
        {
            for(int c=0;c<3;c++)
            {
                pantalla[v][h][c] = rand()%256;
            }
        }
    }

    typedef int c_array[3]; //renombro una array int de 3 espacios a c_array
    typedef c_array h_array[vpixels]; //creo una array de c_array es decir una matriz de vpixels x 3

    h_array * ptr; //creo un puntero de mi matriz

    ptr = malloc(hpixels * vpixels * 3 * sizeof(int)); //dejo el espacio para la matriz tridimensional

    for(int v=0;v<vpixels;v++)
    {
        for(int h=0;h<hpixels;h++)
        {
            for(int c=0;c<3;c++)
            {
                ptr[v][h][c] = pantalla[v][h][c];
            }
        }
    }

    return 0;
}