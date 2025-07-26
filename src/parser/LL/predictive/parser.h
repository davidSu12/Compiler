#ifndef PARSER_H
#define PARSER_H

#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH



void expr(); //this is my first symbol
void exprP();
void term();
void termP();
void factor();
void match(enum labelTok simbolo);
void initParser();


#endif PARSER_H
