#include "testClosureFunction.h"

void testClosure1(void){

    setItem st1;
    createEmptySetItem(&st1);
    addItem(&st1, (struct item){0,0});

    setItem *closure_set = closure(&st1);
    //its the initial set so all the productions with the dots at the first place are added

    NodeSetItem *temp = *closure_set;

    assert(temp -> data.production == 0);
    assert((temp -> data.item | 1U) == 1);
    temp = temp -> next;
    assert(temp -> data.production == 1);
    assert((temp -> data.item | 1U) == 1);
    temp = temp -> next;
    assert(temp -> data.production == 2);
    assert((temp -> data.item | 1U) == 1);
    temp = temp -> next;
    assert(temp -> data.production == 3);
    assert((temp -> data.item | 1U) == 1);
    temp = temp -> next;
    assert(temp -> data.production == 4);
    assert((temp -> data.item | 1U) == 1);
    temp = temp -> next;
    assert(temp -> data.production == 5);
    assert((temp -> data.item | 1U) == 1);
    temp = temp -> next;
    assert(temp -> data.production == 6);
    assert((temp -> data.item | 1U) == 1);
    temp = temp -> next;
    assert(temp -> data.production == 7);
    assert((temp -> data.item | 1U) == 1);


    deleteSetItem(&st1);
    addItem(&st1, (struct item){0,1});

    temp = st1;
    assert((temp -> data.production == 0));
    assert((temp -> data.item | 2U) == 2U);
    temp = temp -> next;
    assert(temp == NULL);


}

void testClosure2(void){


}

void testClosure3(void){


}