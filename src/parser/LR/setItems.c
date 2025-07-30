#include "setItems.h"

void createEmptySetItem(setItem *st1){

    *st1 = calloc(NUM_PRODUCCIONES, sizeof(uint32_t));

    if(*st1 == NULL){
        fprintf(stderr, "An error has ocurred while allocating memory for setItem\n");
        exit(EXIT_FAILURE);
    }
}

setItem * unionSetItems(setItem *st1, setItem *st2){
    if(isEmptySetItem(*st1)){
        return st2;
    }else{
        for(int i = 0; i < NUM_PRODUCCIONES; i++){
            (*st1)[i] = UNION_SET( (*st1)[i] , (*st2)[i] );
        }
        deleteSetItem(st2);
    }
    return st1;
}
void deleteSetItem(setItem *st1){
    free(*st1);
    *st1 = NULL;
}




bool addItem(setItem *st1, item it){

    if(isEmptySetItem(*st1)){
        return false;
    }

    (*st1)[it.production] = INSERT_ELEMENT((*st1)[it.production], it.item);

#ifdef DEBUG
    printf("%u", (bool)((*st1)[it.production] & (1U << it.item)));
#endif
    assert(((*st1)[it.production] & (1U << it.item)) != 1U);

    return true;
}
bool itemInSet(setItem st1, item it){
    return (bool) ELEMENT_IN_SET(st1[it.production], it.item);
}

bool isEmptySetItem(setItem st1){
    return st1 == NULL;
}

void deleteItem(setItem *st1, item it){

    if(isEmptySetItem(*st1)){
        return;
    }

    (*st1)[it.production]  = DELETE_ELEMENT((*st1)[it.production], it.item);

    assert(((*st1)[it.production] & (1U << it.item)) == 0);
}