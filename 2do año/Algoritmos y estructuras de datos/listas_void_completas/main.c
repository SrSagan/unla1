#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "lista.h"

int main()
{

    //------------------------------INT------------------------------//

    ListaPtr lista = crearLista();

    PersonaPtr santi = crearPersona(45421137, "Santi");
    PersonaPtr maxi = crearPersona(45985595, "Maxi");
    PersonaPtr abuelo = crearPersona(1, "Mirtha Legrand");

    insertarPrimero(lista, maxi);
    insertarUltimo(lista, santi);
    insertarUltimo(lista, abuelo);

    //mostrarListaInt(lista);
    mostrarListaGenerica(lista, &mostrarPersonaDatoPtr);


    ordenarListaInsercion(lista, compararPersonasDatoPtr);

    mostrarListaGenerica(lista, &mostrarPersonaDatoPtr);

    //------------------------------INT------------------------------//


    return 0;
}
