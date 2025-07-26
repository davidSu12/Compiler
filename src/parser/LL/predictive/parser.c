#include "parser.h"


static token lookahead;


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
bool expr(void){
#ifdef DEBUG
    fprintf(stdout, "expr()\n");
#endif
    term();exprP();
    return true;
}
void exprP(void){
#ifdef DEBUG
    fprintf(stdout, "exprP()\n");
#endif
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
    }else if(lookahead != NULL){
        SyntaxError();
    }else{
        //we are in the empty string
        return;
    }

}
void term(void){
#ifdef DEBUG
    fprintf(stdout, "term()\n");
#endif
    factor();
    termP();

}
void termP(void){
#ifdef DEBUG
    fprintf(stdout, "termP()\n");
#endif
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
    }else if(lookahead != NULL){
        SyntaxError();
    }else{
        return;
    }

}
void factor(void){
#ifdef DEBUG
    fprintf(stdout, "factor()\n");
#endif
    if(lookahead == NULL){
        return;
    }
    if(lookahead -> label == NUM){
#ifdef DEBUG
        printf("%s\n",lookahead->element.lexeme);
#endif
        match(NUM);

    }else if(lookahead -> label == LEFTPAR){
        match(LEFTPAR);
        expr();
        match(RIGHTPAR);
    }else{

#ifdef DEBUG
        fprintf(stderr, "Error in factor\n");
        fprintf(stderr, "%c\n", simbToChar(lookahead -> label));
#endif
        SyntaxError();
    }
}
void match(enum labelTok simbolo){
    if(lookahead == NULL){
        SyntaxError();
    }
#ifdef DEBUG
    fprintf(stdout, "match()\n");
#endif
    if(lookahead -> label == simbolo){
        lookahead = getNextToken();
    }else{
#ifdef DEBUG
        fprintf(stderr, "Error in factor");
#endif
        SyntaxError();
    }
}

