#include <stdio.h>
#include "lexer.h"
#include "paths.h"

//#define TEST_CLOSURE_FUNCTION

#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif //TOP_DOWN_PR

#define TOP_DOWN_IT
#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#include "parser/LL/iterative/stack_production.h"
#include "parser/LL/iterative/testStackProduction/testStackProduction.h"
#include "globalVar/listProduction/topDown/parseTable.h"
#endif //TOP_DOWN_IT



#ifdef BOTTOM_UP
#include "parser/LR/testSetItems/testSetItems.h"
#endif

#ifdef TEST_CLOSURE_FUNCTION
#include "parser/LR/SLR/testClosure/testClosureFunction.h"
#endif


#include "testHeader.h"


int main(int argc, char ** argv) {

    initBuffer();
    parse();
    return 0;
}
