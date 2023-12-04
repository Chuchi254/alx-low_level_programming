section .data
    msg db 'Mary had a little lamb',0xA  ; Message and a newline character
    len equ $ - msg                     ; Length of the message

section .text
    global _start

_start:
    ; Write the message to stdout
    mov eax, 4          ; The system call for write
    mov ebx, 1          ; File descriptor 1 is stdout
    mov ecx, msg        ; Pointer to our message
    mov edx, len        ; Length of our message
    int 0x80            ; Call the kernel

    ; Exit with code 123
    mov eax, 1          ; The system call for exit
    mov ebx, 123        ; Return code 123
    int 0x80            ; Call the kernel
