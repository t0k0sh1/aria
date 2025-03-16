#ifndef ARIA_OPCODE_H
#define ARIA_OPCODE_H

#include "vm.h"

typedef enum
{
    NOP = 0x00,
    PUSH = 0x01,
    POP = 0x02,
    ADD = 0x03,
    SUB = 0x04,
    MUL = 0x05,
    DIV = 0x06,
    HALT = 0x07,
} OP_CODE;

void exec_NOP(VM *vm);
void exec_PUSH(VM *vm);
void exec_POP(VM *vm);
void exec_ADD(VM *vm);
void exec_HALT(VM *vm);

extern void (*OP_TABLE[])(VM *);

#endif // ARIA_OPCODE_H