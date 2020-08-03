%macro fim 1
	mov rax, SYS_EXIT
	mov rdi, %1
	syscall
%endmacro

SYS_EXIT	equ 60
