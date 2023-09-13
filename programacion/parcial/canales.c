#include <stdio.h>
#include <stdlib.h>

#include "canales.h"


void cargarVacios(CanalPtr e[], int tam)
{
    CanalPtr a = (CanalPtr) malloc(sizeof(struct Canal));
    a->vacio=1;

    //si alguna otra variable tiene que ser seteado por default
    //hacerlo aca

    for(int i=0; i<tam; i++)
    {
        e[i]=a;
    }
}

void mostrarCanales(CanalPtr e[], int tam)
{
    printf("--------------\n");
    for(int i=0; i<tam; i++)
    {
        if(e[i]->vacio != 1)
        {
            printf("Nombre: %s\n", e[i]->nombre);
            printf("Rating: %.2f\n", e[i]->rating);
            printf("Area: %s\n", e[i]->area);
            //reemplazar por variables
            printf("--------------\n");
        }
    }
}

void eliminarMenor(CanalPtr e[], int tam, int r)
{
    CanalPtr a = (CanalPtr) malloc(sizeof(struct Canal));
    a->vacio=1;
    for(int i=0;i<tam;i++)
    {
        if(e[i]->rating < r && e[i]->vacio != 1)
        {
            printf("--%s eliminado con un rating de %.2f--\n", e[i]->nombre, e[i]->rating);
            e[i]=a;
        }
    }
}

void cargarArchivo(CanalPtr e[])
{
    FILE * fp;

    fp=fopen("canal.txt","r"); //remplazar con archivo correcto
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

CanalPtr cargarEstructura(char line[])
{
    CanalPtr e = (CanalPtr) malloc(sizeof(struct Canal));
    sscanf(line, "%[a-zA-Z ]-%f-%[a-zA-Z ]\n", e->nombre, &(e->rating), e->area);
    //reemplazar con la estructura de varibles
    e->vacio=0;
    return e;
}


void guardarArchivo(CanalPtr e[], int tam)
{
    FILE * fp=fopen("elimandos.txt","w");
    int first=1;
    for(int i=0;i<tam;i++)
    {
        if(e[i]->vacio!=1)
        {
            if(first!=1) fprintf(fp ,"\n");
            fprintf(fp, "%s-%f-%s", e[i]->nombre,e[i]->rating,e[i]->area);
            //reemplazar con la estructura de varibles
            first=0;
        }
    }
    fclose(fp);
}
