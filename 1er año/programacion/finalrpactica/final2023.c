#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** cargar_mat(int **mat);
//crear matriz de 4x5 y llenarla de numeros aleatorios de 3 cifras pares
//luego invertir la matriz

void mostrar_mat(int **mat, int x, int y);
int check_repeat(int num, int **mat);

int** invertir_mat(int **mat);

int main()
{
    srand(time(0));

    int **mat;

    mat = cargar_mat(mat);

    mostrar_mat(mat, 4, 5);

    mat = invertir_mat(mat);
    printf("-----------------------------------\n");
    mostrar_mat(mat, 5, 4);

    return 0;
}

int** cargar_mat(int **mat)
{
    mat = malloc(4 * sizeof(int *));

    for(int i=0;i<4;i++)
    {
        mat[i] = malloc(5 * sizeof(int)); //reservamos memoria
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            mat[i][j]=-1; //"vaciamos la matriz"
        }
    }

    int encontrado=0;
    int num;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            //numeros random de 3 cifras pares
            //numero par = n*2
            //numero de 3 cifras 100 <= n <= 999
            //999/2 = 498

            encontrado=0;
            while(!encontrado)
            {
                num=(50+rand()%(499-50))*2; //numero de 100 a 499 *2

                encontrado = !check_repeat(num, mat);
            }

            mat[i][j] = num;
        }
    }

    return mat;

}

void mostrar_mat(int **mat, int x, int y)
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}


int check_repeat(int num, int **mat)
//return 0 if number not found
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(num == mat[i][j]) return 1;
        }
    }
    return 0;
}

int** invertir_mat(int **mat)
{
    int **matinv;
    matinv = malloc(5 * sizeof(int *));

    for(int i=0;i<5;i++)
    {
        matinv[i]=malloc(4 * sizeof(int));
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            matinv[j][i] = mat[i][j];
        }
    }

    return matinv;
}