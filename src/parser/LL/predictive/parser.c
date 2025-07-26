#include "parser.h"

static token lookahead;


void expr(){
    lookahead = getNextToken();
    term();
    exprP();

}
void exprP(){

    lookahead = getNextToken();
    if(lookahead -> label == PLUS){
        term();
        exprP();
    }else if(lookahead -> label == MINUS){
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
    lookahead = getNextToken();
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

    lookahead = getNextToken();
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
