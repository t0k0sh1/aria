#include <stdio.h>
#include <stdlib.h>

#include "vm.h"
#include "lexer.h"
#include "opcode.h"
#include "parse.h"
#include "generate.h"
#include "writer.h"

byte_t *load(const char *filename, size_t *size)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("EError opening file");
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

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        size_t program_size;
        byte_t *program = load(argv[1], &program_size);
        VM vm = {
            .stack = {0},
            .sp = 0,
            .code = program,
            .ip = 0,
            .code_size = program_size};
        VM_execute(&vm);
        return 0;
    }

    if (argc == 3)
    {
        FILE *file = fopen(argv[1], "r");
        if (!file)
        {
            perror("Error opening source file");
            return 1;
        }
        char source[256];
        fgets(source, sizeof(source), file);
        fclose(file);

        Lexer lexer;
        lexer_init(&lexer, source);
        parse_expression(&lexer);
        generate_bytecode();
        save_bytecode(argv[2]);

        printf("Bytecode written to %s\n", argv[2]);
        return 0;
    }

    printf("Usage: %s <code file>\n", argv[0]);
    printf("Usage: %s <source file> <output file>\n", argv[0]);
    return 1;
}
