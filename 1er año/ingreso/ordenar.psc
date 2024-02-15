Algoritmo ordenar
	
	definir a,b Como Entero;
	definir buffer como entero;
	
	escribir "Escriba sus 2 numeros a ordenar";
	leer a;
	leer b;
	
	si(a = b)
		escribir a, " y ", b, " son iguales";
	sino
		si(a>b)
			buffer <- a;
			a  <- b;
			b <- buffer;
		FinSi
		escribir b, " es mayor que ", a;
	FinSi
	
FinAlgoritmo
