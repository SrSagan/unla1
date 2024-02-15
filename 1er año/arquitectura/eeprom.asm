#include <p16f628a.inc>
	LIST p=16f628a
	
	ORG 0

	bsf 0x03, 5 ; cambiamos el bit 5 de status

INICIO
;guardado en memoria EEPROM
;todos los registros relacionados a eeprom estan en el banco 01
;cambiamos al banco 01
	bcf 0x8B, 7 ; ponemos el bit 7 de 8B (INTCON) en 0
	;esto es para desacrivar las interrupciones momentaneamente

	;vamos a guardar un 132 en la eeprom
	movlw d'132' ; movemos el literal 132 a w
	movwf 0x9A ; movemos w al registro 9A (EEDATA)
	movlw 0x01 ; ponemos w en 1
	movwf 0x9B ; movemos el 0 de w a la posicion 9B (EEADR)
	
	bsf 0x9C, 2 ; ponemos en 1 el bit nº2 del registro 9C (EECON1)
	;esto permite escribir cosas en la eeprom
	
	; magia negra que me dijo el datasheet
	movlw 0x55
	movwf 0x9D
	movlw 0xAA
	movwf 0x9D
	
	bsf 0x9C, 1 ; ponemos en 1 el bit nº1 del registro 9C (EECON1)
	;este bit en 1 escribe lo que este guardado en EEDATA
	;en la posicion EEADR

	bsf 0x8B, 7 ; reactivamos las interrupciones
	nop
	GOTO INICIO

	END