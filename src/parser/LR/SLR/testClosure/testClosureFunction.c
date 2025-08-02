#include "testClosureFunction.h"

void testClosure1(void){

    setItem st1;
    createEmptySetItem(&st1);
    addItem(&st1, (struct item){0,0});

    setItem *closure_set = closure(&st1);
    //its the initial set so all the productions with the dots at the first place are added

    NodeSetItem *temp = *closure_set;

    assert(temp -> data.production == 0);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 1);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 2);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 3);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 4);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 5);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 6);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 7);
    assert((temp -> data.item | 0x1) == 0x1);


    deleteSetItem(&st1);
    addItem(&st1, (struct item){0,1});

    temp = *(closure(&st1));


    assert((temp -> data.production == 0));
    assert((temp -> data.item | 0x02) == 0x02);
    temp = temp -> next;
    assert(temp == NULL);
    deleteSetItem(&st1);

}

void testClosure2(void){
    setItem st1;
    createEmptySetItem(&st1);
    addItem(&st1, (struct item){1,2});

    NodeSetItem *temp = *(closure(&st1));

    assert(temp -> data.production == 1);
    assert((temp -> data.item | 0x4) == 0x4);
    temp = temp -> next;
    assert(temp -> data.production == 3);
    assert((temp ->data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 4);
    assert((temp ->data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 5);
    assert((temp ->data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 6);
    assert((temp ->data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 7);
    assert((temp ->data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp == NULL);
    deleteSetItem(&st1);
}

void testClosure3(void){

    setItem st1;
    createEmptySetItem(&st1);
    addItem(&st1, (struct item){3,2});

    NodeSetItem *temp = *(closure(&st1));

    assert(temp -> data.production == 3);
    assert((temp -> data.item | 0x4) == 0x4);
    temp = temp -> next;
    assert(temp -> data.production == 6);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 7);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp == NULL);

    deleteSetItem(&st1);



}