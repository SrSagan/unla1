;---------------------------------------------------------------------------------------;
; Dal Degan Santiago - 45421137
; Ejercicio 2 - Punto 4 y 5
; En este programa se encienden los leds conectados a RB0, RB1, RB2, RB3 en orden con 
; un delay de 500ms entre ellos
; Luego se apagan en el orden contrario
;---------------------------------------------------------------------------------------;

; se configura el pic
#include <p16f628a.inc>
	LIST	P=16f628a

	org 0

	; configuramos los puertos
	bsf STATUS, RP0 ; cambiamos al segundo banco de memoria
	movlw b'11110000'
	movwf TRISB ; Ponemos desde RB0 hasta RB3 
	bcf STATUS, RP0 ; Volvemos al primer banco
	
INICIO
	call ENCENDER_ORDEN_CICLICO ; Empezamos el programa
	goto INICIO
	
	
ENCENDER_ORDEN
	; Prendemos los led en orden con 500ms de delay entre ellos
	bsf PORTB, 0 
	call DELAY500
	bsf PORTB, 1
	call DELAY500
	bsf PORTB, 2
	call DELAY500
	bsf PORTB, 3
	return

APAGAR_ORDEN
	; Apagamos los led en orden inverso con 500ms de delay entre ellos
	bcf PORTB, 3
	call DELAY500
	bcf PORTB, 2
	call DELAY500
	bcf PORTB, 1
	call DELAY500
	bcf PORTB, 0 
	return

ENCENDER_ORDEN_CICLICO
	call ENCENDER_ORDEN ; Encendemos los led en orden
	call DELAY500 ; Delay de 500ms
	call APAGAR_ORDEN ; Apagamos los led en orden
	call DELAY500
	return
	
DELAY500
	; estamos andando a 4Mhz
	; un ciclo de instruccion son 4 ciclos de relojs es decir 4/4 = 1Mhz
	; para calcular el tiempo hacemos 1/1Mhz = 1us
	; si queremos lograr un delay de 1s necesitamos
	; 500.000 ciclos de maquina
	; sin embargo como toma 3 ciclos de maquina hacer el proceso
	; dividimos 500.000/3 = 166.666,6666...
	; ya que no entra eso en un registro lo separaremos en 3
	; por cada valor del un registro el otro registro contara
	; regresivamente su valor
	; es decir reg1=10 reg=20, por cada 10 ciclos restando reg1
	; se restara uno de reg2
	; para saber los valores necesitamos reg1*reg2*reg3 = 166.666
	; raiz cubica 166.666 = 55.03
	
	movlw d'55'
	movwf 0x20
REG2
	movlw d'55'
	movwf 0x21
REG3
	movlw d'55'
	movwf 0x22
	
START
	decfsz 0x22, 1
	goto START
	decfsz 0x21, 1
	goto REG3
	decfsz 0x20, 1
	goto REG2
	clrwdt
	return

	end