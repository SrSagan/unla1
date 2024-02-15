#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 6

void cargarMatriz(int mat[TAM][TAM]);
void mostrarMatriz(int mat[TAM][TAM]);
void mostrarVocales(int mat[TAM][TAM]);
void mostrarDiagonal(int mat[TAM][TAM]);
void escribirMatriz(int mat[TAM][TAM]);
int checkRepe(int let, int mat[TAM][TAM]);

int main()
{
    srand(time(0));

    int matriz[TAM][TAM];
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    mostrarVocales(matriz);
    mostrarDiagonal(matriz);
    escribirMatriz(matriz);

    return 0;
}

void cargarMatriz(int mat[TAM][TAM])
{
    char let[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            mat[i][j]=-1;
        }
    }

    int num,rep;

    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            rep=1;
            do{
                num = rand()%52;
                if(!checkRepe(let[num],mat))
                {
                    rep=0;
                    mat[i][j] = let[num];
                }
            }while(rep);
        }
    }
}

int checkRepe(int let, int mat[TAM][TAM])
{
    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            if(let == mat[i][j]) return 1;
        }
    }
    return 0;
}

void mostrarMatriz(int mat[TAM][TAM])
{
   for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    } 
}

void mostrarVocales(int mat[TAM][TAM])
{
    char voc[]="aeiouAEIOU"; //tam=10
    int found=0;

    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            found=0;

            for(int l=0;l<10;l++)
            {
                if(mat[i][j] == voc[l])
                {
                    found = 1;
                    printf("%c ", mat[i][j]);
                }
            }
            if(!found) printf("# "); //agregue espacio despues del papel
        }
        printf("\n");
    }
}

void mostrarDiagonal(int mat[TAM][TAM])
{
    int jpos=TAM-1; //baja
    int ipos=0; //sube

    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            if((i == ipos) && (j == jpos))
            {
                printf("%c ", mat[i][j]);
                jpos--;
                ipos++;
            }
            else printf(" ");
        }
        printf("\n");
    } 
    
}

void escribirMatriz(int mat[TAM][TAM])
{
    FILE * fp;
    fp = fopen("matriz.txt","w");

    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            fprintf(fp, "%c ", mat[i][j]);
        }
        fprintf(fp, "\n");
    } 
    fclose(fp);
}