#include "testClosureFunction.h"

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