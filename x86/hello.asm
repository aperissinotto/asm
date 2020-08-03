section .data
	text db "Hello, World!", 0x0a
	ttext equ $-text

section .text
	global _start

_start:
	mov eax, 4	; funcao de write
	mov ebx, 1	; file descripto (fd) - 1=saida padrao
	mov ecx, text	; mensagem
	mov edx, ttext	; tamanho da mensagem
	int 0x80	; chama s.o.

	mov eax, 1	; funcao de retorno
	mov ebx, 0	; codigo de retorno
	int 0x80	; chama s.o.
