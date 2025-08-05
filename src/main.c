#include <stdio.h>
#include "lexer.h"
#include "paths.h"

//#define TEST_CLOSURE_FUNCTION

#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif //TOP_DOWN_PR

#define IR_TRANSLATION
#ifdef IR_TRANSLATION
#include "parser/LL/predictive/IR/parser.h"
#endif

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


#ifdef TEST_SUPER_SET_ITEM
#include BOTTOM_UP_TEST_SUPER_SET_ITEMS
#endif


#ifdef TEST_GOTO_FUNCTION
#include BOTTOM_UP_TEST_GOTO_FUNCTION_PATH
#endif

#include "testHeader.h"

#include TEST_QUADRUPLET_PATH



int main(int argc, char ** argv) {



    testDeleteQuadrupletList();
    return 0;
}
