#include "parser.h"


setItem * closure(setItem *st1){
    setItem J;
    createEmptySetItem(&J);
    unionSetItems(&J, st1);

    bool added;
    do{
        added = false;
        for(int i = 0; i < NUM_PRODUCCIONES; i++){
            uint32_t temp = J[i]; //guardo el set temporalmente.
            while(temp != 0){
                int k_index = 0;
                int j = 0;
                j = temp & 1U; // el indice j se encuentra si o no en el conjunto
                if(j == 1){
                    item temp_item = (struct item){i,k_index};
                    if(!itemInSet(J, temp_item)){
                        addItem(&J,temp_item);
                        added = true;
                    }
                }
                temp = temp >> 1;
                k_index++;
                j = 0;

            }
        }
    }while(!added);
    return &J;
}
setItem * gotoFunction(setItem *st1, enum labelTok token){
    return NULL;
}