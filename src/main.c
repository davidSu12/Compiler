#include <stdio.h>
#include "lexer.h"
#include "paths.h"

//#define TEST_CLOSURE_FUNCTION

#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif //TOP_DOWN_PR


#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#include "parser/LL/iterative/stack_production.h"
#include "parser/LL/iterative/testStackProduction/testStackProduction.h"
#include "globalVar/listProduction/topDown/parseTable.h"
#endif //TOP_DOWN_IT


#define BOTTOM_UP
#define TEST_CLOSURE_FUNCTION

#ifdef BOTTOM_UP
#include "parser/LR/testSetItems/testSetItems.h"
#endif

#ifdef TEST_CLOSURE_FUNCTION
#include "parser/LR/SLR/testClosure/testClosureFunction.h"
#endif


#include "testHeader.h"


int main(int argc, char ** argv) {

    testClosure1();
    testClosure2();
    testClosure3();

    return 0;
}
