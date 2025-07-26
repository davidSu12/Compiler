#include "parser.h"

static token lookahead;


void expr(){

    lookahead = getNextToken();

    if(lookahead -> label == LEFTPAR){
        expr();
        match(RIGHTPAR);
    }else{
        term();
        exprP();
    }

}
void exprP(){

}
void term(){


}
void termP(){

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
    lookahead = getNextToken();
    if(tok != lookahead -> label){
        fprintf(stderr, "Syntax error. Aborting compilation\n");
        exit(EXIT_FAILURE);
    }else{
        lookahead = getNextToken();
    }
}
