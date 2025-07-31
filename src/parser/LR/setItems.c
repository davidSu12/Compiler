#include "setItems.h"


void createEmptySetItem(setItem *st1){
    *st1 = NULL;
}
bool isEmptySetItem(setItem st1){
    return st1 == NULL;
}

bool addItem(setItem *st1, item it){

    NodeSetItem *prev, *curr;
    NodeSetItem *temp = malloc(sizeof(struct NodeSetItem));

    if(temp == NULL){
        fprintf(stderr, "An error has ocurred while allocating memory for NodeSetItem");
        exit(EXIT_FAILURE);
    }

    if(isEmptySetItem(*st1)){
        temp -> data.production = it.production;
        temp -> data.item = it.item;
        temp -> next = NULL;
    }else{

        for(prev = NULL, curr = *st1;
            (curr != NULL) && (it.production > curr ->data.production);
            prev = curr, curr = curr -> next);

        if(curr == NULL){
            /*
             * estamos en el final de manera que no nos queda otra que añadir en el final
             */
            prev -> next = temp;
            temp -> next = NULL;
            temp -> data.production = it.production;
            temp -> data.item = it.item;

        }else if(prev == NULL){
            temp -> next = *st1;
            temp -> data.production = it.production;
            temp -> data.item = it.item;
            *st1 = temp;
        }else{

            /*
             * aqui tenemos que considerar dos casos completamente separados
             * curr.production es igual a it.production o desigual
             */
            if(curr -> data.production == it.production){
                curr -> data.item |= it.item;
                free(temp);
            }else{
                //es mayor entonces prev es el anterior
                prev -> next = temp;
                temp -> next = curr;
                temp -> data.production = it.production;
                temp -> data.item = it.item;


            }
        }

    }

    assert(ELEMENT_IN_SET(temp -> data.item, it.item) == 0);
    return true;

}

bool itemInSet(setItem st1, item it){

    NodeSetItem *temp;

    if(isEmptySetItem(st1)){
        return false;
    }


    for(temp = st1 ;temp != NULL && (temp -> data.production != it.production); temp = temp -> next);

    if(temp == NULL){
        return false;
    }else{
        if( ELEMENT_IN_SET(temp -> data.item, it.item)  != 0 ){
            return true;
        }
    }
    return false;
}

void deleteItem(setItem *st1, item it){
    NodeSetItem *temp;

    if(isEmptySetItem(*st1)){
        return;
    }
    for(temp = *st1; temp != NULL && (temp -> data.production != it.production); temp = temp -> next);

    if(temp == NULL){
        return;
    }else{

        temp -> data.item = DELETE_ELEMENT(temp -> data.item, it.item);
        assert(ELEMENT_IN_SET(temp -> data.item, it.item) == 0);
    }

}

void deleteSetItem(setItem *st1){

    NodeSetItem *temp = *st1;

    while(temp != NULL){
        *st1 = (*st1) -> next;
        free(temp);
        temp = *st1;
    }

    assert(*st1 == NULL);
}