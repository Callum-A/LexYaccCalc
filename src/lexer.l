%{
#include "y.tab.h"
#include <stdlib.h>
#include "node.h"
extern int yyerror(Node *root, char *s);
%}
%%
[0-9]+ {
    yylval.number = atoi(yytext); 
    return NUMBER;
}
[\t\n ] ;
"+" return(PLUS);
"-" return(MINUS);
"*" return(TIMES);
"/" return(DIVIDE);
"(" return(LEFT_PAREN);
")" return(RIGHT_PAREN);
";" return(END);
. { yyerror(NULL, "unexpected character."); }
%%
int yywrap(void) {
    return 1;
}