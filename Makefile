# Toolchain
CC     = i686-elf-gcc
LD     = i686-elf-ld
NASM   = nasm

CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-pie -nostdlib

# Source files
ASM_SOURCES = boot.s arch/gdt_flush.s arch/idt_load.s
C_SOURCES   = kernel.c arch/gdt.c arch/idt.c arch/irq.c arch/pic.c

# Object files
ASM_OBJS = $(ASM_SOURCES:.s=.o)
C_OBJS   = $(C_SOURCES:.c=.o)
OBJS     = $(ASM_OBJS) $(C_OBJS)

# Output
TARGET = kernel.bin

# Default build
all: $(TARGET)

# Link kernel
$(TARGET): $(OBJS) linker.ld
	$(LD) -m elf_i386 -T linker.ld -o $@ $(OBJS)

# Compile assembly
%.o: %.s
	$(NASM) -f elf32 $< -o $@

# Compile C
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Run in QEMU
run: $(TARGET)
	qemu-system-i386 -kernel $(TARGET)

