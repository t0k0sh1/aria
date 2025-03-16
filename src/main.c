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
    if (argc < 3)
    {
        printf("Usage: %s <source file> <output file>\n", argv[0]);
        return 1;
    }

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
    // if (argc < 2)
    // {
    //     fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    //     return EXIT_FAILURE;
    // }

    // size_t program_size;
    // byte_t *program = load(argv[1], &program_size);

    // const char *source = "10 + 20";
    // Lexer lexer;
    // lexer_init(&lexer, source);

    // Token token;
    // do
    // {
    //     token = lexer_next_token(&lexer);
    //     switch (token.type)
    //     {
    //     case TOKEN_INT:
    //         printf("TOKEN_INT: %d\n", token.value);
    //         break;
    //     case TOKEN_PLUS:
    //         printf("TOKEN_PLUS\n");
    //         break;
    //     case TOKEN_MINUS:
    //         printf("TOKEN_MINUS\n");
    //         break;
    //     case TOKEN_MUL:
    //         printf("TOKEN_MUL\n");
    //         break;
    //     case TOKEN_DIV:
    //         printf("TOKEN_DIV\n");
    //         break;
    //     case TOKEN_EOF:
    //         printf("TOKEN_EOF\n");
    //         break;
    //     default:
    //         printf("Unknown token\n");
    //     }
    // } while (token.type != TOKEN_EOF);

    // byte_t program[] = {
    //     PUSH, 0x00, 0x00, 0x00, 0x0A, // PUSH 10
    //     PUSH, 0x00, 0x00, 0x00, 0x14, // PUSH 20
    //     ADD,                          // ADD (10 + 20)
    //     POP,                          // POP (表示のため)
    //     PUSH, 0x00, 0x00, 0x00, 0x0A, // PUSH 10
    //     PUSH, 0x00, 0x00, 0x00, 0x14, // PUSH 20
    //     SUB,                          // SUB (20 - 10)
    //     POP,                          // POP (表示のため)
    //     PUSH, 0x00, 0x00, 0x00, 0x0A, // PUSH 10
    //     PUSH, 0x00, 0x00, 0x00, 0x14, // PUSH 20
    //     MUL,                          // MUL (10 * 20)
    //     POP,                          // POP (表示のため)
    //     PUSH, 0x00, 0x00, 0x00, 0x0A, // PUSH 10
    //     PUSH, 0x00, 0x00, 0x00, 0x14, // PUSH 20
    //     DIV,                          // DIV (20 / 10)
    //     POP,                          // POP (表示のため)
    //     HALT};

    // VM vm = {
    //     .stack = {0},
    //     .sp = 0,
    //     .code = program,
    //     .ip = 0,
    //     .code_size = program_size};
    // VM_execute(&vm);
    return 0;
}
