#include <stdio.h>
#include "lexer.h"

#define TOP_DOWN_IT
#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif
#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#include "parser/LL/iterative/stack_production.h"
#endif


int main(int argc, char ** argv){


    return 0;
}
