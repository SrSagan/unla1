Algoritmo catetonometro
	
	//calcular hipotenusa, sqrt(cateto1² + cateto2²) = hipotenusa
	//el area b*a/2 (base * altura / 2)
	//el perimettro cateto1 + cateto2 + hipotenusa
	
	definir cateto1 como entero;
	definir cateto2 como entero;
	
	escribir "Escriba el cateto 1";
	leer cateto1;
	escribir "Escriba el cateto 2";
	leer cateto2;
	
	definir hipotenusa como Real;
	
	hipotenusa <- raiz(cateto1^2 + cateto2^2);
	
	escribir "La hipotenusa es igual a: ", hipotenusa;
	
	escribir "El area del triangulo es: ", (cateto1*cateto2)/2;
	escribir "El perimetro del triangulo es: ", cateto1+cateto2+hipotenusa;
	
	
	
FinAlgoritmo
