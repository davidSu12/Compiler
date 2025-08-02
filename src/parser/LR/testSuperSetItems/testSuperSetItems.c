#include "testSuperSetItems.h"


void testSuperSetItems1(void){


    setItem set1;
    setItem set2;
    setItem set3;

    createEmptySetItem(&set1);
    createEmptySetItem(&set2);
    createEmptySetItem(&set3);

    assert(addItem(&set1, (struct item){1,0}));
    assert(addItem(&set2, (struct item){2,0}));
    assert(addItem(&set3, (struct item){3, 0}));

    superSetItem superSet;
    createEmptySuperSet(&superSet);

    assert(addSet(&superSet, &set1));
    assert(addSet(&superSet, &set2));
    assert(addSet(&superSet, &set3));

    superSetItem temp;
    temp = superSet;
    assert(temp -> set == &set3);
    temp = temp -> next;
    assert(temp -> set == &set2);
    temp = temp -> next;
    assert(temp -> set == &set1);
    temp = temp -> next;
    assert(temp == NULL);

    deleteSuperSet(&superSet);

    assert(isEmptySuperSetItem(superSet));
    assert(set1 == NULL);
    assert(set2 == NULL);
    assert(set3 == NULL);
}
void testSuperSetItems2(void){

    setItem set1;
    setItem set2;
    setItem set3;

    createEmptySetItem(&set1);
    createEmptySetItem(&set2);
    createEmptySetItem(&set3);

    assert(addItem(&set1, (struct item){1,0}));
    assert(addItem(&set2, (struct item){2,0}));
    assert(addItem(&set3, (struct item){3, 0}));

    superSetItem superSet;
    createEmptySuperSet(&superSet);

    assert(addSet(&superSet, &set1));
    assert(addSet(&superSet, &set2));
    assert(addSet(&superSet, &set3));

    superSetItem temp;
    temp = superSet;

    deleteSet(&superSet, &set1);
    assert(temp -> set == &set3);
    temp = temp -> next;
    assert(temp -> set == &set2);
    temp = temp -> next;
    assert(temp == NULL);

    deleteSet(&superSet, &set3);
    temp = superSet;
    assert(temp -> set == &set2);
    temp = temp -> next;
    assert(temp == NULL);

    deleteSet(&superSet, &set2);

    assert(isEmptySuperSetItem(superSet));

    deleteSetItem(&set1);
    deleteSetItem(&set2);
    deleteSetItem(&set3);
}


