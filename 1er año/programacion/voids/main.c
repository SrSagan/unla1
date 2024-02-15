#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("VOID TEST\n");

    void * punteroloco;

    int numero = 100;

    punteroloco = &numero;

    printf("Numero: %d\n", *(int*)punteroloco);

    float pi= 3.14;

    punteroloco = &pi;

    printf("Numero: %.2f\n", *(float*)punteroloco);

    char texto[20]="Tomamate";

    punteroloco = &texto;

    printf("Texto: %s\n", (char*)punteroloco);

    return 0;
}
