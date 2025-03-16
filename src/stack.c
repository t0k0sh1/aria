#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push(VM *vm, int32_t value)
{
    if (vm->sp >= STACK_SIZE)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    vm->stack[vm->sp++] = value;
}

int32_t pop(VM *vm)
{
    if (vm->sp <= 0)
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    return vm->stack[--vm->sp];
}