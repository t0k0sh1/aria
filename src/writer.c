#include "writer.h"

#include <stdlib.h>

#include "generate.h"

void save_bytecode(const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        perror("Error opening file");
        exit(1);
    }

    fwrite(bytecode, 1, bytecode_pos, file);
    fclose(file);
}