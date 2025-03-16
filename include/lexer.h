#ifndef ARIA_LEXER_H
#define ARIA_LEXER_H

#include "token.h"

typedef struct
{
    const char *input;
    int pos;
} Lexer;

void lexer_init(Lexer *lexer, const char *input);
Token lexer_next_token(Lexer *lexer);

#endif // ARIA_LEXER_H