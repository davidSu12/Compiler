#ifndef PARSER_H
#define PARSER_H


#include "paths.h"
#include LEXER_PATH




/**
 * @return true if the parse goes right
 */
bool parse(void);
void expr(void); //this is my first symbol
void exprP(void);
void term(void);
void termP(void);
void factor(void);
void match(token simbolo);
void initParser(void);


#endif PARSER_H
