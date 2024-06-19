	section .data
	format db "Hello, Holberton", 0xA, 0 ; The string to print, followed by a newline and a null terminator

	section .text
	global main
	extern printf

main:
	;;  Set up the argument for printf
	mov rdi, format    	; First argument (format string) in rdi
	xor eax, eax       	; Clear eax register (printf expects RAX to be 0 in x64 ABI)
	call printf

	;;  Return 0
	mov eax, 0         	; Return 0
	ret
