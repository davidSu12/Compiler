#ifndef PARSETABLE_H
#define PARSETABLE_H


#include "paths.h"

#include TYPE_PRODUCTION_PATH"typeProduction.h"
#include LEXER_MACROS_PATH"lexerMacros.h"

extern production *parseTable[NUM_VARIABLES_TOP_DOWN][NUM_TERMINALS];

#endif
