#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "empleados.h"


void mainmenu(EmpleadoPtr e[], int tam)
{
    cargarArchivo(e);
    while(1)
    {
        printf("--------MENU--------\n");
        printf("1) Agregar empleado\n");
        printf("2) Mostrar empleados\n");
        printf("3) Eliminar empleado\n");
        printf("4) Buscar por nombre\n");
        printf("5) Ordenar por nombre\n");
        printf("6) Ordenar por legajo\n");
        printf("7) Salir\n");
        printf("--------MENU--------\n");

        int opcion=0;
        scanf("%d", &opcion);

        switch(opcion){

            case 1:

                int pos = checkVacio(e, tam);
                if(pos == -1)
                {
                    printf("No hay espacio para mas empleados\n");
                    break;
                }
                cargarEmpleadoTeclado(e, pos);
                break;

            case 2:

                mostrarEmpleados(e, tam);
                break;

            case 3:

                int legajo;
                int borrado=-1;
                while(borrado == -1)
                {
                    printf("Escriba el numero de legajo del empleado\n");
                    scanf("%d", &legajo);
                    borrado = eliminarEmpleado(e, tam, legajo);
                    if(borrado == -1) printf("Legajo invalido\n");
                }
                break;

            case 4:

                char name[50];
                int valido=-1;
                do
                {
                    printf("Escriba el nombre de un empleado\n");
                    getchar();
                    gets(name);
                    valido = buscarNombre(e, tam, name);
                    if(valido == -1) printf("El nombre no es valido\n");

                }while(valido == -1);
                break;

            case 5:

                ordernarNombre(e, tam);
                break;

            case 6:

                ordenarNumero(e, tam);
                break;

            case 7:

                guardarArchivo(e, tam);
                return;
                break;

            default:

                printf("La opcion es invalida\n");
                break;
        }

    }
}
