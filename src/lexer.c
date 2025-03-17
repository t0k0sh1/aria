#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void lexer_init(Lexer *lexer, const char *input)
{
    lexer->input = input;
    lexer->pos = 0;
}

Token lexer_next_token(Lexer *lexer)
{
    while (lexer->input[lexer->pos] != '\0')
    {
        char current = lexer->input[lexer->pos];

        if (isspace(current))
        {
            lexer->pos++;
            continue;
        }

        if (isdigit(current))
        {
            int value = 0;
            while (isdigit(lexer->input[lexer->pos]))
            {
                value = value * 10 + (lexer->input[lexer->pos] - '0');
                lexer->pos++;
            }
            return (Token){TOKEN_INT, value};
        }

        lexer->pos++;
        switch (current)
        {
        case '+':
            return (Token){TOKEN_PLUS, 0};
        case '-':
            return (Token){TOKEN_MINUS, 0};
        case '*':
            return (Token){TOKEN_MUL, 0};
        case '/':
            return (Token){TOKEN_DIV, 0};
        case '(':
            return (Token){TOKEN_LPAREN, 0};
        case ')':
            return (Token){TOKEN_RPAREN, 0};
        default:
            printf("Error: Unknown character '%c'\n", current);
            exit(1);
        }
    }
    return (Token){TOKEN_EOF, 0};
}
