#include "testGoto.h"


void testGoto1(void){

    setItem st1;
    createEmptySetItem(&st1);

    assert(addItem(&st1, (struct item){0,1}));

    setItem *got = gotoFunction(&st1, PLUS);

    setItem temp = *got;
    assert(temp -> data.production == 0);
    assert((temp -> data.item | 0x4) == 0x4);
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
    temp = temp -> next;
    assert(temp == NULL);



    deleteSetItem(&st1);
    deleteSetItem(got);
    assert(*got == NULL);


    assert(addItem(&st1, (struct item){0, 2}));
    assert(addItem(&st1, (struct item){1,1}));

    got = gotoFunction(&st1, TERM);

    temp = *got;
    assert(temp -> data.production == 0);
    assert((temp -> data.item | 0x8) == 0x8);
    deleteSetItem(got);
    deleteSetItem(&st1);

    assert(*got == NULL);
    assert(isEmptySetItem(st1));

}

void testGoto2(void){

    setItem st1;
    createEmptySetItem(&st1);


    assert(addItem(&st1, (struct item){3, 1}));

    setItem *got = gotoFunction(&st1, DOT);

    setItem temp = *got;
    assert(temp -> data.production == 3);
    assert((temp -> data.item | 0x4) == 4);
    temp = temp -> next;
    assert(temp -> data.production == 6);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp -> data.production == 7);
    assert((temp -> data.item | 0x1) == 0x1);
    temp = temp -> next;
    assert(temp == NULL);

    deleteSetItem(got);
    assert(isEmptySetItem(*got));

}

