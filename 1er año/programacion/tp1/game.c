#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "game.h"
#include "players.h"

struct Pregunta{

    char question[300];
    char respuestas[4][300];
    int vacio;

};

void startGame(int cantidad)
{
    system("cls");
    srand(time(NULL));

    PlayerStr players[cantidad];

    PlayerStr e = startEmpty();

    PreguntaStr preguntas[50];

    for(int i=0; i<cantidad; i++)
    {
        e = startPlayer(i);
        players[i]=e;
    }
    cargarVacios(preguntas, 50);
    //cargar preguntas

    cargarArchivo(preguntas);
    mainGame(preguntas, 50, players, cantidad);

}

void mainGame(PreguntaStr p[] ,int tamPr, PlayerStr j[], int tamJ)
{
    int cantidad=0;
    for(int i=0;i<tamPr;i++)
    {
        if(p[i]->vacio!=1) cantidad++;
    }

    int max=0;

    PlayerStr e = startEmpty();

    for(int i=0;i<tamJ;i++) //se hacen las preguntas y se guardan los puntajes
    {
        e = quiz(j[i], cantidad, p);

        if(getRespuestas(e) > max)
        {
            max = getRespuestas(e);
        }
        j[i]=e;

        printf("Respondiste %d preguntas bien\n\n", getRespuestas(e));
    }

    int empatados[tamJ];

    int counter = 0;
    for(int i=0;i<tamJ;i++)
    {
        if(getRespuestas(j[i]) == max)
        {
            empatados[counter] = i;
            counter++;
        }
    }

    if(counter > 1)
    {
        e = desempate(j, empatados, counter);

        printf("El ganador es %s\n", getAlias(e));

        for(int i=0;i<tamJ;i++)
        {
            if(getAlias(e) == getAlias(j[i]))
            {
                setRespuestas(j[i], getRespuestas(j[i])+1);
            }
        }
    }
    else
    {
        printf("El ganador es %s\n", getAlias(j[empatados[0]]));
    }

    ordenarPuntuacion(j, tamJ);

    mostrarPuntuacion(j, tamJ);

    guardarPuntuacion(j, tamJ);

}

PlayerStr quiz(PlayerStr plyr, int cantidad, PreguntaStr p[])
{
    system("cls");
    printf("--------------TURNO DE %s--------------\n\n",  getAlias(plyr));
    printf("Tu pregunta aparecera en 3 segundos\n\n");

    countDown(3, 1);

    int correcta = 1;

    while(correcta == 1)
    {
        int x = rand()% cantidad;
        PreguntaStr e = p[x];
        //pregunta random

        printf("%s?\n", e->question);
        //randomizamos las respuestas
        //la utlima siempre es la correcta

        x = rand()% 4; //randomiza la respuesta correcta
        int restante=0;

        //printf("X+1= %d  (respuesta correcta)\n\n", x+1); //imprimir respuesta correcta

        double inicio = startTimer();

        for(int i=0;i<4;i++)
        {
            if(i==x)
            {
                printf("%d) %s\n", i+1, e->respuestas[3]); //si i = valor random entonces en esa posicion va ir la correcta
                restante=1; //una vez que este la correcta desfaza todo el resto de respuestas para asegurar que no se repita la correcta
            }
            else
            {
                printf("%d) %s\n", i+1, e->respuestas[i-restante]); //sino pone otra
            }
        }

        int respuesta=0;
        do{
            printf("\nEscriba su respuesta del 1 al 4\n");
            scanf("%d", &respuesta);
            if(respuesta < 1 || respuesta > 4)
            {
                printf("La respuesta no es valida\n");
            }
        }while(respuesta < 1 || respuesta > 4);


        int diferencia = finishTimer(inicio, 15);

        if(diferencia <= 0)
        {
            printf("Tardaste mucho en responder :( \n\n");
            correcta=0;
            system("pause");
        }

        else if(respuesta == (x+1))
        {
            printf("La respuesta es correcta :D\n\n");
            correcta = 1;

            setRespuestas(plyr,getRespuestas(plyr)+1);

            diferencia += getPuntos(plyr);
            setPuntos(plyr, diferencia);
            countDown(2, 0);
            system("cls");
        }
        else
        {
            printf("La respuesta es incorrecta D:\n\n");
            correcta=0;
            system("pause");
        }
    }

    return plyr;

}

PlayerStr desempate(PlayerStr j[], int empatados[], int counter)
{
    int empate=0;
    int pos=0;
    do{
        empate=0;
        system("cls");
        int puntos[counter];
        printf("Hay un empate entre:");
        for(int i=0;i<counter;i++)
        {
            if(i != 0) printf(", ");
            int pos = empatados[i];
            printf(" %s", getAlias(j[pos]));
        }
        printf("\n\n");

        printf("Para desempatar se hara una pregunta matematica distinta a cada uno\nLa pregunta aparecera en la pantalla por 3 segundos y luego tendran 5 segundos para responderla\n");
        printf("El que este mas cerca de la respuesta correcta ganara\n");
        system("pause");

        //cuenta x-y/z //detalle la cuenta se es realmente x-(y/z)

        for(int i=0;i<counter;i++)
        {
            system("cls");
            int pos = empatados[i];
            printf("--------------TURNO DE %s--------------\n\n",  getAlias(j[pos]));

            int x,y,z;

            x = rand()% 100;
            y = rand()% 100;
            z = 1+rand()% 11;

            int answer = trunc(x+(y/z));
            printf("La pregunta aparecera en 3 segundos:\n");
            countDown(3, 1);
            printf("\n");

            printf("%d+%d/%d\n\n", x,y,z);
            countDown(3, 1);
            system("cls");
            printf("Tienes 5 segundos para responderla\n");

            double start = startTimer();

            int plyrAnswer=0;
            scanf("%d", &plyrAnswer);

            int diferencia=0;

            if(finishTimer(start, 5) <= 0)
            {
                printf("Tardaste mucho :(\n");
                puntos[pos]=1000000;
                diferencia = 1000000;
            }
            else
            {
                diferencia = trunc(fabs(plyrAnswer-answer));
                puntos[pos]=diferencia;
                printf("La respuesta correcta es: %d\n", answer);
                printf("Estuviste a %d de la respuesta correcta\n\n", diferencia);
            }

            countDown(5, 0);

        }

        int min;

        for(int i=0;i<counter;i++)
        {
            int x = empatados[i];
            if(i==0) min=puntos[x];

            if(min > puntos[x])
            {
                min = puntos[x];
                pos=i;
            }
        }

        for(int i=0;i<counter;i++)
        {
            int x = empatados[i];
            if(min == puntos[x])
            {
                empate++;
            }
        }

    }while(empate>1);

    return j[pos];
}

