section .data
    prompt db 'Enter two digits (W and H) separated by space: ', 0
    promptLen equ $ - prompt
    star db '*', 0
    newline db 0xA

section .bss
    input resb 3 ; Reserve 3 bytes for two digits and a space

section .text
global _start

_start:
    ; Print the prompt
    mov rax, 1  ; syscall number for write
    mov rdi, 1  ; file descriptor 1 is stdout
    mov rsi, prompt ; pointer to the prompt string
    mov rdx, promptLen ; length of the prompt string
    syscall

    ; Read two single-digit numbers
    mov rax, 0  ; syscall number for read
    mov rdi, 0  ; file descriptor 0 is stdin
    mov rsi, input ; buffer to store the input
    mov rdx, 3  ; maximum number of bytes to read
    syscall

   ; Convert ASCII characters to integers
    movzx rax, byte [input]
    sub rax, '0'
    mov rbx, rax ; W

    movzx rax, byte [input+2]
    sub rax, '0'
    mov rcx, rax ; H

    ; Set up for the rectangle drawing loop
    mov r8, rcx ; row counter (H)
    mov r9, rbx ; column counter (W), re-initialized for each row

draw_row:
    push r8
    mov r9, rbx ; Reset column counter for each row

draw_star:
    mov rax, 1
    mov rdi, 1
    mov rsi, star
    mov rdx, 1
    syscall

    dec r9
    jnz draw_star

    ; Print newline after a row
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    pop r8
    dec r8
    jnz draw_row

    ; Exit
    mov rax, 60 ; syscall number for exit
    syscall
