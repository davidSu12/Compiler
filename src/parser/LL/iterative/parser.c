#include "parser.h"




static void SyntaxError(){
    fprintf(stderr, "Syntax error\n");
    exit(EXIT_FAILURE);
}

production * createProduction(token head, token body[], int longitud_array){

    production * temp = malloc(sizeof(struct production));
    if(!temp){
        fprintf(stderr, "An error has ocurred "
                        "while allocating memory for production\n");
        exit(EXIT_FAILURE);
    }
    temp -> head = head;
    temp -> body = malloc(sizeof(token) * longitud_array);
    if(!(temp -> body)){
        fprintf(stderr, "An error has ocurred"
                        " while allocating memory for body of production\n");
        free(temp);
        exit(EXIT_FAILURE);
    }

    memcpy(temp -> body, body, sizeof(token) * longitud_array);

    for(int i = 0; i< longitud_array; i++){
        assert(temp -> body[i] == body[i]);
    }
    temp -> longitud_body = longitud_array;
    return temp;
}


bool derivesEmptyString(token head){
    if(IS_TERMINAL(head)){
        return false;
    }else{
        int i = 0;
        while(listProduction[i].head != EMPTY){
            if(listProduction[i].head == head){
                //longitud_body == 0 -> body = emptyString
                if(listProduction[i].longitud_body > 0){
                    /*In this case the this is just a preventive
                     comprobation since we could have listProduction[i].longitud == 0
                     so this is just to check errors
                     */
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

static void auxFirst(token head, setLabel *t){


    if(IS_TERMINAL(head)){
        if(!addLabel(head, t)){
            fprintf(stderr, "An error has ocurred while inserting label in auxFirst\n");
            exit(EXIT_FAILURE);
        }

        return;
    }else{
        int i = 0;
        while(listProduction[i].head != EMPTY){

            //estamos ante la produccion que buscabamos
            if(listProduction[i].head == head){

                if(listProduction[i].body[0] == EMPTY){
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



static void auxFollow(token head, setLabel *t){
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
setLabel first(token head){
    setLabel t;
    createEmptySetLabel(&t);
    auxFirst(head, &t);
    return t;
}

setLabel follow(token head){
    setLabel t;
    createEmptySetLabel(&t);
    auxFollow(head, &t);
    return t;

}


void initParseTable(void){

#ifdef DEBUG
    assert(TERMINAL_INDEX(FIRST_TERMINAL) == 0);
    assert(TERMINAL_INDEX(LAST_TERMINAL) == 6);
#endif
    int i = 0;

    while(listProduction[i].head != EMPTY){

        setLabel temp = first_production(listProduction[i]);
        setLabel tempFollow = follow(listProduction[i].head);


        for(int j = TERMINAL_INDEX(FIRST_TERMINAL); j <= TERMINAL_INDEX(LAST_TERMINAL); j++){
            //paso1
            if(searchLabel( (token)j, temp )){
                parseTable[VARIABLE_INDEX(listProduction[i].head)][j] = &listProduction[i];

            }

            //paso2
            if(searchLabel(EMPTY, temp)) {
                for (int k = TERMINAL_INDEX(FIRST_TERMINAL); k <= TERMINAL_INDEX(LAST_TERMINAL); k++) {
                    if(searchLabel((token) k, tempFollow)) {
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

    initParseTable();
    createEmptyStackProd();
    nodeToken tok = getNextToken();

    if(!pushLabel(EXPR)){
        fprintf(stderr, "An error has ocurred while doing "
                        "a push on parse function on iterative parser");
        exit(EXIT_FAILURE);
    }


    while(!isEmptyStack()){

        printStack();

        if(tok == NULL && IS_TERMINAL(peekLabel())){
            SyntaxError();
        }else if(tok == NULL && !IS_TERMINAL(peekLabel())){
            while(!IS_TERMINAL(peekLabel())){
                popLabel();
                if(isEmptyStack()){
                    break;
                }
            }
        }else if(peekLabel() == EMPTY){
            popLabel();
        }else if(IS_TERMINAL(peekLabel()) && (peekLabel() == tok -> label)){
            popLabel();
            tok = getNextToken();
        }else if(IS_TERMINAL(peekLabel()) && (peekLabel() != tok -> label)){
            SyntaxError();
        }else if(parseTable[VARIABLE_INDEX(peekLabel())][TERMINAL_INDEX(tok -> label)] == NULL){
            SyntaxError();
        }else if(parseTable[VARIABLE_INDEX(peekLabel())][TERMINAL_INDEX(tok -> label)] != NULL){

            token temp = peekLabel();
            popLabel();
            if(!pushProduction(*parseTable[VARIABLE_INDEX(temp)][TERMINAL_INDEX(tok -> label)])){
                fprintf(stderr, "An error has ocurred while pushing production on parse function");
                exit(EXIT_FAILURE);
            }
        }
    }

    if((getNextToken() == NULL)) return true;
    return false;
}