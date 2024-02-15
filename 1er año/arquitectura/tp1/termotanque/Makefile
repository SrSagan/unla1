# MPLAB IDE generated this makefile for use with GNU make.
# Project: termotanque.mcp
# Date: Tue Oct 24 20:15:30 2023

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

termotanque.cof : termotanque.o
	$(LD) /p16F628A "termotanque.o" /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"termotanque.cof" /M"termotanque.map" /W

termotanque.o : termotanque.asm C:/Program\ Files\ (x86)/Microchip/MPASM\ Suite/p16f628a.inc
	$(AS) /q /p16F628A "termotanque.asm" /l"termotanque.lst" /e"termotanque.err" /o"termotanque.o" /d__DEBUG=1

clean : 
	$(RM) "termotanque.o" "termotanque.err" "termotanque.lst" "termotanque.cof" "termotanque.hex"

