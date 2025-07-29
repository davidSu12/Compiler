#ifndef PARSER_H
#define PARSER_H

#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH

#include "setLabel.h"
#include "typesParser.h"
#include "stack_production.h"

production *createProduction(enum labelTok head, enum labelTok body[], int longitud_array);
setLabel first(enum labelTok head);
bool derivesEmptyString(enum labelTok head);
setLabel follow(enum labelTok head);
void initParseTable(void);
setLabel first_production(production p);
/**
 * This function parses the specified string by stdin
 */
bool parse();



#endif
