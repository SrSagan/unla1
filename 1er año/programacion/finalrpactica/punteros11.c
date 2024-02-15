#include <stdio.h>
#include <stdlib.h>


//void suma_dos(int *x, int *y, int *z);

/*int main()
{
    int *punt,i;

    int x[5] = {1,2,3,4,5}; 
    punt = x; //iguala el puntero a la array

    *(punt+2) = 9; //dice que el puntero + 2 posiciones sea igual a 9, por lo tanto la posicion [2] del punt sera 9
    *(x+3) = 7; // lo mismo pero con la posicion [3] dira 7

    punt[1]=11; //lo mismo pero con la posicion [1] sera 11

    for(i=0;i<5;i++)
    {
        printf("%d,", *(punt+i)); //que imprime??
    } //imprimira 1,11,9,7,5
    //tenia razon :DDDDDdd
    return 0;
}

int main()
{

    int x,y,z;

    x=3;
    y=10;
    z=15; //creamos y ponermos numeros en 3 variables int

    suma_dos(&x, &y, &z); //envia la direccion de memoria de los int

    printf("%d %d %d", x, y, z); //ya que modificamos directamente la posicion de memoria en la funcion, tambien se modifico lo que esta guardado en las variables
    //nuevamente B))
    return 0;
}

void suma_dos(int *x, int *y, int *z) //recive un puntero
{
    *x=*x+2; //lo que esta guardado en ese puntero va a ser igual a lo que este guardado mas 2
    *y=*y+2;
    *z=*z+2;
}*/