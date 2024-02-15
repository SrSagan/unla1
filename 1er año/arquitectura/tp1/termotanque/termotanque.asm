;------------------------------------------------------------------------------------;
; Dal Degan Santiago - 45421137 
; Ejercicio 1 - Termotanque
; En este programa controla un termotanque utilizando el PIC16F628A
;-----------------------------------------------------------------------------------;

; se configura el pic
#include <p16f628a.inc>
	LIST	P=16f628a

	org 0
	
; declaracion de variables

tmax	equ d'45'
maxagua	equ d'110'
minagua	equ d'50'
tagua	equ 0x20
cagua	equ 0x21
bomba	equ 0
bled	equ 1
tled	equ 2
resis	equ 3
resled	equ 4
maxled	equ 5
canilla equ 6
; 0x20-0x21 utilizado

;-----------SALIDAS-----------
	bsf STATUS, 5
	clrf TRISB ; Configuramos los pines B como salida
	bcf STATUS, 5
;-----------SALIDAS-----------

;-----------VARIABLES PRUEBA-----------
	movlw d'30'
	movwf tagua
	movlw d'100'
	movwf cagua
	movlw 0x00
	movwf PORTB ; Limpiamos las salias
;-----------VARIABLES PRUEBA-----------

;-----------INICIO CICLO-----------
INICIO
	
	clrwdt ; Limpiamos el watchdog
	movlw maxagua ; Movemos el nivel maximo de agua a w
	subwf cagua, 0 ; Restamos 110 - cantidad de agua
	
	; if
	btfss STATUS, 2 ; Checkeamos si el bit de STATUS en la pos 2 es 0
	
	; false
	goto PRENDER_BOMBA ; si el bit es 0 (es decir no hay suficiente agua), prendemos la bomba
	
	; true
	goto CHECK_TEMP
;-----------INICIO CICLO-----------

;-----------PRENDER BOMBA-----------
PRENDER_BOMBA
	bsf PORTB, bomba ; Prendemos la bomba
	bsf PORTB, bled ; Prendemos el led marcador de la bomba

PRENDER_BOMBA_LOOP
	incf cagua, 1 ; Simulamos el agua subiendo
	movlw maxagua
	subwf cagua, 0
	
	; if
	btfss STATUS, 2 ; checkeamos nuevamente el nivel del agua
	
	; false
	goto PRENDER_BOMBA_LOOP ; Si sigue bajo repetimos el loop
	
	; true
	bcf PORTB, bomba ; Apagamos la bomba si el agua llego al nivel correcto
	bcf PORTB, bled ; Apagamos el led de la bomba
	bsf PORTB, maxled ; Prendemos el led de termotanque lleno
	goto CHECK_TEMP
;-----------PRENDER BOMBA-----------

;-----------CHECK TEMPERATURA-----------
CHECK_TEMP
	movlw tmax
	subwf tagua, 0
	
	; if
	btfss STATUS, 2 ; Checkeamos si la temperatura del agua es la maxima
	
	; false
	goto PRENDER_RES ; Si no lo es prendemos la resistencia
	
	; true
	bsf PORTB, tled ; Prendemos el led de temperatuar alcanzada
	goto ABRIR_CANILLA ; Si lo es abrimos la canilla
;-----------CHECK TEMPERATURA-----------

;-----------PRENDER RESISTENCIA-----------
PRENDER_RES
	bsf PORTB, resis

PRENDER_RES_LOOP
	incf tagua, 1 ; Simulamos el aumento de temperatura del agua	
	movlw tmax
	subwf tagua, 0

	call DELAY250 ; Hacemos titilar el led
	bsf PORTB, resled
	call DELAY250
	bcf PORTB, resled
	
	; if
	btfss STATUS, 2 ; Checkeamos la temperatura del agua
	
	; false
	goto PRENDER_RES_LOOP ; Si no se alcanzo la temperatura repetimos
	
	; true
	; Si la temperatura fue alcanzada apagamos la resistencia y el led
	bcf PORTB, resis
	bcf PORTB, resled
	bsf PORTB, tled ; Prendemos el led de temperatuar alcanzada
	goto ABRIR_CANILLA
;-----------PRENDER RESISTENCIA-----------

;-----------ABRIR CANILLA-----------
ABRIR_CANILLA
	call DELAY1 ; Delay de 1 segundo antes de abrir la canilla
	
	bsf PORTB, canilla ; Abrimos la canilla

ABRIR_CANILLA_LOOP
	decf cagua, 1
	movlw minagua
	subwf cagua, 0

	btfss STATUS, 2 ; Checkeamos si el agua llego a los 50 litros
	;false
	goto ABRIR_CANILLA_LOOP

	;true
	call DELAY1
	call DELAY1
	bcf PORTB, canilla
	bcf PORTB, tled
	bcf PORTB, maxled
	goto INICIO
;-----------ABRIR CANILLA-----------

;-----------DELAY 1s-----------
DELAY1
	; estamos andando a 4Mhz
	; un ciclo de instruccion son 4 ciclos de relojs es decir 4/4 = 1Mhz
	; para calcular el tiempo hacemos 1/1Mhz = 1us
	; si queremos lograr un delay de 1s necesitamos
	; 1M ciclos de maquina
	; sin embargo como toma 3 ciclos de maquina hacer el proceso
	; dividimos 1M/3 = 333.333,33...
	; ya que no entra eso en un registro lo separaremos en 3
	; por cada valor del un registro el otro registro contara
	; regresivamente su valor
	; es decir reg1=10 reg=20, por cada 10 ciclos restando reg1
	; se restara uno de reg2
	; para saber los valores necesitamos reg1*reg2*reg3 = 333.333
	; raiz cubica 333.333 = 69.3
	
	movlw d'69'
	movwf 0x24
REG2
	movlw d'69'
	movwf 0x25
REG3
	movlw d'70' ; ya que da un valor con coma a la 3ra le sumo uno
	movwf 0x26 ; no es un delay exacto asi que no deberia importar
	
START
	decfsz 0x26, 1
	goto START
	decfsz 0x25, 1
	goto REG3
	decfsz 0x24, 1
	goto REG2
	clrwdt
	return
;-----------DELAY 1s-----------

;-----------DELAY 250ms-----------
DELAY250
	; La logica es la misma pero para 250ms
	
	movlw d'43'
	movwf 0x24
REG5
	movlw d'43'
	movwf 0x25
REG4
	movlw d'44'
	movwf 0x26
	
START1
	decfsz 0x26, 1
	goto START
	decfsz 0x25, 1
	goto REG5
	decfsz 0x24, 1
	goto REG4
	clrwdt
	return
;-----------DELAY 500ms-----------
	end