// punto 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int calcularEdad(int nacimiento, int anioHoy);
float calcularIndiceDeMasaCorporal(float altura, float peso);
void dibujarTriangulo(int base, int altura);
void calcularHipotenusa(float cateto1, float cateto2);
int cantidadDeVecesQueApareceLaLetra(char letra, char oracion[100]);
int pedirEnteroPorTeclado();
float pedirFloatPorTeclado();
void cargarVector(); //definir un vector global solo por ahora
void mostrarVector();
int maximoVector();
int minimoVector();
int cantidadNumerosRepetidosEnElVector();
void cargarVectorConAleatoriosSinRepetir(int tam, int mini,int maxi);
int contiene(int v[], int tam ,int a);

int vector[20];

int main()
{
    char texto[100] = "hola cual es el horario de hoy?";


    printf("Edad: %d\n", calcularEdad(2004, 2023));
    printf("Indice masa corporal: %f\n", calcularIndiceDeMasaCorporal(1.80,99));
    calcularHipotenusa(1, 1);
    printf("La letra h aparece %d veces\n", cantidadDeVecesQueApareceLaLetra('h', texto));
    printf("%d\n", pedirEnteroPorTeclado());
    printf("%f\n", pedirFloatPorTeclado());
    cargarVector(); //definir un vector global solo por ahora
    mostrarVector();
    printf("El maximo del vector es: %d\n", maximoVector());
    printf("El minimo del vector es: %d\n", minimoVector());
    printf("Se repiten %d numeros\n", cantidadNumerosRepetidosEnElVector());
    cargarVectorConAleatoriosSinRepetir(20, 0, 100);
    mostrarVector();
    printf("Se repiten %d numeros\n", cantidadNumerosRepetidosEnElVector());

    return 0;
}

int calcularEdad(int nacimiento, int anioHoy)
{
    return nacimiento-anioHoy;
}
float calcularIndiceDeMasaCorporal(float altura, float peso)
{
    return altura/peso*peso;
}
void dibujarTriangulo(int base, int altura)
{

}
void calcularHipotenusa(float cateto1, float cateto2)
{
    float hipotenusa = sqrtf(cateto1*cateto1+cateto2*cateto2);
    printf("La hipotenusa es: %f\n", hipotenusa);
}
int cantidadDeVecesQueApareceLaLetra(char letra, char oracion[100])
{
    int contador=0;
    for(int c=0;c<strlen(oracion);c++)
    {
        if(oracion[c] == letra) contador++;
    }
    return contador;
}
int pedirEnteroPorTeclado()
{
    int entero;
    printf("Ingrese un entero\n");
    scanf("%d", &entero);
    return entero;
}
float pedirFloatPorTeclado()
{
    float flotante;
    printf("Ingrese un valor flotante\n");
    scanf("%f", &flotante);
    return flotante;
}
void cargarVector()
{
    srand(time(NULL));
    for(int i=0;i<20;i++)
    {
        vector[i] = rand()%100+1;
    }
}
void mostrarVector()
{
    for(int i=0;i<20;i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}
int maximoVector()
{
    int max;
    for(int i=0;i<20;i++)
    {
        if(!i) max=vector[i];
        if(max < vector[i]) max = vector[i];
    }
    return max;
}
int minimoVector()
{
    int min;
    for(int i=0;i<20;i++)
    {
        if(!i) min=vector[i];
        if(min > vector[i]) min = vector[i];
    }
    return min;
}
int cantidadNumerosRepetidosEnElVector()
{
    int cantidad = 0;
    for(int i=0;i<20;i++)
    {
        for(int x=0;x<20;x++)
        {
            if(vector[i] == vector[x]) cantidad++;
        }
    }
    return (cantidad-20)/2;
}

void cargarVectorConAleatoriosSinRepetir(int tam, int mini,int maxi)
{
    srand(time(NULL));
    int random;
    for(int i=0;i<tam;i++)
    {
        random = mini+rand()%maxi+1;
        if(!contiene(vector, tam, random))
        {
            vector[i] = random;
        }
        else i--;
        
    }

}

int contiene(int v[], int tam ,int a)
{
    for(int i=0;i<tam;i++)
    {
        if(v[i] == a)
        {
            return 1;
        }
    }
    return 0;
}