#include "compiler.h"

#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "writer.h"
#include "parser.h"
#include "generate.h"
#include "util.h"

void compile(char *source_filename)
{
    FILE *in_file = fopen(source_filename, "r");
    if (!in_file)
    {
        perror("Error opening source file");
        return;
    }
    char source[256];
    fgets(source, sizeof(source), in_file);
    fclose(in_file);

    char output_filename[256];
    get_ac_filename(source_filename, output_filename);

    FILE *file = fopen(output_filename, "wb");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    Lexer lexer;
    lexer_init(&lexer, source);
    parse_expression(&lexer);
    generate_bytecode();
    save_bytecode(output_filename);

    printf("Bytecode written to %s\n", output_filename);
}