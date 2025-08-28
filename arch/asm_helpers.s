; arch/asm_helpers.s
BITS 32

global gdt_flush
gdt_flush:
    mov eax, [esp+4]        ; Load pointer to GDT descriptor
    lgdt [eax]              ; Load the GDT register

    mov ax, 0x10            ; Kernel data segment selector (2nd entry in GDT)
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x08:.flush         ; Far jump to reload CS with kernel code segment
.flush:
    ret


global idt_load
idt_load:
    mov eax, [esp+4]        ; Load pointer to IDT descriptor
    lidt [eax]              ; Load the IDT register
    ret
