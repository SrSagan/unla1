#include <p16f628a.inc>
	LIST p=16f628a
	
	ORG 0
P	EQU d'123' ;declaro 3 numeros como "variables
q	EQU d'12'
t	EQU d'10'

	movlw P ;muevo p a W
	movwf 0x20 ;muevo w a f (0x20)
	
	movlw q ; muevo q a w
	addwf 0x20, 1 ; sumo w a f (0x20) y lo guardo en f
	movlw t ; muevo t a w
	subwf 0x20, 1 ; sumo w a f (0x20) y lo guardo en f

	END