	section .rodata
	hello_msg db 'Hello, Holberton', 0 ; Define the message to print with a null terminator

	section .text
	global _start

	extern printf

_start:
	;;  Call printf function
	mov rdi, hello_msg	; First argument: pointer to the message
	xor rax, rax	; Clear rax (no floating point arguments)
	call printf	; Call the printf function

	;;  Exit the program
	mov rax, 60		; System call number for exit (60)
	xor rdi, rdi	; Exit code 0
	syscall	; Invoke the system call
