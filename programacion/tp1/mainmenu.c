#include <stdio.h>
#include <stdlib.h>

#include "mainmenu.h"
#include "game.h"

void printmain()
{
    printf("----MENU PRINCIPAL----\n");
    printf("1) Nuevo juego\n");
    printf("2) High scores\n");
    printf("3) Salir\n");
    printf("----MENU PRINCIPAL----\n");
    selectOption();
}

int printplayers()
{   
    int cantidad = 0;
    printf("Cuantos jugadores desean jugar? (2-4)\n");
    scanf("%d", &cantidad);
    if(cantidad < 2 || cantidad > 4)
    {
        printf("%d es una cantidad invalida de jugadores\npor favor seleccione entre 2 y 4 jugadores\n");
        printplayers();
    }
    else return cantidad;

}

void selectOption()
{
    int select=0;
    scanf("%d", &select);

    switch (select)
    {
        case 1:
            int cantidad = printplayers();
            startGame(cantidad);
            break;

        case 2:
            //display high scores
            break;

        case 3:
            system("exit");
            break;

        default:
            printf("%d no es una opcion valida, por favor seleccione una opcion del menu\n", select);
            printmain();
            break;
    }
}