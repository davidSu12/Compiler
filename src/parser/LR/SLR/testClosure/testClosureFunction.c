#include "testClosureFunction.h"
#include <assert.h>
#include <stdio.h>

#define PATH_SET_ITEMS "parser/LR/setItems.h"
#define PATH_PARSER_SLR "parser/LR/SLR/parser.h"

#include PATH_SET_ITEMS
#include PATH_PARSER_SLR

void testClosure1(void){

    setItem st1;
    createEmptySetItem(&st1);
    addItem(&st1, (struct item){0,0});

    setItem *closure_set = closure(&st1);

}

void testClosure2(void){


}

void testClosure3(void){


}