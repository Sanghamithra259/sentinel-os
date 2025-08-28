[GLOBAL idt_load]      ; Make the symbol visible to C
idt_load:
    lidt [esp+4]       ; Load IDT descriptor (passed as argument)
    ret

