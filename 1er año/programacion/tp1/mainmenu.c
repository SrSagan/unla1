#include <stdio.h>
#include <stdlib.h>

#include "mainmenu.h"
#include "game.h"
#include "players.h"

int printmain()
{
    system("cls");
    printf("----MENU PRINCIPAL----\n");
    printf("1) Nuevo juego\n");
    printf("2) High scores\n");
    printf("3) Salir\n");
    printf("----MENU PRINCIPAL----\n");
    int loop = selectOption();
    return loop;
}

int printplayers()
{
    system("cls");
    int cantidad = 0;
    printf("Cuantos jugadores desean jugar? (2-4)\n");
    scanf("%d", &cantidad);
    if(cantidad < 2 || cantidad > 4)
    {
        printf("%d es una cantidad invalida de jugadores\npor favor seleccione entre 2 y 4 jugadores\n", cantidad);
        printplayers();
    }
    else return cantidad;

}

int selectOption()
{
    int select=0;
    scanf("%d", &select);

    switch (select)
    {
        case 1: ;
            int cantidad = printplayers();
            startGame(cantidad);
            return 1;
            break;

        case 2:
            //display high scores
            mostrarHighScores();
            return 1;
            break;

        case 3: ;
            return 0;
            break;

        default: ;
            printmain();
            break;
    }
}
