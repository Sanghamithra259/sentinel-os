#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>

void irq_install();
void irq_handler(uint32_t irq);

#endif
