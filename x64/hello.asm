%include "prtout.inc"
%include "fim.inc"

section .data
	text db "Hello, World!", 0x0a
	ttext equ $-text

section .text
	global _start

_start:
	prtstr text, ttext

	fim RC_OK

RC_OK		equ 0
