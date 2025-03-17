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

    // write magic number
    // fwrite("ARIA", 1, 4, file);

    // write version
    // uint16_t version = 0x0001;
    // fwrite(&version, sizeof(version), 1, file);

    // write bytecode size
    // uint16_t size = (uint16_t)bytecode_pos;
    // fwrite(&size, sizeof(size), 1, file);

    // write bytecode
    fwrite(bytecode, 1, bytecode_pos, file);

    // close file
    fclose(file);
}