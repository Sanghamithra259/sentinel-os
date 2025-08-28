#include <stdint.h>

#define VGA_MEMORY ((uint16_t*)0xb8000)
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

// Cursor position
static uint8_t row = 0;
static uint8_t col = 0;

// Print a single character
void kputc(char c) {
    if (c == '\n') {
        col = 0;
        row++;
        return;
    }

    uint16_t *location = VGA_MEMORY + (row * VGA_WIDTH + col);
    *location = (uint16_t)c | (0x07 << 8); // white on black
    col++;

    if (col >= VGA_WIDTH) {
        col = 0;
        row++;
    }
    if (row >= VGA_HEIGHT) {
        row = 0; // simple scroll wraparound (can improve later)
    }
}

// Print a null-terminated string
void kputs(const char *s) {
    for (int i = 0; s[i]; i++) {
        kputc(s[i]);
    }
}

// Kernel entry point
void main() {
    kputs("Hello from Sentinel OS!\n");
    kputs("VGA output works correctly.\n");

    while (1); // hang forever
}

