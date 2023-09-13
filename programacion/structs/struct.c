#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void cargarVacios(EstructuraPtr e[], int tam)
{
    EstructuraPtr a = malloc(sizeof(struct Estructura));
    a->vacio=1;

    //si alguna otra variable tiene que ser seteado por default
    //hacerlo aca

    for(int i=0; i<tam; i++)
    {
        e[i]=a;
    }
}

int checkVacio(EstructuraPtr e[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        if(e[i]->vacio == 1) return i;
    }
    return -1;
}

void cargarStruct(EstructuraPtr e[], int pos)
{
    EstructuraPtr a = malloc(sizeof(struct Estructura));

    //getchar(); //en caso de que fflush sea necesario
    //ponerlo antes de un gets();
    //ej:
    //printf("Escriba un nombre a ingresar\n");
    //getchar();
    //gets(a->nombre);

    e[pos] = a;
}

int eliminarEstructura(EstructuraPtr e[], int tam, int id)
{
    EstructuraPtr a = malloc(sizeof(struct Estructura));
    a->vacio=1;
    for(int i=0;i<tam;i++)
    {
        if(e[i]->id == id) //id = algun identificador que no se repita
        {
            e[i]=a;
            return 1;
        }
    }
    return -1;
}

void mostrarEstructuras(EstructuraPtr e[], int tam)
{
    printf("--------------\n");
    for(int i=0; i<tam; i++)
    {
        if(e[i]->vacio != 1)
        {
            //printf("Nombre: %s\n", e[i]->nombre);
            //printf("Legajo: %d\n", e[i]->legajo);
            //printf("Sueldo: %d\n", e[i]->sueldo);
            //reemplazar por variables
            printf("--------------\n");
        }
    }
}

int buscarChar(EstructuraPtr e[], int tam, char word[])
{
    for(int i=0;i<tam;i++)
    {
        if(strcmp(word,e[i]->word) == 0) return i;
        //word es un char dentro del struct como un nombre
    }
    return -1;
}

void ordernarChar(EstructuraPtr e[], int tam)
{
    EstructuraPtr aux = malloc(sizeof(struct Estructura));
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(e[i]->word, e[j]->word) > 0)
            //word es un char dentro del struct como un nombre
            {
                aux = e[j];
                e[j] = e[i];
                e[i] = aux;
            }
        }
    }
}

void ordenarNumero(EstructuraPtr e[], int tam)
{
    EstructuraPtr aux = malloc(sizeof(struct Estructura));
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(e[i]->id > e[j]->id)
            //id debe ser reemplazado por un numero del struct
            {
                aux = e[j];
                e[j] = e[i];
                e[i] = aux;
            }
        }
    }
}

void cargarArchivo(EstructuraPtr e[])
{
    FILE * fp;

    fp=fopen("estructura.txt","r"); //remplazar con archivo correcto
    if(fp == NULL) return;

    char line[50];
    int i=0;
    while(!feof(fp))
    {
        fgets(line, 50, fp);
        e[i]=cargarEstructura(line);
        i++;
    }

    fclose(fp);
}

EstructuraPtr cargarEstructura(char line[])
{
    EstructuraPtr e = malloc(sizeof(struct Estructura));
    //sscanf(line, "%[a-zA-Z ];%d;%d\n", e->nombre, &(e->legajo), &(e->sueldo));
    //reemplazar con la estructura de varibles
    e->vacio=0;
    return e;
}

void guardarArchivo(EstructuraPtr e[], int tam)
{
    FILE * fp=fopen("estructura.txt","w");
    int first=1;
    for(int i=0;i<tam;i++)
    {
        if(e[i]->vacio!=1)
        {
            if(first!=1) fprintf(fp ,"\n");
            //fprintf(fp, "%s;%d;%d", empleados[i]->nombre,empleados[i]->legajo,empleados[i]->sueldo);
            //reemplazar con la estructura de varibles
            first=0;
        }
    }
    fclose(fp);
}