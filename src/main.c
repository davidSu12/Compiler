#include <stdio.h>
#include "lexer.h"

#define TOP_DOWN_IT

#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif //TOP_DOWN_PR
#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#include "parser/LL/iterative/stack_production.h"
#include "parser/LL/iterative/testStackProduction.h"
#endif //TOP_DOWN_IT



#define TEST_FIRST
#ifdef TEST_FIRST
#include "parser/LL/iterative/testFirst/testFirst.h"
#endif


int main(int argc, char ** argv){



    //test1First();

    setLabel t = first(FACTOR);
    printSetLabel(t);
    return 0;
}
