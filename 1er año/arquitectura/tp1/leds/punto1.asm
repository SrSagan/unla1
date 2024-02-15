;---------------------------------------------------------------------------------------;
; Dal Degan Santiago - 45421137
; Ejercicio 2 - Punto 1
; En este programa se encienden los leds conectados a RB0, RB1, RB2, RB3
;---------------------------------------------------------------------------------------;

; se configura el pic
#include <p16f628a.inc>
	LIST	P=16f628a

	org 0

	; configuramos los puertos
	bsf STATUS, RP0 ; cambiamos al segundo banco de memoria
	movlw b'11110000'
	movwf TRISB ; ponemos desde RB0 hasta RB3 
	bcf STATUS, RP0 ; volvemos al primer banco
	
INICIO
	call ENCENDER_TODOS ; encendemos todos los leds
	clrwdt ; limpiamos el watchdog
	goto INICIO ; repetimos
	
	
ENCENDER_TODOS
	movlw b'00001111' ; ponemos el 1 en los ultimos 4 bits de PORTB
	movwf PORTB
	return
	
	end