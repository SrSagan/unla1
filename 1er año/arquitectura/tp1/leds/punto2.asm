;---------------------------------------------------------------------------------------;
; Dal Degan Santiago - 45421137
; Ejercicio 2 - Punto 2
; En este programa se encienden los leds conectados a RB0, RB1, RB2, RB3 espera un segundo y los apaga
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
	call ENCENDER_POR_SEGUNDO ; Encender los leds cada un segundo
	goto INICIO ; repetimos

ENCENDER_TODOS
	movlw b'00001111' ; ponemos el 1 en los ultimos 4 bits de PORTB
	movwf PORTB
	return

ENCENDER_POR_SEGUNDO 
	call ENCENDER_TODOS ; Encendemos todos los leds
	call DELAY1s ; delay de un segundo
	clrf PORTB ; apalagamos los leds
	call DELAY1s ; delay de un segundo
	clrwdt ; limpiamos el watchdog
	return  

DELAY1s
	; estamos andando a 4Mhz
	; un ciclo de instruccion son 4 ciclos de relojs es decir 4/4 = 1Mhz
	; para calcular el tiempo hacemos 1/1Mhz = 1us
	; si queremos lograr un delay de 1s necesitamos
	; 1.000.000 ciclos de maquina
	; sin embargo como toma 3 ciclos de maquina hacer el proceso
	; dividimos 1.000.000/3 = 333.333,333...
	; ya que no entra eso en un registro lo separaremos en 3
	; por cada valor del un registro el otro registro contara
	; regresivamente su valor
	; es decir reg1=10 reg=20, por cada 10 ciclos restando reg1
	; se restara uno de reg2
	; para saber los valores necesitamos reg1*reg2*reg3 = 333.333
	; raiz cubica 333.333 = 69.3
	
	movlw d'69'
	movwf 0x20
REG2
	movlw d'69'
	movwf 0x21
REG3
	movlw d'70'
	movwf 0x22
	
START
	decfsz 0x22, 1
	goto START
	decfsz 0x21, 1
	goto REG3
	decfsz 0x20, 1
	goto REG2
	return

	end