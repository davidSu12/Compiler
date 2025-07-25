#include "lexer.h"





static char buff[MAX_LEN_BUFF];
static char * lexemeBegin;
static char * currPosition;
static ListToken list;



void initBuffer(){
    memset(buff, (char)END, MAX_LEN_BUFF);
    fgets(buff, MAX_LEN_BUFF -1, stdin);
    lexemeBegin = currPosition = buff;
}

void printBuffer(){
    printf("%s",buff);
}


char simbToChar(const enum labelTok m){

    switch(m){
        case PLUS:return '+';break;
        case MINUS:return '-';break;
        case DOT:return '*'; break;
        case DIV:return '/'; break;
        case LEFTPAR:return'(';break;
        case RIGHTPAR:return ')';break;
    }
}
token getNextToken(){


    if(*currPosition == END || *currPosition == '\n'){
        return NULL;
    }
    token temp = malloc(sizeof(struct node));
    if(!temp){
        fprintf(stderr, "Error in getNextToken (No more memory available)\n");
        exit(EXIT_FAILURE);
    }
    //have to define a simple state machine
    if(!isdigit(*currPosition)){

        switch(*currPosition){
            case '+':temp -> element.simb = PLUS;break;
            case '-':temp -> element.simb = MINUS;break;
            case '*':temp -> element.simb = DOT;break;
            case '/':temp -> element.simb = DIV;break;
            case '(':temp -> element.simb = LEFTPAR;break;
            case ')':temp -> element.simb = RIGHTPAR;break;
            default:{
                fprintf(stderr, "Symbol not recognized\n");
                exit(EXIT_FAILURE);
            }
        }
        temp -> label = temp -> element.simb;
        temp -> next = list;
        list = temp;

        lexemeBegin = ++currPosition;

    }else{
        while(isdigit(*currPosition)) currPosition++;
        char *lexeme = malloc(sizeof(char) * (currPosition - lexemeBegin));
        if(!lexeme){
            fprintf(stderr, "An error has ocurred while allocating memory for a lexeme\n");
            exit(EXIT_FAILURE);
        }

        *(lexeme + (currPosition - lexemeBegin)) = END;
        memcpy(lexeme, lexemeBegin, (currPosition - lexemeBegin));
#ifdef DEBUG
        printf("%s",lexeme);
#endif
        temp -> element.lexeme = lexeme;
        temp -> label = NUM;
        temp -> next = list;
        list = temp;

        lexemeBegin = currPosition;
    }

    return temp;
}


void deleteListToken(){
    token temp;

    if(isEmptyList()){
        return;
    }

    do{
        temp = list;
        free(temp);
        list = list -> next;
    }while(list != NULL);



    assert(list == NULL);
}


bool isEmptyList(){
    return list == NULL;
}
