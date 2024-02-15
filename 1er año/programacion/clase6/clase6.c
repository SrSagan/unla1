#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mainMenuShow();
int mainMenuOpciones(float v[], int tam, int opcion);
void ordenador(float v[], int tam, int orden);
void menuOp(int op, char descripcion[]);

int main()
{
    srand(time(NULL));
    float vector[10];

    while(1)
    {
        int op = mainMenuShow();
        int sal = mainMenuOpciones(vector, 10 ,op);

        if(sal == 0) return 0;
    }
    return 0;
}

int mainMenuShow()
{
    int opcion;
    printf("-----------MENU-----------\n");
    menuOp(1, "Crear vector");
    menuOp(2, "Mostrar vector");
    menuOp(3, "Organizar vector");
    menuOp(4, "Salir");
    printf("-----------MENU-----------\n");

    scanf("%d", &opcion);
    return opcion;

}

int mainMenuOpciones(float v[], int tam, int opcion)
{

    switch(opcion)
    {
        case 1: //crear vector
            for(int i=0;i<tam;i++)
            {
                v[i] = (float) (rand() % 1001) /100;
            }
            printf("Vector creado\n");
        break;

        case 2: //mostrar vector
            for(int i=0;i<tam;i++)
            {
                printf("%.2f ", v[i]);
            }
            printf("\n");
        break;

        case 3: //organizar vector
            int op;
            printf("-----------ORGANIZADOR-----------\n");
            menuOp(1, "Organizar de menor a mayor");
            menuOp(2, "Organizar de mayor a menor");
            printf("-----------ORGANIZADOR-----------\n");
            scanf("%d", &op);
            
            if(op==1)
            {
                ordenador(v, tam, 0);
                printf("Vector ordenado de menor a mayor\n");
            }
            else
            {
                ordenador(v, tam, 1);
                printf("Vector ordenado de mayor a menor\n");
            }
        break;

        case 4: //salir
            return 0;
    }
}

void ordenador(float v[], int tam, int orden)
{
    //orden = 0 menor a mayor
    //orden = 1 mayor a menor

    float aux;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam-1;j++)
        {
            if(orden==0)
            {
                if(v[j]>=v[j+1])
                {
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1]=aux;
                }
            }
            else
            {
                if(v[j]<=v[j+1])
                {
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1]=aux;
                }
            }
        }
    }
}

void menuOp(int op, char descripcion[])
{
    printf("(%d)- %s\n", op, descripcion);
}