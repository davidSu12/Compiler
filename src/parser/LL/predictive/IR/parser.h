#ifndef PARSER_H
#define PARSER_H


#include "paths.h"
#include LEXER_PATH
#include AST_TOP_DOWN_PREDICTIVE
#include TOP_DOWN_QUADRUPLET_PATH




nodeTree * parse(void);
void expr(void);
void exprP(void);
void term(void);
void termP(void);
void factor(void);
void match(token simbolo);
void initParser(void);
void translateEntry(nodeTree * tree);
void getQuadrupletList(nodeTree * tree, quadrupletList *L);


#endif
