#include "runner.h"

#include <stdio.h>
#include <stdlib.h>

#include "vm.h"
#include "reader.h"

void run(const char *filename)
{
    size_t program_size;
    byte_t *program = load_bytecode(filename, &program_size);
    VM vm = {
        .stack = {0},
        .sp = 0,
        .code = program,
        .ip = 0,
        .code_size = program_size};
    VM_execute(&vm);
}