#include "vm.h"

#include <stdio.h>
#include <stdlib.h>

#include "opcode.h"

void VM_execute(VM *vm)
{
    while (vm->ip < vm->code_size)
    {
        byte_t op_code = vm->code[vm->ip++];
        if (op_code <= HALT && OP_TABLE[op_code])
        {
            OP_TABLE[op_code](vm);
        }
        else
        {
            printf("Unknown opcode: %d\n", op_code);
            exit(1);
        }
    }
}