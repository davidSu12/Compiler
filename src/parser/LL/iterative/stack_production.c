#include "stack_production.h"



static stackProduction stackProd;


bool pushLabel(enum labelTok label){
    nodeProduction * temp = malloc(sizeof(struct nodeProduction));
    if(!temp){
        fprintf(stderr, "An error has ocurred while"
                        "allocating memory for pushLabel\n");
        return false;
    }
    temp -> item = label;
    temp -> next = stackProd;
    stackProd = temp;
    assert(stackProd != NULL);
    return true;
}

bool pushProduction(production el){
    for(int i = (el.longitud_body)-1; i >= 0; i--){
        enum labelTok temp = el.body[i];
        if(!pushLabel(temp)){
            int j = (el.longitud_body) - i;
            while(j != 0){
                popLabel();
                j--;
            }
            return false;
        }

    }

#ifdef DEBUG
    printStack();
#endif
    assert(stackProd != NULL);
    return true;
}

enum labelTok peekLabel(){
    if(isEmptyStack()){
        fprintf(stderr, "Stack of labels is empty\n");
        return -1;
    }
    return stackProd -> item;
}

bool isEmptyStack(){
    return stackProd == NULL;
}

void popLabel(){
    nodeProduction *temp;
    if(isEmptyStack()){
        return;
    }
    temp = stackProd;
    stackProd = stackProd -> next;
    free(temp);


}

void printStack(){

    nodeProduction * temp;
    temp = stackProd;
    while(temp != NULL){
        printf("%d ", temp -> item);
        temp = temp -> next;
    }
    printf("\n");
}

void createEmptyStackProd(){
    stackProd = NULL;
}