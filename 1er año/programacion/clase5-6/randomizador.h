#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int randomNumber(int min, int max)
{
    srand(time(NULL));

    return min+rand()%max+1;
}

/*
char randomArrayChar(char v[], int tam)
{
    srand(time(NULL));
    int val = rand()%tam;
    return v[val];
}*/

int randomArrayInt(int v[], int tam)
{
    srand(time(NULL));
    int val = rand()%tam;
    return v[val];
}

char randomLetra()
{
    srand(time(NULL));
    char letras[29]="abcdefghijklmnñopqrstuvwxyz";
    int val = rand()%30;
    return letras[val];
}