#include "setLabel.h"


void createEmptySetLabel(setLabel *set){
    *set = calloc(MAX_LEN_SET, sizeof(bool));
    if(*set == NULL){
        fprintf(stderr, "No more memory to create setLabel\n");
        exit(EXIT_FAILURE);
    }
}
bool isEmptySetLabel(setLabel set){
    return set == NULL;
}
bool addLabel(enum labelTok label, setLabel * set){
    if(isEmptySetLabel(*set)){
        fprintf(stderr, "Set not initialized");
        exit(EXIT_FAILURE);
    }
    (*set)[label] = true;
    return true;
}
void deleteLabel(enum labelTok label, setLabel * set){
    if(isEmptySetLabel(*set)){
        return;
    }
    (*set)[label] = false;
}
bool searchLabel(enum labelTok label, setLabel set){
    if(isEmptySetLabel(set)){
        return false;
    }
    return set[label];
}
void printSetLabel(setLabel t){
    if(isEmptySetLabel(t)){
        return;
    }else{
        for(int i = 0; i< MAX_LEN_SET; i++){
            if(t[i]){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
setLabel *unionSet(setLabel *set1, setLabel *set2){
    if(isEmptySetLabel(*set1)){
        set1 = set2;
    }else{
        for(int i = 0; i < MAX_LEN_SET; i++){
            if(!(*set1)[i]){
                (*set1)[i] = (*set2)[i];
            }
        }
        deleteLabelSet(set2);
    }
    return set1;
}
void deleteLabelSet(setLabel *set){
    free(*set);
    *set = NULL;
}
