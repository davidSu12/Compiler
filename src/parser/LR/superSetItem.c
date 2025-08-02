#include "superSetItems.h"

void createEmptySuperSet(superSetItem *set){

    *set = NULL;
}
bool addSet(superSetItem *superSet, setItem *set){

    NodeSuperSetItem *temp = malloc(sizeof(struct NodeSuperSetItem));
    if(temp == NULL){
        fprintf(stderr,"An error has ocurred "
                       "while allocating memory for NodeSuperSet in addSet\n");
        exit(EXIT_FAILURE);
    }

    temp -> set = set;
    temp -> next = *superSet;
    (*superSet) = temp;
    return true;
}
void deleteSet(superSetItem *superSet, setItem *set){
    NodeSuperSetItem *prev, *curr;
    for(prev = NULL, curr = *superSet;
    curr != NULL && (curr -> set != set);
    prev = curr, curr = curr -> next);

    if(prev == NULL){
        (*superSet) = (*superSet) -> next;
    }else if(curr == NULL){
        return;
    }else{
        prev -> next = curr -> next;
    }
    free(curr);
}
bool isEmptySuperSetItem(superSetItem set){

    return set == NULL;
}

void deleteSuperSet(superSetItem *superSet){

    NodeSuperSetItem *temp;
    temp = *superSet;
    while(temp != NULL){
        deleteSetItem(temp -> set);
        (*superSet) = (*superSet) -> next;
        free(temp);
        temp = (*superSet);
    }
}

