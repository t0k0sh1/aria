#ifndef ARIA_STACK_H
#define ARIA_STACK_H

#include "vm.h"

void push(VM *vm, int32_t value);
int32_t pop(VM *vm);

#endif // ARIA_STACK_H