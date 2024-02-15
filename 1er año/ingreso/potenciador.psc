Algoritmo potenciador
	
	definir base Como Entero;
	definir exponente Como Entero;
	definir resultado como entero;
	definir i como entero;
	
	escribir "Escriba su base";
	leer base;
	escribir "Escriba su exponente";
	leer exponente;
	resultado <- base;
	
	
	para i desde 2 hasta exponente Hacer
		resultado <- resultado*base;
		
	FinPara
	escribir resultado;
	
FinAlgoritmo
