#include <p16f628a.inc>

	LIST p=16f628a

RESULTADO EQU 0x20

	ORG 0

	movlw d'0' ;
	;movwf RESULTADO ;igualo resultado a 0 (RESULTADO = 0)
	;esto es lo mismo:
	clrf RESULTADO
	
	

INICIO
	addlw d'1' ;le agrego 1 al 10 en w
	movwf RESULTADO ;muevo el contenido de w a f (un registro)
	
	bsf 0x03, 5; cambiamos el bit Nº5 de STATUS a 1 y asi cambiamos al banco de memoria 01
	movwf 0xA0 ; movemos el contenido de w a un registro dentro del banco de memoria 2
	bcf 0x83, 5; volvemos el bit nº5 de STATUS a 0 para volver al banco de memoria 00
	GOTO INICIO ;va a inicio

	END