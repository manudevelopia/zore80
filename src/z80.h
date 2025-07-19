#ifndef Z80_H
#define Z80_H

#include <stdint.h>

typedef struct {
    // Main registers
    uint8_t A, F;
    uint8_t B, C;
    uint8_t D, E;
    uint8_t H, L;

    // Alternate register set
    uint8_t A_alt, F_alt;
    uint8_t B_alt, C_alt;
    uint8_t D_alt, E_alt;
    uint8_t H_alt, L_alt;

    // Index registers
    uint16_t IX, IY;

    // Stack Pointer and Program Counter
    uint16_t SP, PC;

    // Interrupt registers
    uint8_t I, R;
    uint8_t IFF1, IFF2;
    uint8_t IM;

    // Memory (64 KB)
    uint8_t memory[0x10000];
} Z80;

void z80_reset(Z80 *cpu);
void z80_step(Z80 *cpu);

#endif
