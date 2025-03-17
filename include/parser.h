#ifndef ARIA_PARSER_H
#define ARIA_PARSER_H

#include "lexer.h"

#define MAX_TOKENS 256

extern Token rpn[MAX_TOKENS];
extern int rpn_pos;

void parse_expression(Lexer *lexer);

#endif // ARIA_PARSER_H