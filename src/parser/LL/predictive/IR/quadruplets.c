#include "quadruplets.h"

void createEmptyQuadrupletList(quadrupletList * list){
    (*list).first = (*list).last = NULL;
}
nodeQuadruplet * createNodeQuadruplet(token operation, char * arg1, char * arg2, char * result){

    nodeQuadruplet * temp = malloc(sizeof(struct nodeQuadruplet));
    char * arg1_new = strdup(arg1);
    char * arg2_new = strdup(arg2);
    char * arg3_new = strdup(result);

    if(!temp || !arg1_new || !arg2_new || !arg3_new){
        fprintf(
                stderr,
                "An error has ocurred on func:%s\non:%s\nin line:%d\n",
                __func__,
                __FILE__,
                __LINE__);
        exit(EXIT_FAILURE);
    }
    temp -> item.operation = operation;
    temp -> item.arg1 = arg1;
    temp -> item.arg2 = arg2;
    temp -> item.result = result;

    return temp;
}
bool insertNodeQuadruplet(quadrupletList * list, nodeQuadruplet *node){

    if(isEmptyListQuadruplets(*list)){
        list -> first = list -> last = node;
        node -> next = NULL;
    }else{
        nodeQuadruplet *last = list -> last;
        last ->next = node;
        node -> next = NULL;
        list -> last = node;
    }
    return true;
}
void deleteListQuadruplet(quadrupletList * list){

    nodeQuadruplet * temp;
    temp = list -> first;
    while(temp != NULL){
        list -> first = list -> first -> next;
        free(temp);
        temp = list -> first;
    }
    assert(list -> first == NULL);
    list -> last = list -> first;

}
bool isEmptyListQuadruplets(quadrupletList l){
    return l.first == NULL && l.last == NULL;
}
