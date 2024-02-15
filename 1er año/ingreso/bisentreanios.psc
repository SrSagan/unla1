Algoritmo bisentreanios
	
	
	definir anio como entero;
	definir anio2 como entero;
	definir anioMed como entero;
	definir anioMen como entero;
	
	escribir "Diga 2 años";
	leer anio;
	leer anio2;
	
	si(anio < anio2)
		anioMen <- anio;
		anioMed <- anio2;
	SiNo
		anioMen <- anio2;
		anioMed <- anio;
	FinSi
	
	si(anio = anio2)
		escribir "Ambos años son iguales";
	FinSi
	
	
	mientras anioMen < anioMed Hacer
		anioMed <- anioMed-1;
		
		si!(anioMed mod 4 <> 0 o anioMed mod 100 = 0 & anioMed mod 400 <> 0)
			escribir "El año ", anioMed," es biciesto";
		FinSi
		
	FinMientras
	
	
	
	
	
FinAlgoritmo
