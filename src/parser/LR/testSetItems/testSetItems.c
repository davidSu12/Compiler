#include "testSetItems.h"

void testSetItem1(void){
    setItem st1;
    createEmptySetItem(&st1);
    for(int i = 0; i < NUM_PRODUCCIONES; i++){
        assert(!st1[i]);
    }

    addItem(&st1, (struct item) {1,2 });
    assert(ELEMENT_IN_SET(st1[1], 2) != 0);
    for(int i = 0; i < NUM_PRODUCCIONES; i++){
        if(i != 1){
            assert(!st1[i]);
        }
    }
    addItem(&st1, (struct item){1, 1});
    assert(ELEMENT_IN_SET(st1[1],1) != 0);
    assert(!ELEMENT_IN_SET(st1[1],0));
    deleteSetItem(&st1);

}
void testSetItem2(void){
    setItem st1;
    setItem st2;
    createEmptySetItem(&st1);
    createEmptySetItem(&st2);
    addItem(&st1, (struct item) {1, 1});
    addItem(&st2, (struct item) {1, 2});
    addItem(&st1, (struct item) {3, 1});
    addItem(&st2, (struct item){3, 2});

    unionSetItems(&st1, &st2);
    assert(st2 == NULL);
    assert(ELEMENT_IN_SET(st1[1], 1) != 0);
    assert(ELEMENT_IN_SET(st1[1], 2) != 0);
    assert(ELEMENT_IN_SET(st1[3], 1) != 0);
    assert(ELEMENT_IN_SET(st1[3], 2) != 0);
    for(int i = 0; i < NUM_PRODUCCIONES; i++){
        if(i != 1 && i != 3){
            assert(!st1[i]);
        }
    }
    deleteSetItem(&st1);


}
void testSetItem3(void){

    setItem st1;
    setItem st2;
    createEmptySetItem(&st1);
    createEmptySetItem(&st2);
    addItem(&st1, (struct item) {1, 1});
    addItem(&st1, (struct item) {1,2});
    addItem(&st2, (struct item) {1, 2});
    addItem(&st1, (struct item) {3, 1});
    addItem(&st2, (struct item){3, 2});

    assert(itemInSet(st1,(struct item){1,1}));
    assert(!itemInSet(st1, (struct item){1, 0}));
    assert(itemInSet(st1, (struct item){3,1}));
    assert(!itemInSet(st2 ,(struct item) {3, 0}));
    assert(!itemInSet(st2, (struct item){3, 3}));


    deleteItem(&st1, (struct item){1,1});
    assert(!itemInSet(st1,(struct item){1,1}));
    assert(itemInSet(st1, (struct item) {1,2}));
}