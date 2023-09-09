#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

void cargarEmpleadoTeclado(EmpleadoPtr empleados[], int pos)
{
    EmpleadoPtr e = malloc(sizeof(struct Empleado));

    printf("Escriba el nombre del empleado a ingresar\n");
    getchar(); //arreglo de fflush para linux
    gets(e->nombre);
    printf("Escriba el legajo del empleado a ingresar\n");
    scanf("%d", &e->legajo);
    printf("Escriba el sueldo del empleado a ingresar\n");
    scanf("%d", &e->sueldo);

    empleados[pos] = e;
}

int eliminarEmpleado(EmpleadoPtr empleados[], int tam, int legajo)
{
    EmpleadoPtr e = malloc(sizeof(struct Empleado));
    e->legajo=-1;
    for(int i=0;i<tam;i++)
    {
        if(empleados[i]->legajo == legajo)
        {
            empleados[i]=e;
            return 1;
        }
    }
    return -1;
}

int buscarNombre(EmpleadoPtr e[], int tam, char nom[])
{
    for(int i=0;i<tam;i++)
    {
        if(strcmp(nom,e[i]->nombre) == 0) return i;
    }
    return -1;
}

void ordernarNombre(EmpleadoPtr e[], int tam)
{
    EmpleadoPtr aux = malloc(sizeof(struct Empleado));
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(e[i]->nombre, e[j]->nombre) > 0)
            {
                aux = e[j];
                e[j] = e[i];
                e[i] = aux;
            }
        }
    }
}

void ordenarNumero(EmpleadoPtr e[], int tam)
{
    EmpleadoPtr aux = malloc(sizeof(struct Empleado));
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(e[i]->legajo > e[j]->legajo)
            {
                aux = e[j];
                e[j] = e[i];
                e[i] = aux;
            }
        }
    }
}

int checkVacio(EmpleadoPtr e[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        if(e[i]->legajo == -1) return i;
    }
    return -1;
}

void mostrarEmpleados(EmpleadoPtr e[], int tam)
{
    printf("--------------\n");
    for(int i=0; i<tam; i++)
    {
        if(e[i]->legajo != -1)
        {
            printf("Nombre: %s\n", e[i]->nombre);
            printf("Legajo: %d\n", e[i]->legajo);
            printf("Sueldo: %d\n", e[i]->sueldo);
            printf("--------------\n");
        }
    }
}

void cargarVacios(EmpleadoPtr Empleados[], int tam)
{
    EmpleadoPtr e = malloc(sizeof(struct Empleado));
    e->legajo=-1;

    for(int i=0; i<tam; i++)
    {
        Empleados[i]=e;
    }
}

void cargarArchivo(EmpleadoPtr e[])
{
    FILE * fp;

    fp=fopen("empleados.txt","r");
    if(fp == NULL) return;

    char line[50];
    int i=0;
    while(!feof(fp))
    {
        fgets(line, 50, fp);
        e[i]=cargarEmpleado(line);
        i++;
    }

    fclose(fp);
}

EmpleadoPtr cargarEmpleado(char line[])
{
    EmpleadoPtr e = malloc(sizeof(struct Empleado));
    sscanf(line, "%[a-zA-Z];%d;%d\n", e->nombre, &(e->legajo), &(e->sueldo));
    return e;
}

void guardarArchivo(EmpleadoPtr empleados[], int tam)
{
    FILE * fp=fopen("empleados.txt","w");
    int first=1;
    for(int i=0;i<tam;i++)
    {
        if(empleados[i]->legajo!=-1)
        {
            if(first!=1) fprintf(fp ,"\n");
            fprintf(fp, "%s;%d;%d", empleados[i]->nombre,empleados[i]->legajo,empleados[i]->sueldo);
            first=0;
        }
    }
    fclose(fp);
}
