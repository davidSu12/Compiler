#include "parser.h"


static nodeToken lookahead;
static nodeTree * EXPRNODE; //this is our ast tree
static nodeTree * EXPRPNODE;
static nodeTree * EXPRINHERITED;
static nodeTree * TERMNODE;
static nodeTree * TERMPINHERITED;
static nodeTree * TERMPNODE;
static nodeTree * FACTORNODE;
static nodeTree * FACTORSYN;
static nodeTree * EXPRPINHERITED;


static void SyntaxError(void) {
    fprintf(stderr, "Syntax error\n");
    exit(EXIT_FAILURE);

}
void initParser(){
    lookahead = getNextToken();
}

bool parse(void){
    initParser();
    expr();
    if(lookahead == NULL){
        return true;
    }else{
        SyntaxError();
    }
}

void expr(void){
    term();
    EXPRPINHERITED = TERMNODE;
    exprP();
    EXPRNODE = EXPRPNODE;
}
void exprP(void){

    if(lookahead == NULL){
        return;
    }

    nodeTree * node = malloc(sizeof(struct nodeTree));

    if(node == NULL){
        fprintf(stderr,
                "An error has ocurred on %s in %s in line %d",
                __func__,
                __FILE__,
                __LINE__);
        exit(EXIT_FAILURE);
    }

    if(lookahead -> label == PLUS){
        node -> type = INTERIOR_NODE;
        node -> entry.operation = PLUS;
        node -> left = EXPRPINHERITED;
        match(PLUS);
        term();
        node -> right = TERMNODE;
        EXPRPINHERITED = node;
        exprP();
    }else if(lookahead -> label == MINUS){
        node -> type = INTERIOR_NODE;
        node -> entry.operation = MINUS;
        node -> left = EXPRPINHERITED;
        match(MINUS);
        term();
        node -> right = TERMNODE;
        EXPRINHERITED = node;
        exprP();
    }else{
        EXPRPNODE = EXPRPINHERITED;
        return;
    }


}
void term(void){

    factor();
    TERMPINHERITED = FACTORNODE;
    termP();
    TERMNODE = TERMPNODE;

}
void termP(void){

    if(lookahead == NULL){
        return;
    }

    nodeTree * node = malloc(sizeof(struct nodeTree));

    if(node == NULL){
        fprintf(stderr,
                "An error has ocurred on %s in %s in line %d",
                __func__,
                __FILE__,
                __LINE__);
        exit(EXIT_FAILURE);
    }
    if(lookahead -> label == DOT){

        node -> type = INTERIOR_NODE;
        node -> entry.operation = DOT;
        node -> left = TERMPINHERITED;
        match(DOT);
        factor();
        node -> right = FACTORNODE;
        TERMPINHERITED = node;
        termP();

    }else if(lookahead -> label == DIV){
        node -> type = INTERIOR_NODE;
        node -> entry.operation = DIV;
        node -> left = TERMPINHERITED;
        match(DIV);
        factor();
        node -> right = FACTORNODE;
        TERMPINHERITED = node;
        termP();
    }else{
        TERMPNODE = TERMPINHERITED;
        return;
    }

}
void factor(void){

    if(lookahead == NULL){
        return;
    }
    if(lookahead -> label == NUM){
        nodeTree * node = malloc(sizeof(struct nodeTree));
        if(node == NULL){

            fprintf(
                    stderr,
                    "An error has ocurred on %s in %s in line %d",
                    __func__,
                    __FILE__,
                    __LINE__);

            exit(EXIT_FAILURE);
        }

        node -> type = LEAF_NODE;
        node -> entry.lexeme = malloc(sizeof(char) * strlen(lookahead -> element.lexeme));

        if(node -> entry.lexeme == NULL){
            fprintf(stderr,
                    "An error has ocurred on %s in %s in line %d",
                    __func__,
                    __FILE__,
                    __LINE__);
            exit(EXIT_FAILURE);
        }
        strcpy(node -> entry.lexeme, lookahead -> element.lexeme);
        FACTORNODE = node;

        match(NUM);
    }else if(lookahead -> label == LEFTPAR){
        match(LEFTPAR);
        expr();
        FACTORNODE = EXPRNODE;
        match(RIGHTPAR);
    }else{


        SyntaxError();
    }
}
void match(token simbolo){
    if(lookahead == NULL){
        SyntaxError();
    }

    if(lookahead -> label == simbolo){
        lookahead = getNextToken();
    }else{
        SyntaxError();
    }
}

