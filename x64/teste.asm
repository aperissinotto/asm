section .data
	txt1 	db "Digite o 1 numero: "
	ttxt1 	equ $-txt1

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
	mov rax, txt1
	mov rbx, [txt1]
	mov rcx, ttxt1
	mov rdx, 1
	mov r8, num1
	mov [num1], rdx

	mov rax, 60
	mov rdi, 0
	syscall
