#include <stdint.h>

static uint16_t* const VGA_MEMORY = (uint16_t*)0xB8000;
static int term_col = 0, term_row = 2; // print on row 2 so we keep the header

static inline uint8_t inb(uint16_t port) { uint8_t ret; asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port)); return ret; }

const char scancode_to_ascii[128] = {
    0,  27,'1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',0,
    'a','s','d','f','g','h','j','k','l',';','\'','`',0,
    '\\','z','x','c','v','b','n','m',',','.','/',0,
    '*',0,' ',0
    // rest zeros
};

void keyboard_install()
{
    // nothing special to install in this minimal demo
}

void keyboard_handler()
{
    uint8_t scancode = inb(0x60);
    if (scancode & 0x80) {
        // key release - ignore
    } else {
        char c = scancode_to_ascii[scancode];
        if (c) {
            int idx = term_row * 80 + term_col;
            VGA_MEMORY[idx] = (uint8_t)c | (0x07 << 8);
            term_col++;
            if (term_col >= 80) { term_col = 0; term_row++; }
        }
    }
    // send EOI
    asm volatile ("outb %0, %1" : : "a"(0x20), "Nd"(0x20));
}
