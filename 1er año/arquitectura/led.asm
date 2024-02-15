#include <p16f628a.inc>
	LIST p=16f628a
	
	ORG 0

	; primero habilitamos el pin RB0 como salida
	bsf 0x03, 5 ; pasamos al banco de memoria 01
	; Ponemos el bit nº5 de STATUS en 1
	
	bcf 0x86, 0 ; activamos RB0 como salida
	; ponemos el bit nº0 de TRISB en 0
	; esto marca que RB0 sea salida

	bcf 0x83, 5 ; volvemos al banco 00

INICIO

	bsf 0x06, 0 ; ponemos el pin RB0 en high
	; bcf 0x06, 0

	GOTO INICIO

	END