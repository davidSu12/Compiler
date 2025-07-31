#include "testSetItems.h"



static void privateViewBinary(uint32_t d, int count){
    if(d == 0){
        printf("0");
        return;
    }
    privateViewBinary(d >>1, count++);
    printf("%d", d % 2);

}

void viewBinary(uint32_t d){
    privateViewBinary(d, 0);
}

void testSetItem1(void){


    setItem st1;
    createEmptySetItem(&st1);

    assert(addItem(&st1, (struct item){1,2}));
    assert(addItem(&st1, (struct item){5, 1}));
    assert(addItem(&st1, (struct item){1,0}));
    assert(addItem(&st1, (struct item){ 3, 5}));

    assert(addItem(&st1, (struct item){2,1}));
    assert(st1 != NULL);

    printSetItem(st1, viewBinary);
    assert(itemInSet(st1, (struct item){1,2}));
    assert(!itemInSet(st1, (struct item){1,1}));
    assert(itemInSet(st1, (struct item){1,0}));

    printf("\nafter eliminating:\n");
    deleteItem(&st1, (struct item){1,2});
    assert(!itemInSet(st1, (struct item){1,2}));
    printSetItem(st1, viewBinary);

}
void testSetItem2(void){


}

void testSetItem3(void){

}