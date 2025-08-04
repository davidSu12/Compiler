#ifndef PARSER_H
#define PARSER_H


#include "paths.h"
#include LEXER_PATH
#include AST_TOP_DOWN_ITERATIVE




bool parse(void);
void expr(void);
void exprP(void);
void term(void);
void termP(void);
void factor(void);
void match(token simbolo);
void initParser(void);


#endif
