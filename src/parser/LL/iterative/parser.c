#include "parser.h"


#define VARIABLE_INDEX(s) (s - EXPR)
#define TERMINAL_INDEX(s) (s)


static entryTable parseTable[NUM_VARIABLES][NUM_TERMINALS] = {
        [VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(NUM)] = {},

};

static void SyntaxError(){
    fprintf(stderr, "An error has ocurred\n");
    exit(EXIT_FAILURE);
}

production * createProduction(enum labelTok head, enum labelTok body[], int longitud_array){

    production * temp = malloc(sizeof(struct production));
    if(!temp){
        fprintf(stderr, "An error has ocurred "
                        "while allocating memory for production\n");
        exit(EXIT_FAILURE);
    }
    temp -> head = head;
    temp -> body = malloc(sizeof(enum labelTok) * longitud_array);
    if(!(temp -> body)){
        fprintf(stderr, "An error has ocurred"
                        " while allocating memory for body of production\n");
        free(temp);
        exit(EXIT_FAILURE);
    }

    memcpy(temp -> body, body, sizeof(enum labelTok) * longitud_array);

    for(int i = 0; i< longitud_array; i++){
        assert(temp -> body[i] == body[i]);
    }
    temp -> longitud_body = longitud_array;
    return temp;
}


bool derivesEmptyString(enum labelTok head){
    if(IS_TERMINAL(head)){
        return false;
    }else{
        int i = 0;
        while(listProduction[i].head != EMPTY){
            if(listProduction[i].head == head){
                //longitud_body == 0 -> body = emptyString
                if(listProduction[i].longitud_body == 0){
                    return true;
                }
            }
            i++;
        }
        return false;
    }
}

static void auxFirst(enum labelTok head, listLabel *t){
    if(IS_TERMINAL(head)){
        if(!insertLabel(head, t)){
            fprintf(stderr, "An error has ocurred while inserting label in auxFirst\n");
            exit(EXIT_FAILURE);
        }
    }else{
        int i = 0;
        while(listProduction[i].head != EMPTY){
            if(listProduction[i].head == head){
                //estamos ante la produccion que buscabamos
                if(listProduction[i].longitud_body == 0){
                    //estamos ante la cadena vacia
                    insertLabel(EMPTY, t);
                }else{
                    //no estamos ante la cadena vacia
                    for(int j = 0; j < listProduction[i].longitud_body; j++){
                        auxFirst(listProduction[i].body[j], t);
                        if(derivesEmptyString(listProduction[i].body[j])){
                            goto endWhile;
                        }
                    }

                }
            }
            i++;
        }
        endWhile:
    }
}

listLabel first(enum labelTok head){
    listLabel t;
    createEmptyListLabel(&t);
    auxFirst(head, &t);
    return t;
}
