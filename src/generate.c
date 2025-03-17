#include "generate.h"

#include "opcode.h"

byte_t bytecode[MAX_TOKENS * 5];
int bytecode_pos = 0;

void generate_bytecode()
{
    for (int i = 0; i < rpn_pos; i++)
    {
        Token token = rpn[i];
        if (token.type == TOKEN_INT)
        {
            bytecode[bytecode_pos++] = PUSH; // PUSH
            bytecode[bytecode_pos++] = (token.value >> 24) & 0xFF;
            bytecode[bytecode_pos++] = (token.value >> 16) & 0xFF;
            bytecode[bytecode_pos++] = (token.value >> 8) & 0xFF;
            bytecode[bytecode_pos++] = token.value & 0xFF;
        }
        else if (token.type == TOKEN_PLUS)
        {
            bytecode[bytecode_pos++] = ADD; // ADD
        }
        else if (token.type == TOKEN_MINUS)
        {
            bytecode[bytecode_pos++] = SUB; // SUB
        }
        else if (token.type == TOKEN_MUL)
        {
            bytecode[bytecode_pos++] = MUL; // MUL
        }
        else if (token.type == TOKEN_DIV)
        {
            bytecode[bytecode_pos++] = DIV; // DIV
        }
    }
    bytecode[bytecode_pos++] = HALT; // HALT
}