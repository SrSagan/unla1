#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "nodo.h"

struct Lista{

    NodoPtr primero;

};

ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};

void insertarPrimero(ListaPtr lista, datoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;
};

void insertarUltimo(ListaPtr lista, datoPtr dato)
{
    NodoPtr a = lista->primero;
    NodoPtr nD = crearNodo(dato, NULL);

    if(lista->primero == NULL)
    {
        lista->primero = nD;
        return;
    }

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
    }
    
    setSiguiente(a, nD);
}

void insertarPosicion(ListaPtr lista, datoPtr dato, int posicion)
{
    NodoPtr a = lista->primero;

    if(posicion == 0) insertarPrimero(lista, dato); //si es el primero

    else
    {
        int counter = 0;
        do
        {
            a = getSiguiente(a);
            counter++;

        } while (counter != posicion-1); //busco el anterior a la posicion

        NodoPtr nodoSiguiente = getSiguiente(a);  //tomo el siguente a la posicion

        NodoPtr nodoNuevo = crearNodo(dato, nodoSiguiente); //creo mi nuevo nodo y lo apunto al siguiente
        setSiguiente(a, nodoNuevo); //el nodo anterior lo apunto al nuevo nodo
    }

}


datoPtr obtenerPrimero(ListaPtr lista)
{
    NodoPtr a = lista->primero;
    return getDato(a);
}

datoPtr obtenerUltimo(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
    }

    return getDato(a);
}

datoPtr obtenerPosicicon(ListaPtr lista, int posicion)
{
    NodoPtr a = lista->primero;
    if(posicion >= obtenerTamanio(lista))
    {
        return obtenerUltimo(lista);
    }
    int counter=0;
    do
    {
        a = getSiguiente(a);
        counter++;

    }while(counter != posicion);

    return getDato(a);
}

datoPtr eliminarPrimero(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    lista->primero = getSiguiente(a);
    datoPtr dato = getDato(a);
    free(a);

    return dato;
}

datoPtr eliminarUltimo(ListaPtr lista)
{
    NodoPtr a = lista->primero; //actual
    NodoPtr f; //final

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
        if(getSiguiente(a) != NULL) f=a;
    }
    setSiguiente(f, NULL); //hago el anterior el nuevo final

    datoPtr dato = getDato(a);
    free(a);

    return dato;
}
datoPtr eliminarposicicon(ListaPtr lista, int posicion)
{
    NodoPtr a = lista->primero;

    int counter = 0;

    do
    {
        a = getSiguiente(a);
        counter++;

    } while (counter != posicion-1); //busco el anterior a la posicion

    NodoPtr nodoSiguiente = getSiguiente(a);  //tomo el siguente a la posicion es decir el que queremos eliminar

    setSiguiente(a, getSiguiente(nodoSiguiente)); //al anterior lo apunto al siguente del que queremos eliminar

    datoPtr dato = getDato(nodoSiguiente); //tomo el dato del eliminado
    free (nodoSiguiente);

    return dato;
}

int obtenerTamanio(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    int counter = 1;

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
        counter++;
    }

    return counter;
}

ListaPtr duplicarLista(ListaPtr lista)
{
    //la nueva lista no puede utilizar los mismo nodos si no seria inutil
    ListaPtr nL = crearLista();
    NodoPtr a = lista->primero;

    NodoPtr copia = crearNodo(getDato(a), NULL);
    nL->primero = copia;

    a = getSiguiente(a);

    while(a != NULL)
    {
       insertarUltimo(nL, getDato(a));
       a = getSiguiente(a);
    }

    return nL;
}

int buscarElementoInt(ListaPtr lista, datoPtr datoBuscado)
{
    NodoPtr a = lista->primero;
    int counter=0;
    int dato, datobusc;

    datobusc = *(int*) datoBuscado;

    dato = *(int*) getDato(a);
    do
    {
        a = getSiguiente(a);
        dato = *(int*) getDato(a);
        counter++;

    }while(dato != datobusc && getSiguiente(a) != NULL);

    if(a == NULL)
    {
        return -1; //no fue encontrado
    }

    return counter;
}


