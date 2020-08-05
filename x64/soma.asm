%include "prtout.inc"
%include "getin.inc"
%include "inttoasc.inc"
%include "fim.inc"

section .data
	txt1 	db "Digite o 1 numero: "
	ttxt1 	equ $-txt1
	txt2	db "Digite o 2 numero: "
	ttxt2	equ $-txt2

section .bss
	num1	resb 8
	tnum1	equ $-num1
	num2	resb 8
	tnum2	equ $-num2
	num3	resb 24
	tnum3	equ $-num3
	work    resb 48
	twork   equ $-work

section .text
	global _start

_start:
	prtout txt1, ttxt1
	getin num1, tnum1
	prtout txt2, ttxt2
	getin num2, tnum2
	mov rax, [num1]
	add rax, [num2]
	mov [num3], rax
	inttoasc num3, work, twork
	prtout work, twork
	fim RC_OK

RC_OK		equ 0
