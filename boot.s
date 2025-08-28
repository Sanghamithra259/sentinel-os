; boot.s - Multiboot compliant bootloader for Sentinel OS
; Assemble with: nasm -f elf32 boot.s -o boot.o

global start
extern main

section .multiboot
    align 4
    dd 0x1BADB002            ; magic number
    dd 0x00                  ; flags
    dd -(0x1BADB002+0x00)    ; checksum

section .text
start:
    ; Set up stack
    mov esp, stack_top

    ; Call kernel main
    call main

    ; Hang if main returns
.hang:
    hlt
    jmp .hang

section .bss
    resb 8192               ; 8 KB stack
stack_top:

