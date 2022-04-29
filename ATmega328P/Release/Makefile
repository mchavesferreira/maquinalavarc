###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = ATmega328P
COMPILER = "AVRASM (Proteus)"
TARGET = Release
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
ASMFLAGS=-fI -i"C:\Program Files (x86)\Proteus 8 Professional\Tools\AVRASM\appnotes\m328Pdef.inc"

## Processing Tools
ASM=avrasm2.exe
#  C:/Documents and Settings/Administrador/Meus documentos/exemplos_avr/maquina_lavar_C_funcoes_timer/maquina_lavar_C_funcoes_timer/ATmega328P/Release/Release.hex: TOOL=ASM
#     C:/Documents and Settings/Administrador/Meus documentos/exemplos_avr/maquina_lavar_C_funcoes_timer/maquina_lavar_C_funcoes_timer/ATmega328P/main.asm

# Build tree:
all:	Release

Release:	Release.hex
	cp "Release.hex" "../../ATmega328P.hex"

Release.hex:	../main.asm 
	$(ASM) $(ASMFLAGS)  -o "Release.hex" -l Release.lst "..\main.asm"

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Release.lst

# cleanup - delete all generated files
clean:	tidy
	rm -rf Release.hex

