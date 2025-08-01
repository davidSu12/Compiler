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
setItem gotoFunction(setItem *st1, enum labelTok token){

    return NULL;
}
