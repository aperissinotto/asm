%macro getin 2
	mov rax, SYS_READ
	mov rdi, STD_IN
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

STD_IN		equ 0
SYS_READ	equ 0
	
