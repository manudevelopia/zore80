#include <stdio.h>

#include "z80.h"

void execute_opcode(struct cpu_t* cpu){
    byte opcode = cpu -> mem[cpu -> pc++];
}