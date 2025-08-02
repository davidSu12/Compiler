#include "parser.h"


setItem * closure(setItem *st1){

    setItem *J = st1;
    bool added;
    NodeSetItem *temp;
    temp = *J;
    do{
        added = false;
        for(;temp != NULL; temp = temp -> next){

            item temp1 = temp -> data;
            uint32_t production = temp1.production;
            uint32_t setItem = temp1.item;
            int p_index = 0;

            while(setItem != 0){
                uint32_t isInSet = setItem & 1U;
                if(isInSet){

                    if(p_index < listProduction[production].longitud_body){
                        token nextToken = listProduction[production].body[p_index];
                        int index = 0;

                        if(IS_VARIABLE(nextToken)) {
                            while (listProduction[index].head != EMPTY) {
                                if (listProduction[index].head == nextToken) {
                                    added = addItem(J, (struct item) {index, 0});
                                    if (!added) {
                                        fprintf(stderr, "An error has ocurred "
                                                        "while adding item to set item in closure");
                                        exit(EXIT_FAILURE);
                                    }
                                }
                                index++;
                            }
                        }

                    }
                }
                p_index++;
                setItem >>= 1;
            }
        }
    }while(added);

    return J;
}

setItem * gotoFunction(setItem *st1, token tok){

    setItem *J_aux = malloc(sizeof(setItem));
    if(J_aux == NULL){
        fprintf(stderr, "An error has ocurred while allocating memory for J_aux in gotoFunction");
        exit(EXIT_FAILURE);
    }
    setItem temp;
    createEmptySetItem(J_aux);

    for(temp = *st1; temp != NULL; temp = temp -> next){
        item it = temp -> data;
        uint32_t production = it.production;
        uint32_t itemSet = it.item;
        int k_index = 0;

        while(itemSet != 0){
            uint32_t isInSet = (itemSet & 1U);
            if(isInSet){
                //aqui comprobamos si estamos ante esa clase de token
                if(k_index < listProduction[production].longitud_body){
                    token nextTok = listProduction[production].body[k_index];
                    if(nextTok == tok){
                        if(!addItem(J_aux, (struct item){production, k_index+1})){
                            fprintf(stderr, "An error has ocurred while adding item in gotoFunction");
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
            k_index++;
            itemSet >>= 1;

        }

    }

    return closure(J_aux);
}

superSetItem *canonicalSet(void){

    superSetItem *superSet = malloc(sizeof(superSetItem));
    if(superSet == NULL){
        fprintf(stderr, "An error has ocurred while allocating memory for superSetItem in canonicalSet");
        exit(EXIT_FAILURE);
    }

    return NULL;
}