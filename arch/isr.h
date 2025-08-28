#ifndef ISR_H
#define ISR_H

#include <stdint.h>

// CPU state structure (pushed by ISR stubs in isr.s)
struct regs {
    uint32_t ds;                  // Data segment selector
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha
    uint32_t int_no, err_code;    // Interrupt number + error code (if any)
    uint32_t eip, cs, eflags, useresp, ss; // Pushed by CPU automatically
};

typedef void (*isr_t)(struct regs*);

void isr_install();
void register_interrupt_handler(uint8_t n, isr_t handler);

#endif
