#include <stdio.h>
#include <stdlib.h>

#define PRIM "primero.txt"
#define SEG "segundo.txt"

int leernum(int pos, char file[]);

int main()
{
    int n1 = leernum(0, PRIM);
    int n2 = leernum(0, SEG);

    FILE * fp;
    fp = fopen("solucion.txt", "a");

    int p1=0;
    int p2=0;

    while(n1 != -100 && n2 != -100)
    {
        if(n1 % 2 == 0)
        {
            if(n2 % 2 == 0)
            {
                if(n1<n2)
                {
                    p1++;
                    fprintf(fp, "%d\n", n1);
                    n1 = leernum(p1, PRIM);
                }
                else if(n2<n1)
                {
                    p2++;
                    fprintf(fp, "%d\n", n2);
                    n2 = leernum(p2, SEG);
                }
                else{
                    p1++;
                    p2++;
                    fprintf(fp, "%d\n%d\n", n1, n2);
                    n1 = leernum(p1, PRIM);
                    n2 = leernum(p2, SEG);
                }
            }
            else{
                p2++;
                n2 = leernum(p2, SEG);
            }
        }
        else{
            p1++;
            n1 = leernum(p1, PRIM);
        }
    }
    while(n1 != -100)
    {
        p1++;
        fprintf(fp, "%d\n", n1);
        n1 = leernum(p1, PRIM);
    }
    while(n2 != -100)
    {
        p2++;
        fprintf(fp, "%d\n", n2);
        n2 = leernum(p2, PRIM);
    }
}

int leernum(int pos, char file[])
{
    FILE * fp;
    fp = fopen(file, "r");

    int num;
    char line[50];

    int posact=0;

    while(!feof(fp))
    {
        fgets(line, 50, fp);
        if(posact == pos)
        {
            sscanf(line, "%d\n", &num);
            return num;
        }
        posact++;
    }
    return -100;
}