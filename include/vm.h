#ifndef ARIA_VM_H
#define ARIA_VM_H

#include <stdint.h>

typedef uint8_t byte_t;

#define STACK_SIZE 256

typedef struct
{
    byte_t stack[STACK_SIZE];
    int sp;
    byte_t *code;
    int ip;
    int code_size;
} VM;

void VM_execute(VM *vm);

#endif // ARIA_VM_H