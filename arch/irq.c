// arch/irq.c
#include "isr.h"
#include "idt.h"
#include "pic.h"   // declare pic_remap, pic_send_end_of_interrupt

// Example IRQ handler array
void *irq_routines[16] = {0};

void irq_install_handler(int irq, void (*handler)(void *)) {
    irq_routines[irq] = handler;
}

void irq_handler(struct regs *r) {
    void (*handler)(void *);
    handler = irq_routines[r->int_no - 32];
    if (handler) {
        handler(r);
    }

    pic_send_end_of_interrupt(r->int_no - 32);
}

