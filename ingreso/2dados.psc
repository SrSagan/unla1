Algoritmo dosDados
	
	definir dado1 como entero;
	definir dado2 como entero;
	definir continuar como caracter;
	continuar <- "s";
	definir adivinanza como entero;
	definir sumaDeDados como entero;
	
	mientras(continuar <> "n")
	
	dado1 <- aleatorio(1,6);
	dado2 <- aleatorio(1,6);
	sumaDeDados <- dado1+dado2;
	escribir "Adivine la suma de los 2 dados";
	leer adivinanza;
	
	escribir "Dado 1: ", dado1;
	escribir "Dado 2: ", dado2;
	
	
	
	escribir "Valor total: ", sumaDeDados;
	si(sumaDeDados=adivinanza)
		escribir "Correcto!";
	SiNo
		escribir "Fallaste por ", abs(sumaDeDados - adivinanza);
	FinSi
	
	escribir "Desea tirar de nuevo? (S/N)";
	leer continuar;
	finmientras
	
FinAlgoritmo
