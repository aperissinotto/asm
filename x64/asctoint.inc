;***********************************************************************************
; Autor: Alexandre Perissinotto
; Data: 02/08/2020 02:34
; obbiettivo: macro per convertire numeri caratteri ascii in intero
; parametri : 1-numero ascii
;***********************************************************************************

%macro asctoint 2
	; prende i parametri
	mov r8, %1	; indirizzo del numero ascii
	mov r9, %2      ; indirizzo del area di lavoro

; scopri l'ultimo byte ascii, quando = 0x0a
	mov rbx, r8	; copia il indirizzo del numero per confrontare
	mov rcx, 0x00   ; pulire il register per usare la parte bassa

_attlp01:
	mov cl, [rbx]   ; copia uno byte per confrontare per 0x0a
	cmp cl, 0x0a    ; quando cl = 0x0a e fine della string
	je _uttlp01     ; si, e finito
	inc rbx         ; no, incrementa il indirizzo
	j _attlp01      ; ritorna al loop

_uttlp01:
	dec rbx         ; diminuisce il indirizzo
	mov rdx, 0x00   ; pulire il register per la moltiplicazione
	mov r10, 0x01   ; il primo moltiplicatore
	mov r11, 0x00   ; pulire il register per accumulare la somma

_attlp02:
	mov cl, [rbx]   ; copia uno byte per diventare un intero
	sub cl, 0x30    ; 
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

	mov [r9], r11
%endmacro
