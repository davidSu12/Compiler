#include "stack.h"



static stack st = NULL;

bool insertElement(nodeToken elemento){

    stack temp = malloc(sizeof(struct nodeStack));
    if(!temp){
        fprintf(stderr, "An error has ocurred while allocating memory for stack\n");
        exit(EXIT_FAILURE);
    }
    temp -> elemento = elemento;
    temp -> next = st;
    st = temp;
    return true;

}
nodeToken pop(){
    stack temp; nodeToken tokTemp;
    temp = st;
    tokTemp = st -> elemento;
    st = st -> next;
    free(temp);
    assert(tokTemp != NULL);
    return tokTemp;
}
nodeToken peek(){
    if(isEmptyStack()){
        fprintf(stderr, "stack is empty\n");
        return NULL;
    }
    else return st -> elemento;
}
bool isEmptyStack(){
    return st == LNULL;
}