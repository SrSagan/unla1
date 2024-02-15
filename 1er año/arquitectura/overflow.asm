#include <p16f628a.inc>
	LIST p=16f628a
	
	ORG 0

	movlw d'254'
	movwf 0x20
	movlw d'5'

loop:
	addwf 0x20, 1
	

	goto loop

	end