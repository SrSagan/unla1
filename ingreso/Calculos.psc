Algoritmo Calculos
	
	//definimos las variables
	definir a Como Entero;
	definir b Como Entero;
	
	//se toman ambas variables del usuario
	escribir "Escriba A:";
	leer a;
	
	escribir "Escriba B:";
	leer b;
	
	//para evitar utilizar otra variable como total se escribe directamente a+b*
	//se escriben todos los resultados
	escribir a ,"+", b,"=", a+b;	
	escribir a, "-", b, "=", a-b;
	escribir a, "*", b, "=", a*b;
	escribir a, "/", b, "=", a/b;
	
	//*una variable no guarda nada mas que un dato, si una variable "total" guarda a+b es decir total=a+b. Por lo tanto en el mismo lugar que usariamos la variable total se podria usar a+b sin causar ninguna diferencia en el codigo
	//entonces por que se usan variables?
	//pues por varios motivos, por ejemplo a y b son variables ingresadas por el usuario, por lo tanto DESCONOCIDA, otro motivo es evitar la repeticion y ayudar la comprension. En este codigo cada calculo se utiliza una sola vez
	//por lo tanto crear variables para estos es una perdida de tiempo y espacio
	
FinAlgoritmo
