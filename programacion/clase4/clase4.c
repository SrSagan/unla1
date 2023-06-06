#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Crear una matriz de 12 columnas y 4 renglones, de números decimales
//cada valor explica las ganancias de 4 empresas distintas mes a mes.

//datos:
/*
A- Encontrar el total ganado por cada empresa al año.
B- Encontrar cuanto se gano por mes contando a todas las empresas
C- Calcular el total ganado por todas las empresas juntas.
D- Encontrar que empresa gano mas y en qué mes.
E- Que empresa gano menos y cuándo.
F- Calcular el promedio de ganancias de cada empresa por bimestres. ¿Cuál gano mas en cada bimestre?
EXTRA- Hacer un cuadro para mostrar los valores originales*/


int main()
{
    srand(time(NULL));

    float random;
    int maximo=300000;

    printf("Escriba el maximo de ganancia por mes\n");
    scanf("%d", &maximo);

    float empresas[4][12];  
    for(int empresa=0;empresa<4;empresa++)
    {
        for(int mes=0;mes<12;mes++)
        {
            random = rand()%maximo+1/1.14;
            empresas[empresa][mes]=random; //minimo + rand() % (maximo-minimo+1)
        }
    }

//extra
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    //voy a utilizar | y - para separar los valores, sin embargo los valores no son de igual tamaño
    //es decir 123 no tiene el mismo largo de caracteres que 1234 por lo tanto tengo que igualarlos de alguna forma

    float valor;
    int digitos, maxdig=0;
    int digitosPorNumero[4][12];
    for(int empresa=0;empresa<4;empresa++)
    {
        for(int mes=0;mes<12;mes++)
        {
            digitos=0;
            valor=empresas[empresa][mes];
            do
            {
                valor = valor/10;
                digitos++;
            }while(valor >= 1);
            if(maxdig < digitos) maxdig = digitos;
            digitosPorNumero[empresa][mes]=digitos;
        }
    }
    //una vez que tenemos nuestra mayor cantidad de digitos a cada valor que tenga una cantidad menor le debemos agregar espacios al imprimir

    for(int i=0;i<(maxdig+3)*12+9+12;i++) //+3(2 decimales y el .) *12 (meses) +9(Empresas|)+12(todas las | por mes)
            {
                printf("-");
            }
        printf("\n");

    int sumacion=0;
    for(int empresa=0;empresa<5;empresa++)
    {
        
        if(empresa==0)
        {
            printf("Emp./mes|");
            for(int i=1;i<13;i++)
            {
                printf("%d", i);
                if(i<10) sumacion=2;
                if(i>=10) sumacion=1;
                for(int a=0;a<maxdig+sumacion;a++)
                {
                    printf(" ");
                }
                printf("|");
            }
            printf("\n");
        }
        else
        {
            for(int i=0;i<(maxdig+3)*12+9+12;i++)
            {
                printf("-");
            }
            printf("\n");
            printf("%d       |", empresa);
            for(int mes=0;mes<12;mes++)
            {
                printf("%.2f", empresas[empresa-1][mes]);
                if(digitosPorNumero[empresa-1][mes] < maxdig)
                {
                    for(int i=0;i<maxdig-digitosPorNumero[empresa-1][mes];i++)
                    {
                        printf(" ");
                    }
                }
                printf("|");
            }
            printf("\n");
        }
    }
    for(int i=0;i<(maxdig+3)*12+9+12;i++) //+3(2 decimales y el .) *12 (meses) +9("Empresas|")+12(todas las "|" por mes)
        {
            printf("-");
        }
    printf("\n\n");
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    float totalPE, total=0, max=0, min=maximo, totalPEold=0;
    float totalPM[12]={0,0,0,0,0,0,0,0,0,0,0,0},promedios[4][6];
    int maxpos, minpos, maxmes, minmes, bimestres;

    for(int empresa=0;empresa<4;empresa++)
    {
        totalPE=0;
        bimestres=0;
        totalPEold=0;
        for(int mes=0;mes<12;mes++)
        {
            totalPE += empresas[empresa][mes];
            totalPM[mes]+=empresas[empresa][mes];
            total+=empresas[empresa][mes];
            //calculo de maximo
            if(max < empresas[empresa][mes])
            {
                max = empresas[empresa][mes];
                maxpos = empresa;
                maxmes = mes;
            }
            //calculo de minimo
            if(min > empresas[empresa][mes])
            {
                min = empresas[empresa][mes];
                minpos = empresa;
                minmes = mes;
            }
            //calculo de BIMESTRES
            if(mes %2 != 0)
            {
                promedios[empresa][bimestres]=(totalPE-totalPEold)/2;
                totalPEold = totalPE;
                bimestres++;
            }

        }
        printf("%d-Empresa ganancia anual: %.2f\n", empresa+1, totalPE);
    }
    printf("\n");
    printf("La empresa %d tuvo la mayor ganancia en el mes %d, con una ganancia de: %.2f\n", maxpos+1, maxmes+1, max);
    printf("La empresa %d tuvo la menor ganancia en el mes %d, con una ganancia de: %.2f\n\n", minpos+1, minmes+1, min);

    for(int mes=0;mes<12;mes++)
    {
        printf("Ganancia total del mes %d: %.2f\n", mes+1, totalPM[mes]);
    }
    printf("\n");

    float maxbim=0;
    int maxbimpos;
    for(int empresa=0;empresa<4;empresa++)
    {
        printf("Promedio bimestral empresa %d: ", empresa+1);
        for(int bimestre=0;bimestre<6;bimestre++)
        {
            printf("%.2f ", promedios[empresa][bimestre]);
            if(maxbim < promedios[empresa][bimestre])
            {
                maxbim=promedios[empresa][bimestre];
                maxbimpos=bimestre;
            }
        }
        printf("\n");
    }


    return 0;
}