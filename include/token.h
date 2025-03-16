#ifndef ARIA_TOKEN_H
#define ARIA_TOKEN_H

typedef enum
{
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_EOF,
} TokenType;

typedef struct
{
    TokenType type;
    int value;
} Token;

#endif // ARIA_TOKEN_H