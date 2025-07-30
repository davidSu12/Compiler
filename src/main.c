#include <stdio.h>
#include "lexer.h"


#define TOP_DOWN_IT
#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif //TOP_DOWN_PR

#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#include "parser/LL/iterative/stack_production.h"
#include "parser/LL/iterative/testStackProduction/testStackProduction.h"
#include "globalVar/parseTable.h"
#endif //TOP_DOWN_IT


#include "testHeader.h"


int main(int argc, char ** argv) {

    initBuffer();
    assert(parse());

    return 0;
}
