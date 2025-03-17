#ifndef ARIA_GENERATE_H
#define ARIA_GENERATE_H

#include "parser.h"

#include "vm.h"

#define MAX_TOKENS 256

extern byte_t bytecode[MAX_TOKENS * 5];
extern int bytecode_pos;

void generate_bytecode();

#endif // ARIA_GENERATE_H