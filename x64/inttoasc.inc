;***********************************************************************************
; Autor: Alexandre Perissinotto
; Data: 02/08/2020 02:34
; obbiettivo: macro per convertire numeri interi in caratteri ascii
; parametri : 1-numero intero
;             2-indirizzo spazio di lavoro
;             3-dimensione del spazio di lavoro
;***********************************************************************************

%macro inttoasc 3
	; prende i dati
	mov rax, %1	; numero intero
	mov r8, %2	; indirizzo spazio di lavoro
	mov r9, %3	; dimensione del spazio di lavoro

	mov rbx, 0x0a	; il divisore
	add r8, r9	; posizione alla fine del spazio di lavoro
	mov r15, 0x0	; codice di ritorno = 0 (ok)

_laccio_1:
	mov rdx, 0x0	; pulire il register
	div rbx		; divide rax / rdx ; rax <- q ; rdx <- r
	add rdx, 0x30	; somma 48d-30h
	mov [r9], dl	; passa al spazio di lavoro
	dec r8          ; sottrae uno del indirizzo
	dec r9		; sottrae uno del dimensione
	cmp rax, 0x0	; è finito il numero?
	je _fine	; sì, finisce
	cmp r8, 0x0	; è finito il spazio di lavoro?
	jne _laccio_1	; no, ritorna alle laccio
	mov r15,0x01	; sì, finisce con il codice di errore
_fine:
%endmacro
