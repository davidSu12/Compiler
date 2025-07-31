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

    temp -> data.item = 0; //inicializamos el conjunto

    if(isEmptySetItem(*st1)){
        temp -> data.production = it.production;
        temp -> data.item = INSERT_ELEMENT(temp -> data.item, it.item);
        temp -> next = NULL;
        *st1 = temp;
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
            temp -> data.item = INSERT_ELEMENT(temp -> data.item, it.item);

        }else{

            /*
             * aqui tenemos que considerar dos casos completamente separados
             * curr.production es igual a it.production o desigual
             */
            if(curr -> data.production == it.production){
                curr -> data.item = INSERT_ELEMENT(curr -> data.item, it.item);
                assert(ELEMENT_IN_SET(curr -> data.item, it.item) != 0);
                free(temp);
            }else{
                //es mayor entonces prev es el anterior
                prev -> next = temp;
                temp -> next = curr;
                temp -> data.production = it.production;
                temp -> data.item = INSERT_ELEMENT(temp -> data.item, it.item);
                assert(ELEMENT_IN_SET(temp -> data.item, it.item) != 0);

            }
        }

    }

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


setItem * unionSetItems(setItem *st1, setItem *st2){

    NodeSetItem *temp1, *temp2, *temp3, *temp4;
    NodeSetItem * prev_temp1 = NULL;
    NodeSetItem * final_list = NULL;
    NodeSetItem * temp_list = NULL;

    temp1 = *st1;
    temp2 = *st2;


    if(temp1 == NULL){
        return st2;
    }

    if(temp2 == NULL){
        return st1;
    }

    if(temp1 -> data.production < temp2 -> data.production){
        final_list = temp1;
        prev_temp1 = temp1;
        temp1 = temp1 -> next;
    }else if(temp1 -> data.production > temp2 -> data.production){
        final_list = temp2;
        temp2 = temp2 -> next;
    }else{
        temp3 = temp2;
        temp1 -> data.item  = UNION_SET(temp1 -> data.item, temp2 -> data.item);
        final_list = temp1;
        temp2 = temp2 -> next;
        free(temp3);
    }

    temp_list = final_list;

    while(temp1 != NULL){

        if(temp2 == NULL){
            return st1;
        }

        if(temp1 -> data.production < temp2 -> data.production){
            temp_list -> next = temp1;
            temp1 = temp1 -> next;
        }else if(temp1 -> data.production > temp2 -> data.production){
            temp_list -> next = temp2;
            temp2 = temp2 -> next;
        }else{
            temp_list -> next = temp1;
            temp1 -> data.item = UNION_SET(temp1 -> data.item, temp2 -> data.item);
            temp3 = temp2;
            temp2 = temp2 -> next;
            free(temp3);

        }
    }


    prev_temp1 -> next = temp2;
    return st2;
}

void printSetItem(setItem st1, void (*viewBinary)(uint32_t d)){
    NodeSetItem *temp1;
    if(viewBinary == NULL){
        for(temp1 = st1; temp1 != NULL; temp1 = temp1 -> next){
            printf("production: %d\nitemSet: %d\n", temp1 -> data.production, temp1->data.item);
        }
    }else{
        for(temp1 = st1; temp1 != NULL; temp1 = temp1 -> next){
            printf("======\n");
            printf("production: %d\nitemSet: %d\n", temp1 -> data.production, temp1->data.item);
            printf("set:");
            viewBinary(temp1 -> data.item);
            printf("\n");
            printf("======\n");
        }
    }
}

NodeSetItem * getSetProduction(setItem st1, uint32_t num_production){

    NodeSetItem *temp;
    for(temp = st1; temp != NULL && (temp -> data.production != num_production); temp = temp -> next);
    return temp;
}