void mostrarListaInt(ListaPtr lista){

    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;
    int numero=0;

    while (actual!=NULL){

        numero = getDato(actual);
        printf("%d ", numero);
        actual = getSiguiente(actual);
    }
    printf("\n\n");

};


void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(datoPtr)){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        //mostrarFloat(actual);
        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");

};


void liberarLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        actual = getSiguiente(actual);
        free(actual);
    };
}

/*
int busquedaBinaria(int *v, int tam, int num)
{
    int sup =0, inf=0, centro=0;

    sup = tam-1;
    while(inf <= sup)
    {
        centro = (sup+inf)/2; // [@] @ @ @ ->@<- @ @ @ (@) segunda vuelta: [@] ->@<- @ (@) | @ @ @ @ @

        if(v[centro] == num) return centro;
        else
        {
            if(num > v[centro]) inf = centro +1;// @ @ @ @ ->@<- [@] @ @ (@) //requiere que este ordenado!!
            else sup = centro-1; // [@] @ @ (@) ->@<- @ @ @ @
        }
    }

    return -1;
}
*/

void ordenarListaBurbuja(ListaPtr lista, int(comparar)(datoPtr, datoPtr))
{
    NodoPtr a = lista->primero;
    NodoPtr b = lista->primero;

    datoPtr aux;
    while(a != NULL){

        b = a;
        while(b != NULL){

            //if(getDato(a) > getDato(b))
            if(comparar(a, b))
            {
                aux = getDato(a);
                setDato(a, getDato(b));
                setDato(b, aux);
            }
            b = getSiguiente(b);

        }

        a = getSiguiente(a);
    }

}

void ordenarListaSeleccion(ListaPtr lista, int(comparar)(datoPtr, datoPtr))
{
    NodoPtr a = lista->primero;
    NodoPtr b = lista->primero;
    datoPtr aux;
    NodoPtr min = lista->primero;

    while(a != NULL){

        min = a;
        while(b != NULL){

            //if(getDato(a) > getDato(b))
            if(comparar(min, b))
            {
                min = b;
            }
            b = getSiguiente(b);

        }
        aux = getDato(a);
        setDato(a, getDato(min));
        setDato(min, aux);

        a = getSiguiente(a);
    }
}

void ordenarListaInsercion(ListaPtr lista, int(comparar)(datoPtr, datoPtr))
{
    /*NodoPtr aux;
    NodoPtr a = getSiguiente(lista->primero);
    NodoPtr izq = lista->primero;

    while(a != NULL)
    {
        aux = a;

        while(comparar(izq, aux))
        {
            setDato(getSiguiente(izq), getDato(izq));
            izq = getSiguiente(aux);
        }
        setDato(getSiguiente(aux), getDato(izq));

        a = getSiguiente(a);
    }*/
}

int busquedaSecuencial(ListaPtr lista, datoPtr datoBuscado)
{
    NodoPtr a = lista->primero;
    int counter=0;
    datoPtr dato;


    dato = getDato(a);
    do
    {
        a = getSiguiente(a);
        dato = getDato(a);
        counter++;

    }while(dato != datoBuscado && getSiguiente(a) != NULL);

    if(a == NULL)
    {
        return -1; //no fue encontrado
    }

    return counter;
}

int busquedaBinaria(ListaPtr lista, datoPtr datoBuscado)
{
    int sup =0, inf=0, centro=0;
    int tam = obtenerTamanio(lista);

    sup = tam-1;

    while(inf <= sup)
    {
        centro = (sup+inf)/2; // [@] @ @ @ ->@<- @ @ @ (@) segunda vuelta: [@] ->@<- @ (@) | @ @ @ @ @

        if(obtenerPosicicon(lista, centro) == datoBuscado) return centro;
        else
        {
            if(datoBuscado > obtenerPosicicon(lista, centro)) inf = centro +1;// @ @ @ @ ->@<- [@] @ @ (@) //requiere que este ordenado!!
            else sup = centro-1; // [@] @ @ (@) ->@<- @ @ @ @
        }
    }

    return -1;
}