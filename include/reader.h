#ifndef ARIA_READER_H
#define ARIA_READER_H

#include <stddef.h>

#include "vm.h"

byte_t *load_bytecode(const char *filename, size_t *size);

#endif // ARIA_READER_H