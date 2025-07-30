#ifndef PARSETABLE_H
#define PARSETABLE_H


#define PATH_PARSER_TYPES "../parser/LL/iterative/typesParser.h"
#define PATH_LEXER_MACROS "../lexerMacros.h"

#include PATH_PARSER_TYPES
#include PATH_LEXER_MACROS

extern production *parseTable[NUM_VARIABLES][NUM_TERMINALS];

#endif
