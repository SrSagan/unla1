Algoritmo biciesto
	
	definir anio Como Entero;
	escribir "Escriba un año para averiguar";
	leer anio;
	
	si(anio mod 4 <> 0 o anio mod 100 = 0 & anio mod 400 <> 0)
		escribir "El año ", anio," no es biciesto";
	SiNo
		escribir "El año ", anio," es biciesto";
	FinSi
	
FinAlgoritmo
