#include <stdio.h>
#include "z80.h"

int main() {
    Z80 cpu;
    z80_reset(&cpu);

    // Example program: LD A, 42
    cpu.memory[0x0000] = 0x3E; // LD A, n
    cpu.memory[0x0001] = 0x2A; // n = 0x2A

    z80_step(&cpu);

    printf("A = %02X\n", cpu.A); // Expect 2A

    return 0;
}
