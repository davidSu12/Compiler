#include "parser.h"
#include "parseTable.h"

production listProduction[] = {
        {EXPR, (enum labelTok[]){TERM, EXPRP}, 2},
        {EXPRP, (enum labelTok[]){PLUS, TERM, EXPRP}, 3},
        {EXPRP, (enum labelTok[]){MINUS, TERM, EXPRP}, 3},
        {EXPRP, (enum labelTok[]){EMPTY}, 1},
        {TERM, (enum labelTok[]){FACTOR, TERMP}, 2},
        {TERMP, (enum labelTok[]){DOT, FACTOR, TERMP}, 3},
        {TERMP, (enum labelTok[]){DIV, FACTOR, TERMP}, 3},
        {TERMP, (enum labelTok[]){EMPTY}, 1},
        {FACTOR, (enum labelTok[]){NUM},1},
        {FACTOR, (enum labelTok[]){LEFTPAR,EXPR,RIGHTPAR},3},
        {EMPTY, NULL, 0} //final de production
};

production *parseTable[NUM_VARIABLES][NUM_TERMINALS] = {NULL};

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
                if(listProduction[i].longitud_body > 0){
                    if(listProduction[i].body[0] == EMPTY){
                        return true;
                    }
                }
            }
            i++;
        }
        return false;
    }
}

static void auxFirst(enum labelTok head, setLabel *t){

#ifdef DEBUG
    printf("\nhead:%d\n", head);
#endif
    if(IS_TERMINAL(head)){
        if(!addLabel(head, t)){
            fprintf(stderr, "An error has ocurred while inserting label in auxFirst\n");
            exit(EXIT_FAILURE);
        }
#ifdef DEBUG
        printf("\ninsertamos: %d\n", head);
#endif
        return;
    }else{
        int i = 0;
        while(listProduction[i].head != EMPTY){
#ifdef DEBUG
            printf("\ni:%d\n",i);
#endif
            if(listProduction[i].head == head){
                //estamos ante la produccion que buscabamos
                if(listProduction[i].longitud_body == 1 && listProduction[i].body[0]){
                    //estamos ante la cadena vacia
                    addLabel(EMPTY, t);
                }else{
                    //no estamos ante la cadena vacia
                    for(int j = 0; j < listProduction[i].longitud_body; j++){

                        auxFirst(listProduction[i].body[j], t);

                        if(!derivesEmptyString(listProduction[i].body[j])){
                            break;
                        }
                    }
                }
            }
            i++;
        }
    }
}



static void auxFollow(enum labelTok head, setLabel *t){
    int i = 0;
    if(head == EXPR){
        if(!addLabel($, t)){
            fprintf(stderr, "An error has ocurred while "
                            "inserting label in t");
            return;
        }
    }
    while(listProduction[i].head != EMPTY){
            for(int j = 0; j < listProduction[i].longitud_body; j++){
                if(listProduction[i].body[j] == head){
                    //caso1
                    if(j < listProduction[i].longitud_body-1){

                        //tenemos que considerar todas las reglas aqui
                        setLabel temp = first(listProduction[i].body[j+1]);
                        if(searchLabel(EMPTY, temp)){
                            setLabel temp1 = follow(listProduction[i].head);
                            unionSet(t, &temp1);
                        }
                        //aqui no añadimos empty
                        temp[EMPTY] = false;
                        unionSet(t, &temp);
                        break;
                    }else{ //caso2
                        if(listProduction[i].head != head){
                            setLabel temp = follow(listProduction[i].head);
                            unionSet(t, &temp);
                            break;
                        }
                    }

                }
            }
            i++;
    }

}
setLabel first(enum labelTok head){
    setLabel t;
    createEmptySetLabel(&t);
    auxFirst(head, &t);
    return t;
}

setLabel follow(enum labelTok head){
    setLabel t;
    createEmptySetLabel(&t);
    auxFollow(head, &t);
    return t;

}


void initParseTable(void){

    assert(TERMINAL_INDEX(FIRST_TERMINAL) == 0);
    assert(TERMINAL_INDEX(LAST_TERMINAL) == 6);
    int i = 0;

    while(listProduction[i].head != EMPTY){

        setLabel temp = first_production(listProduction[i]);
        setLabel tempFollow = follow(listProduction[i].head);


        for(int j = TERMINAL_INDEX(FIRST_TERMINAL); j <= TERMINAL_INDEX(LAST_TERMINAL); j++){
            //paso1
            if(searchLabel( (enum labelTok)j, temp )){
                parseTable[VARIABLE_INDEX(listProduction[i].head)][j] = &listProduction[i];
#ifdef DEBUG
                if(i == 1){
                    if(j == 3){
                        printf("Estoy aqui");
                        assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(PLUS)] == &listProduction[1]);
                    }
                }
#endif
            }

            //paso2
            if(searchLabel(EMPTY, temp)) {
                for (int k = TERMINAL_INDEX(FIRST_TERMINAL); k <= TERMINAL_INDEX(LAST_TERMINAL); k++) {
                    if(searchLabel((enum labelTok) k, tempFollow)) {
                        parseTable[VARIABLE_INDEX(listProduction[i].head)][k] = &listProduction[i];
                    }
                }
            }
        }
        deleteLabelSet(&temp);
        deleteLabelSet(&tempFollow);
        i++;
    }

#ifdef DEBUG
    printf("Estoy aqui");
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(PLUS)] == &listProduction[1]);
#endif
}

static void auxfirst_production(production p, setLabel *t){

    if(p.longitud_body == 1 && p.body[0] == EMPTY){
        addLabel(EMPTY, t);
        return;
    }
    for(int i = 0; i < p.longitud_body; i++){
        setLabel temp = first(p.body[i]);
        unionSet(t, &temp);
        if(!derivesEmptyString(p.body[i])){
            break;
        }
    }
}

setLabel first_production(production p){

    setLabel t;
    createEmptySetLabel(&t);
    auxfirst_production(p, &t);
    return t;

}

bool parse(){
    token tok = getNextToken();
    if(!pushLabel(EXPR)){
        fprintf(stderr, "An error has ocurred while doing "
                        "a push on parse function on iterative parser");
        exit(EXIT_FAILURE);
    }
    while(!isEmptyStack()){
        if(peekLabel() == tok -> label){
            popLabel();
            tok = getNextToken();
        }else if(IS_TERMINAL(peekLabel())){
            SyntaxError();
        }else if(parseTable[peekLabel()][tok -> label] == NULL){
            SyntaxError();
        }else if(parseTable[peekLabel()][tok -> label] != NULL){
            enum labelTok temp = peekLabel();
            popLabel();
            if(!pushProduction(*(parseTable[temp][tok -> label]))){
                fprintf(stderr, "An error has ocurred while pushing production on parse function");
                exit(EXIT_FAILURE);
            }
        }
    }
    if((getNextToken() == NULL) && isEmptyStack()){
        return true;
    }else{
        return false;
    }

}