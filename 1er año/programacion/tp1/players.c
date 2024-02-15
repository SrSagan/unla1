#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "players.h"

struct Player{

    char alias[20];
    int dni;
    int puntos;
    int respuestas;
};

PlayerStr startPlayer(int pos)
{
    PlayerStr e = (PlayerStr) malloc(sizeof(struct Player));

    printf("Jugador %d ingrese su alias\n", pos+1);
    scanf("%s", e->alias);
    printf("Ingrese su DNI\n");
    scanf("%d", &e->dni);
    e->puntos=0;
    e->respuestas=0;
    printf("\n\n");

    return e;

}

PlayerStr startEmpty()
{
    PlayerStr e = (PlayerStr) malloc(sizeof(struct Player));
    return e;
}

//---------------------------------SET-------------------------------

PlayerStr setAlias(PlayerStr e, char alias[])
{
    strcpy(e->alias, alias);
    return e;
}

PlayerStr setDni(PlayerStr e, int dni)
{
    e->dni=dni;
    return e;
}

PlayerStr setPuntos(PlayerStr e, int puntos)
{
    e->puntos=puntos;
    return e;
}

PlayerStr setRespuestas(PlayerStr e, int respuestas)
{
    e->respuestas=respuestas;
    return e;
}

//---------------------------------GET-------------------------------

char * getAlias(PlayerStr e)
{
    return e->alias;
}

int getDni(PlayerStr e)
{
    return e->dni;
}

int getPuntos(PlayerStr e)
{
    return e->puntos;

}

int getRespuestas(PlayerStr e)
{
    return e->respuestas;
}

//-------------------------------ARCHIVO-----------------------------

int getSize()
{
    FILE * fp=fopen("jugadores.txt","r");
    if(fp==NULL) return 0;

    char line[50];
    int i=0;
    while(!feof(fp))
    {
        fgets(line, 50, fp);
        i++;
    }
    fclose(fp);
    return i;
}

void iniciarJugadores(PlayerStr e[], int tam)
{
    PlayerStr j = malloc(sizeof(struct Player));
    j->dni=0;
    j->puntos=0;
    j->respuestas=0;

    for(int i=0;i<tam;i++)
    {
        e[i]=j;
    }
}

void guardarPuntuacion(PlayerStr e[], int tamJ)
{
    int size = getSize();
    if(size == 0) size=tamJ;
    else size=size+tamJ;

    PlayerStr jugadores[size];
    iniciarJugadores(jugadores, size);

    cargarPuntuacion(jugadores);

    int found=0;
    for(int i=0;i<tamJ;i++)
    {
        //printf("jugador actual: %d\n", e[i]->dni);
        found = 0;
        for(int j=0;j<size;j++)
        {
            //printf("jugador actual archivo: %d\n", jugadores[j]->dni);
            if(e[i]->dni == jugadores[j]->dni)
            {
                printf("Es igual\n");
                found=1;
            
                if(e[i]->puntos > jugadores[j]->puntos)
                {
                    jugadores[j]->puntos = e[i]->puntos;
                }
                break;
            }
        }
        if(!found)
        {
            for(int j=0;j<size;j++)
            {
                if(jugadores[j]->dni == 0)
                {
                    jugadores[j] = e[i];
                    break;
                }
            }
        }

    }

    //jugadores array completa
    //los ordeno
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(getPuntos(jugadores[i]) < getPuntos(jugadores[j]))
            {
                int aux = getPuntos(jugadores[j]);
                setPuntos(jugadores[j], getPuntos(jugadores[i]));
                setPuntos(jugadores[i], aux);

                aux = getDni(jugadores[j]);
                setDni(jugadores[j], getDni(jugadores[i]));
                setDni(jugadores[i], aux);

            }
        }
    }

    FILE * fp=fopen("jugadores.txt","w");

    int first=1;
    for(int i=0;i<size;i++)
    {
        if(jugadores[i]->dni!=0)
        {
            if(first!=1) fprintf(fp ,"\n");
            fprintf(fp, "%d;%d", jugadores[i]->dni,jugadores[i]->puntos);
            //reemplazar con la estructura de varibles
            first=0;
        }
    }

    /*for(int i=0;i<size;i++)
    {
        printf("DNI: %d\n", jugadores[i]->dni);
    }
    system("pause");*/ //debugging

    fclose(fp);

}

void cargarPuntuacion(PlayerStr e[])
{
    FILE * fp;
    fp=fopen("jugadores.txt","r");
    if(fp==NULL) return;

    char line[50];
    int i=0;
    while(!feof(fp))
    {
        fgets(line, 50, fp);
        e[i]=cargarJugador(line);
        i++;
    }
    fclose(fp);
}

PlayerStr cargarJugador(char line[])
{
    PlayerStr e = malloc(sizeof(struct Player));
    sscanf(line, "%d;%d\n", &e->dni, &e->puntos);
    return e;
}

void mostrarHighScores()
{
    system("cls");
    int size = getSize();
    PlayerStr e[size];

    cargarPuntuacion(e);

    if(size > 10) size=10;
    printf("-------------------HIGH SCORES-------------------\n\n");
    printf("POS     DNI                            PUNTOS\n");

    for(int i=0;i<size;i++)
    {
        printf("%d      %d                         %d\n", i+1, e[i]->dni, e[i]->puntos);
    }
    printf("\n-------------------HIGH SCORES-------------------\n\n");
    system("pause");
}
