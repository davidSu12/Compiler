#include "testSetItems.h"



static void privateViewBinary(uint32_t d, int count){
    if(d == 0){
        for(int i = 0; i <= 32 - count; i++){
            printf("0");
        }
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
    assert(addItem(&st1, (struct item){2,1}));
    assert(st1 != NULL);

    printSetItem(st1);
    viewBinary(st1 -> data.item);

}
void testSetItem2(void){


}

void testSetItem3(void){

}