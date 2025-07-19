#include "z80.h"
#include <string.h>
#include <stdio.h>

void z80_reset(Z80 *cpu) {
    memset(cpu, 0, sizeof(Z80));
    cpu->PC = 0x0000;
}

void z80_step(Z80 *cpu) {
    uint8_t opcode = cpu->memory[cpu->PC++];

    switch (opcode) {
        case 0x00:  // NOP
            break;

        case 0x3E: { // LD A, n
            cpu->A = cpu->memory[cpu->PC++];
            break;
        }

        default:
            printf("Unimplemented opcode: 0x%02X at 0x%04X\n", opcode, cpu->PC - 1);
            break;
    }
}
