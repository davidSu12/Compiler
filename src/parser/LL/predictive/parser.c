#include "parser.h"

static token lookahead;


void expr(){
    lookahead = getNextToken();
    term();
    exprP();

}
void exprP(){
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
void term(){
    factor();
    termP();

}
void termP(){
    if(lookahead == NULL){
        return;
    }
    if(lookahead -> label == DOT){
        factor();
        termP();
    }else if(lookahead -> label == DIV){
        factor();
        termP();
    }else{
        return;
    }
}
void factor(){
    if(lookahead -> label == NUM){
        lookahead = getNextToken();
    }else{
        match(LEFTPAR);
        expr();
        match(RIGHTPAR);
    }
}
void match(enum labelTok tok){

    if(tok != lookahead -> label){
        fprintf(stderr, "Syntax error. Aborting compilation\n");
        exit(EXIT_FAILURE);
    }else{
        lookahead = getNextToken();
    }
}
