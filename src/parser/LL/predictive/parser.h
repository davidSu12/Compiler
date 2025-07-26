#ifndef PARSER_H
#define PARSER_H

#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH



bool expr(void); //this is my first symbol
void exprP(void);
void term(void);
void termP(void);
void factor(void);
void match(enum labelTok simbolo);
void initParser(void);


#endif PARSER_H
