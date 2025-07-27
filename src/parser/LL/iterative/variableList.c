#include "variableList.h"


void createEmptyListLabel(listLabel * list){
    *list = NULL;
}
bool isEmptyListLabel(listLabel list){
    return list == NULL;
}
bool insertLabel(enum labelTok label, listLabel * list){
    nodeLabel *temp = malloc(sizeof(struct nodeLabel));
    if(!temp){
        fprintf(stderr, "An error has ocurred while "
                        "allocating memory for label on variableList.h");
        exit(EXIT_FAILURE);
    }

    temp -> item = label;
    temp -> next = *list;
    *list = temp;
    return true;
}
void deleteLabel(enum labelTok label, listLabel * list){

    if(isEmptyListLabel(*list)){
        return;
    }

    positionLabel prev, curr;
    for(
            prev = NULL, curr = *list;
            (curr != NULL) && (curr -> item != label)
            ;prev = curr, curr = curr -> next);

    if(prev == NULL){
        //label is in curr
        *list = (*list) -> next;
    }else if(curr == NULL){
        //label is not in list
        return;
    }else{
        prev -> next = curr -> next;
    }
    free(curr);
}
positionLabel searchLabel(enum labelTok label, listLabel list){
    if(isEmptyListLabel(list)){
        //list is empty so we return inmediatly
        return NULL;
    }

    positionLabel temp = list;
    while(temp != NULL && temp -> item != label) temp = temp -> next;
    return temp;

}