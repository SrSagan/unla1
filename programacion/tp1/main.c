#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mainmenu.h"

//descomentar el sistema operativo utilizado
#define OS "clear" //linux
//#define OS "cls" //windows


int main()
{
    system(OS);
    printmain();
    return 0;
}