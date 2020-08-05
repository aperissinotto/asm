%include "asctoint.inc"

section .data
	txt1 	dq 12345678
	ttxt1 	equ $-txt1

section .bss
	num1	resd 1
	tnum1	equ $-num1

	num2	resd 1
	tnum2	equ $-num2

section .text
	global _start

_start:
	mov rax, 0
	mov rdi, 0
	mov rsi, num1
	mov rdx, 4
	syscall

	mov r8, num1
	mov r9, num2

	mov rbx, r8
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

	mov rax, 60
	mov rdi, 0
	syscall
