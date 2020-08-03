%macro prtout 2
	mov rax, SYS_WRITE
	mov rdi, STD_OUT
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

STD_OUT		equ 1
SYS_WRITE	equ 1
	
