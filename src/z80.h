#include <stdint.h>
#include "types.h"

#ifndef CPU_H_
#define CPU_H_

union register_t {

};

struct bank_t {
    uint8_t a, f;
    uint8_t b, c;
    uint8_t d, e;
    uint8_t h, l;

};

struct cpu_t {

  uint16_t mem[0x10000];

  struct bank_t main;
  struct bank_t alternate;

  uint16_t pc; 
  uint16_t sp;
  uint16_t ix;
  uint16_t ip;

  uint8_t i;
  uint8_t r;
};

#endif

