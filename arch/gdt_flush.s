[GLOBAL gdt_flush]     ; Make the symbol visible to C
gdt_flush:
    lgdt [esp+4]       ; Load GDT descriptor (passed as argument)
    mov ax, 0x10       ; Data segment selector
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x08:.flush    ; Code segment selector (0x08)
.flush:
    ret

