#include "parse.h"

// #define MAX_TOKENS 256

Token rpn[MAX_TOKENS];
int rpn_pos = 0;

Token op_stack[MAX_TOKENS];
int op_stack_pos = 0;

int precedence(TokenType type)
{
    switch (type)
    {
    case TOKEN_MUL:
    case TOKEN_DIV:
        return 2;
    case TOKEN_PLUS:
    case TOKEN_MINUS:
        return 1;
    default:
        return 0;
    }
}

void parse_expression(Lexer *lexer)
{
    Token token;
    while ((token = lexer_next_token(lexer)).type != TOKEN_EOF)
    {
        if (token.type == TOKEN_INT)
        {
            rpn[rpn_pos++] = token;
        }
        else if (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS ||
                 token.type == TOKEN_MUL || token.type == TOKEN_DIV)
        {
            while (op_stack_pos > 0 && precedence(op_stack[op_stack_pos - 1].type) >= precedence(token.type))
            {
                rpn[rpn_pos++] = op_stack[--op_stack_pos];
            }
            op_stack[op_stack_pos++] = token;
        }
    }
    while (op_stack_pos > 0)
    {
        rpn[rpn_pos++] = op_stack[--op_stack_pos];
    }
}