void ordenarPuntuacion(PlayerStr e[], int tamJ)
{
    for(int i=0;i<tamJ-1;i++)
    {
        for(int j=i+1;j<tamJ;j++)
        {
            if(getRespuestas(e[i]) < getRespuestas(e[j]))
            {
                int aux = getPuntos(e[j]);
                setPuntos(e[j], getPuntos(e[i]));
                setPuntos(e[i], aux);

                aux = getDni(e[j]);
                setDni(e[j], getDni(e[i]));
                setDni(e[i], aux);

                char aux1[20];
                strcpy(aux1, getAlias(e[j]));
                setAlias(e[j], getAlias(e[i]));
                setAlias(e[i], aux1);

                aux = getRespuestas(e[j]);
                setRespuestas(e[j], getRespuestas(e[i]));
                setRespuestas(e[i], aux);

            }
        }
    }
}

void mostrarPuntuacion(PlayerStr e[], int tamJ)
{
    //se ordena la puntuacion por respuesta
    int maxlen=10;

    //se imprime el cuadro
    //"respuestas" largo de 10
    //nadie va a llegar a una puntuacion de 15^10 asi que podemos asumir que siempre va a ser el mas largo
    //por ende solo faltaria agregar los espacios a cada linea
    //la primera ya la sabemos

    system("cls");

    printf("|JUGADOR   |PUNTOS    |RESPUESTAS|\n");

    int len;
    for(int i=0;i<tamJ;i++)
    {
        printf("|--------------------------------|\n");
        len = strlen(getAlias(e[i]));
        printf("|%s", getAlias(e[i]));

        printSpaces(len, maxlen);

        len=0;
        int valor = getPuntos(e[i]);
        do
        {
            valor = valor/10;
            len++;
        }while(valor >=1);

        printf("%d",getPuntos(e[i]));
        printSpaces(len, maxlen);

        len=0;
        valor = getRespuestas(e[i]);
        do
        {
            valor = valor/10;
            len++;
        }while(valor >=1);

        printf("%d",getRespuestas(e[i]));
        printSpaces(len, maxlen);
        printf("\n");
    }
    system("pause");

}

void printSpaces(int len, int maxlen)
{
    for(int j=0;j<maxlen-len;j++)
        {
            printf(" ");
        }
        printf("|");
}

void cargarVacios(PreguntaStr e[], int tam)
{
    PreguntaStr a = (PreguntaStr) malloc(sizeof(struct Pregunta));
    a->vacio=1;

    //si alguna otra variable tiene que ser seteado por default
    //hacerlo aca

    for(int i=0; i<tam; i++)
    {
        e[i]=a;
    }
}

void cargarArchivo(PreguntaStr e[])
{
    FILE * fp;

    fp=fopen("preguntas.txt","r"); //remplazar con archivo correcto
    if(fp == NULL) return;

    char line[500];
    int i=0;
    while(!feof(fp))
    {
        fgets(line, 500, fp);
        e[i]=cargarEstructura(line);
        i++;
    }

    fclose(fp);
}

PreguntaStr cargarEstructura(char line[])
{
    PreguntaStr e = (PreguntaStr) malloc(sizeof(struct Pregunta));
    sscanf(line, "%[0-9a-zA-Z ];%[0-9a-zA-Z ];%[0-9a-zA-Z ];%[0-9a-zA-Z ];%[0-9a-zA-Z ]", e->question, e->respuestas[0], e->respuestas[1], e->respuestas[2], e->respuestas[3]);
    e->vacio=0;

    return e;
}

void countDown(int seconds, int print)
{
    clock_t startTime, currentTime;

    startTime = clock();
    currentTime = startTime;
    double diferencia, diferenciaOld;

    if(print) printf("\r--------------Quedan %d segundos--------------", seconds);


    while(((double)(currentTime - startTime)/CLOCKS_PER_SEC) < seconds)
    {
        diferencia = seconds-((double)(currentTime - startTime)/CLOCKS_PER_SEC);
        if(startTime == currentTime)
        {
            diferenciaOld = diferencia;
        }
        currentTime = clock();

        if(print && (diferencia == diferenciaOld-1))
        {
            printf("\r--------------Quedan %.0f segundos--------------", diferencia);
            diferenciaOld = diferencia;
        }
    }

    if (print) printf("\n");
}

double startTimer()
{
    clock_t startTime;
    startTime = clock();
    return (double)(startTime/CLOCKS_PER_SEC);
}

int finishTimer(double seconds, int target)
{
    clock_t currentTime;
    currentTime = clock();

    int diferencia;

    diferencia = target-(int)((currentTime/CLOCKS_PER_SEC)-seconds);
    //printf("diferencia: %d\n", diferencia); //imprimir diferencia

    return diferencia;
}
