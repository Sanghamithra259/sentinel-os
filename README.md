# Sentinel OS

**Sentinel OS** is a lightweight, bare-metal operating system designed for technical users who want to experiment with low-level computing and security concepts. It can execute binaries in a sandboxed environment, making it ideal for learning, malware analysis, and educational research.

## Features

- **Multiboot compliant** kernel  
- Lightweight and minimal OS core  
- VGA text output for debugging and display  
- Support for x86 architecture  
- Focused on visibility, control, and safe execution  

## Current Status

- Bootloader (`boot.s`) is functional  
- Basic kernel (`kernel.c`) prints a message to the screen  
- Architecture-specific code under `arch/` for GDT, IDT, IRQ, PIC  
- ISO image generation is working via GRUB  
- Machine learning extensions planned (currently 10% complete)  

## Directory Structure

sentinel-os/
│
├── arch/ # Architecture-specific source files
│ ├── gdt.c
│ ├── gdt.h
│ ├── idt.c
│ ├── idt.h
│ ├── irq.c
│ ├── isr.s
│ ├── pic.c
│ └── ...
│
├── boot.s # Multiboot-compliant bootloader
├── kernel.c # Main kernel code
├── linker.ld # Linker script
├── Makefile # Build automation
├── iso/ # GRUB ISO files (generated)
├── sentinel.iso # Final ISO image (generated)


## Build Instructions

1. Install required packages:

```bash
sudo apt update
sudo apt install build-essential nasm grub-pc-bin xorriso qemu-system-i386
