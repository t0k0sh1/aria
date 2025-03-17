#include "opcode.h"

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void exec_NOP(VM *vm)
{
    printf("NOP\n");
}

void exec_PUSH(VM *vm)
{
    int32_t value = (vm->code[vm->ip++] << 24) |
                    (vm->code[vm->ip++] << 16) |
                    (vm->code[vm->ip++] << 8) |
                    (vm->code[vm->ip++]);
    push(vm, value);
    printf("PUSH %d\n", value);
}

void exec_POP(VM *vm)
{
    int32_t value = pop(vm);
    printf("POP %d\n", value);
}

void exec_ADD(VM *vm)
{
    int32_t b = pop(vm);
    int32_t a = pop(vm);
    int32_t result = a + b;
    push(vm, result);
    printf("ADD %d + %d = %d\n", a, b, result);
}

void exec_SUB(VM *vm)
{
    int32_t b = pop(vm);
    int32_t a = pop(vm);
    int32_t result = a - b;
    push(vm, result);
    printf("SUB %d - %d = %d\n", a, b, result);
}

void exec_MUL(VM *vm)
{
    int32_t b = pop(vm);
    int32_t a = pop(vm);
    int32_t result = a * b;
    push(vm, result);
    printf("MUL %d * %d = %d\n", a, b, result);
}

void exec_DIV(VM *vm)
{
    int32_t b = pop(vm);
    int32_t a = pop(vm);
    int32_t result = a / b;
    push(vm, result);
    printf("DIV %d / %d = %d\n", a, b, result);
}

void exec_HALT(VM *vm)
{
    // printf("HALT\n");
    exit(0);
}

void (*OP_TABLE[])(VM *) = {
    exec_NOP,  // 0x00: NOP
    exec_PUSH, // 0x01: PUSH
    exec_POP,  // 0x02: POP
    exec_ADD,  // 0x03: ADD
    exec_SUB,  // 0x04: SUB
    exec_MUL,  // 0x05: MUL
    exec_DIV,  // 0x06: DIV
    exec_HALT  // 0x07: HALT
};
