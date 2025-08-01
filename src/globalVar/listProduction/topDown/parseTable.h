#ifndef PARSETABLE_H
#define PARSETABLE_H


#include "paths.h"

#include TYPE_PRODUCTION_PATH
#include LEXER_MACROS_PATH

extern production *parseTable[NUM_VARIABLES_TOP_DOWN][NUM_TERMINALS];

#endif
