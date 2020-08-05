;***********************************************************************************
; Autor: Alexandre Perissinotto
; Data: 02/08/2020 02:34
; obbiettivo: macro per convertire numeri caratteri ascii in intero
; parametri : 1-numero ascii
;***********************************************************************************

%macro asctoint 2
	; prende i dati
	mov r8, %1	; indirizzo del numero ascii
	mov r9, %2

; scopri l'ultimo byte ascii, quando = 0x0a
	mov rbx, r8	; copia il indirizzo del numero per confrontare
	mov rcx, 0

_attlp01:
	mov cl, [rbx]
	inc rbx
	cmp cl, 0x0a
	jne _attlp01

	sub rbx, 2
	mov rdx, 0
	mov r10, 1
	mov r11, 0

_attlp02:
	mov cl, [rbx]
	sub cl, 0x30
	mov al, cl
	mul r10
	add r11,rax
	mov rax, r10
	mov r10, 0x0a
	mul r10
	mov r10, rax
	dec rbx
	cmp rbx, r8
	jnl _attlp02

	mov [r9], r11d
%endmacro
