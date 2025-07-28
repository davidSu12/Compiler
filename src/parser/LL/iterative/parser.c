#include "parser.h"



#define VARIABLE_INDEX(s) (s - EXPR)
#define TERMINAL_INDEX(s) (s)




production listProduction[] = {
        {EXPR, (enum labelTok[]){TERM, EXPRP}, 2},
        {EXPRP, (enum labelTok[]){PLUS, TERM, EXPRP}, 3},
        {EXPRP, (enum labelTok[]){MINUS, TERM, EXPRP}, 3},
        {EXPRP, NULL, 0},
        {TERM, (enum labelTok[]){FACTOR, TERMP}, 2},
        {TERMP, (enum labelTok[]){DOT, FACTOR, TERMP}, 3},
        {TERMP, (enum labelTok[]){DIV, FACTOR, TERMP}, 3},
        {TERMP, NULL, 0},
        {FACTOR, (enum labelTok[]){NUM},1},
        {FACTOR, (enum labelTok[]){LEFTPAR,EXPR,RIGHTPAR},3},
        {EMPTY, NULL, 0} //final de production
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

static void auxFirst(enum labelTok head, setLabel *t){

    //podemos mejorar esto muchisimo

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
                if(listProduction[i].longitud_body == 0){
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
