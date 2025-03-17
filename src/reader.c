#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

byte_t *load_bytecode(const char *filename, size_t *size)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    byte_t *buffer = (byte_t *)malloc(*size);
    if (!buffer)
    {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, *size, file);
    fclose(file);
    return buffer;
}