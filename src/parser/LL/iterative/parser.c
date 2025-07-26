#include "parser.h"


static production * parseTable[NUM_TERMINALS][NUM_VARIABLES];




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
    for(int i = 0; i < longitud_array; i++){
        temp -> body[i] = body[i];
    }
    temp -> longitud_body = longitud_array;
    return temp;

    return NULL;
}
void initParseTable(void){

    return;
}