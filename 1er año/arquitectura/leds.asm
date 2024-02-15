#include <p16f628a.inc>

	;LIST p=p16f628a
	org 0
	
	
	;CALL ENCENDER_TODOS
	movlw d'10'
	movwf 0x20
	CALL ENCENDER_RETARDO



;encender toos los leds
;ENCENDER_TODOS
;	bsf STATUS, RP0
;	movlw b'11110000'
;	movwf TRISB
;	
;	bcf STATUS, RP0
;	
;	bsf PORTB, 0
;	bsf PORTB, 1
;	bsf PORTB, 2
;	bsf PORTB, 3
;	RETURN

ENCENDER_RETARDO
	;bsf STATUS, RP0
	;bcf OPTION_REG, 5

	decfsz 0x20, 1
	GOTO $-1
	RETURN 

	end