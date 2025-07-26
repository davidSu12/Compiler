#include <stdio.h>
#include "lexer.h"

#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif
#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#endif


int main(int argc, char ** argv){

    return 0;
}
