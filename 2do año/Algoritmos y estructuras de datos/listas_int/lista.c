#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista{

    NodoPtr primero;

};

ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};

void insertarPrimero(ListaPtr lista, int dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};

void insertarUltimo(ListaPtr lista, int dato)
{
    NodoPtr a = lista->primero;

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
    }

    NodoPtr nD = crearNodo(dato, NULL);
    setSiguiente(a, nD);
}

void insertarPosicion(ListaPtr lista, int dato, int posicion)
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


int obtenerPrimero(ListaPtr lista)
{
    NodoPtr a = lista->primero;
    return getDato(a);
}

int obtenerUltimo(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
    }

    return getDato(a);
}

int obtenerPosicicon(ListaPtr lista, int posicion)
{
    NodoPtr a = lista->primero;
    if(posicion >= obtenerTamanio(lista))
    {
        return -1;
    }
    int counter=0;
    do
    {
        a = getSiguiente(a);
        counter++;

    }while(counter != posicion);

    return getDato(a);
}

int eliminarPrimero(ListaPtr lista)
{
    NodoPtr a = lista->primero;

    lista->primero = getSiguiente(a);
    int dato = getDato(a);
    free(a);

    return dato;
}

int eliminarUltimo(ListaPtr lista)
{
    NodoPtr a = lista->primero; //actual
    NodoPtr f; //final

    while(getSiguiente(a) != NULL)
    {
        a = getSiguiente(a);
        if(getSiguiente(a) != NULL) f=a;
    }
    setSiguiente(f, NULL); //hago el anterior el nuevo final

    int dato = getDato(a);
    free(a);

    return dato;
}
int eliminarposicicon(ListaPtr lista, int posicion)
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

    int dato = getDato(nodoSiguiente); //tomo el dato del eliminado
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
    printf("%d\n", a);

    return counter;
}

void ordenarLista(ListaPtr lista)
{
    NodoPtr a = lista->primero;
    NodoPtr b = lista->primero;

    /*
    int aux=0;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }*/
    int aux=0;
    while(a != NULL){

        b = a;
        while(b != NULL){

            if(getDato(a) > getDato(b))
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

ListaPtr ordenarListaCopia(ListaPtr lista)
{
    ListaPtr nL = duplicarLista(lista);

    ordenarLista(nL);

    return nL;

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

int buscarElemento(ListaPtr lista, int datoBuscado)
{
    NodoPtr a = lista->primero;
    int counter=0;
    do
    {
        a = getSiguiente(a);
        counter++;

    }while(getDato(a) != datoBuscado || getSiguiente(a) != NULL);

    if(a == NULL)
    {
        return -1; //no fue encontrado
    }

    return counter;
}

void insertarEnOrden(ListaPtr lista, int dato)//tarea, si la lista est� ordenada cada vez que
{
//se inserta se inserta en la posici�n que corresponda
    NodoPtr a = lista->primero;
    NodoPtr i = lista->primero; //dato igual
    int datoa = 0;
    int counter=0;
    do
    {
        datoa = getDato(a);
        if(getDato(a) < dato)
        {
            i = a; //me mantengo uno por atras del mayor
            counter++;
        }
        a = getSiguiente(a);
        datoa = getDato(a);

    }while(getDato(a) < dato );
    datoa = getDato(a);

    insertarPosicion(lista, dato, counter); //inserto el dato en la posicion por detras del mayor
}


void mostrarLista(ListaPtr lista){

    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodo(actual);
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
