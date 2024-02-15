#ifndef LISTASENC_H_INCLUDED
#define LISTASENC_H_INCLUDED

#define TRUE 1
#define FALSE 0


#define OK 1
#define ESTRUCTURA_NO_INICIALIZADA -1
#define ESTRUCTURA_VACIA -2
#define INDICE_INVALIDO -3
#define PARAMETRO_INVALIDO -4

// Declaramos la estructura del nodo, prox es un puntero al siguiente nodo
struct NodoE;

typedef struct NodoE *Nodo;



struct ListaEncE;

typedef struct ListaEncE * ListaEnc;


///Constructor
ListaEnc crearLista();

///Destructor
int liberarLista(ListaEnc lista);
//1 si esta vacia ---- 0 tiene algun elemento
int estaVacia(ListaEnc lista);



int insertarInicio(ListaEnc lista, int item); //agregar elementos al inicio
int insertar(ListaEnc lista, int item, int pos); //agregar un elemetno en cualquier posi
int insertarFin(ListaEnc lista, int item);//agregar elementos al final

int removerInicio(ListaEnc lista, int* item);
int remover(ListaEnc lista, int* item, int pos);
int removerFin(ListaEnc lista, int* item);

int obtenerElemento(ListaEnc lista, int* item, int pos);
int obtenerTamanio(ListaEnc lista, int* tam);


void imprimir(ListaEnc lista);







#endif // LISTASENC_H_INCLUDED
