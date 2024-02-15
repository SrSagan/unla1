Algoritmo tresxdos
	
	definir articulo Como Entero;
	articulo <- 30;
	definir cantidad como Entero;
	definir precioOrg como Real;
	definir precio como Real;
	
	escribir "Elegir cantidad de articulos";
	leer cantidad;
	
	precioOrg <- cantidad*articulo;
	
	si(3 <= cantidad)
		definir noAplicable como entero;
		noAplicable <- cantidad %3;
		
		precio <- (precioOrg-noAplicable*articulo)-(PrecioOrg-noAplicable*articulo)/3;
		precio <- precio+noAplicable*articulo;
	SiNo
		precio <- articulo*cantidad;
	FinSi
	
	escribir "Precio c/u: ", articulo;
	escribir "Total: ", precioOrg;
	escribir "Total (oferta 3X2): ", precio;
	
FinAlgoritmo