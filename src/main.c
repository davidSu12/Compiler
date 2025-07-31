#include <stdio.h>
#include "lexer.h"



#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif //TOP_DOWN_PR

#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#include "parser/LL/iterative/stack_production.h"
#include "parser/LL/iterative/testStackProduction/testStackProduction.h"
#include "globalVar/parseTable.h"
#endif //TOP_DOWN_IT


#define BOTTOM_UP
#ifdef BOTTOM_UP
#include "parser/LR/testSetItems/testSetItems.h"
#endif


#include "testHeader.h"


int main(int argc, char ** argv) {

    testSetItem1();
    testSetItem2();
    return 0;
}
