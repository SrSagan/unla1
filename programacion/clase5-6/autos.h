#include <stdio.h>
#include <string.h>
#include "randomizador.h"

struct Auto
{
    char patente[10];
    int anio;
    char color[20];
    int precio;
};

struct Auto cargarAutoTeclado();
struct Auto cargarAutoRandom();
void crearPatenteRandom(char v[]);

struct Auto cargarAutoTeclado()
{
    struct Auto a;

    printf("Escriba la patente del auto\n");
    gets(a.patente);
    printf("Escriba el año del auto\n");
    scanf("%d", &a.anio);
    printf("Escriba el color del auto\n");
    gets(a.color);
    printf("Escriba el precio del auto\n");
    scanf("%d", &a.precio);

    return a;
    
}

struct Auto cargarAutoRandom()
{
    struct Auto a;
    char patente[7];
    crearPatenteRandom(patente);
    strcpy(a.patente, patente);
    a.anio=randomNumber(1950, 2023);
    a.precio=randomNumber(1000000, 10000000);

    char colores[10][20];
    strcpy(colores[0], "rojo");
    strcpy(colores[1], "azul");
    strcpy(colores[2], "verde");
    strcpy(colores[3], "dorado");
    strcpy(colores[4], "gris");
    strcpy(colores[5], "amarillo");
    strcpy(colores[6], "negro");
    strcpy(colores[7], "blanco");
    strcpy(colores[8], "Azul oscuro");
    strcpy(colores[9], "Bordo");

    strcpy(a.color, colores[randomNumber(0,9)]);

}

void crearPatenteRandom(char v[])
{
    v[0]=randomLetra();
    v[1]=randomLetra();
    v[2]=randomNumber(1, 9);
    v[3]=randomNumber(1, 9);
    v[4]=randomNumber(1, 9);
    v[5]=randomLetra();
    v[6]=randomLetra();
}