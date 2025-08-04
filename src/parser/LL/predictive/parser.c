#include "parser.h"


static nodeToken lookahead;

/**
 * auxiliar function to raise a syntax error
 */
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
    exprP();
}
void exprP(void){

    if(lookahead == NULL){
        return;
    }
    if(lookahead -> label == PLUS){
        match(PLUS);
        term();
        exprP();
    }else if(lookahead -> label == MINUS){
        match(MINUS);
        term();
        exprP();
    }else{
        return;
    }


}
void term(void){

    factor();
    termP();

}
void termP(void){

    if(lookahead == NULL){
        return;
    }
    if(lookahead -> label == DOT){
        match(DOT);
        factor();
        termP();
    }else if(lookahead -> label == DIV){
        match(DIV);
        factor();
        termP();
    }else{
        return;
    }

}
void factor(void){

    if(lookahead == NULL){
        return;
    }
    if(lookahead -> label == NUM){

        match(NUM);

    }else if(lookahead -> label == LEFTPAR){
        match(LEFTPAR);
        expr();
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

